std::array 소개

이전 포스트들에서 고정 배열(fixed array)과 동적 배열(dynamic array)을 배웠다. 두 가지 배열 모두 C++에 내장되어 있지만, 포인터로 형 변환되었을 시 배열 길이 정보가 손실되고, 동적 배열은 지저분한 할당 해제 문제가 있다.이러한 문제를 해결하기 위해 C++ 표준라이브러리는 배열 관리를 쉽게 해주는 std::array 와 std::vector가 있다.

An introduction to std::array in C++11

C++ 11에서 소개된 std::array는 함수에 전달할 때 포인터로 형 변환되지 않는 고정 길이 배열이다. std:: array는 <array> 헤더의 std 네임 스페이스 내부에 정의되어 있다.std::array 변수 선언은 쉽다.

#include <array>

std::array<int, 3> myArray; // declare an integer array with length 3


고정 배열 선언처럼 array의 길이는 컴파일 타임에 설정해야 한다.std::array는 초기화 리스트(initializer list) 또는 유니폼 초기화(uniform initialization)를 사용해서 초기화할 수 있다.

std::array<int, 5> myArray = { 9, 7, 5, 3, 1 }; // initialization list
std::array<int, 5> myArray2 { 9, 7, 5, 3, 1 };  // uniform initialization


내장된 고정 배열과는 다르게, std::array의 배열 길이를 생략할 수 없다.

std::array<int, > myArray = { 9, 7, 5, 3, 1 }; // illegal, array length must be provided


또한, 초기화 리스트를 사용해서 배열에 값을 할당할 수도 있다.

std::array<int, 5> myArray;
myArray = { 0, 1, 2, 3, 4 }; // okay
myArray = { 9, 8, 7 }; // okay, elements 3 and 4 are set to zero!
myArray = { 0, 1, 2, 3, 4, 5 }; // not allowed, too many elements in initializer list!


일반 배열처럼 첨자 연산자([])를 사용해서 배열의 요소 값에 접근할 수 있다.

std::cout << myArray[1];
myArray[2] = 6;


또. 일반 배열처럼 첨자 연산자는 유효 범위 검사를 하지 않으므로 잘못된 index가 제공되면 나쁜 일이 발생한다.그러나 std::array는 유효 범위 검사를 수행하는 배열 요소에 접근하는 방법 at() 함수를 지원한다.

std::array<int, 5> myArray { 9, 7, 5, 3, 1 };
myArray.at(1) = 6;  // array element 1 valid, sets array element 1 to value 6
myArray.at(9) = 10; // array element 9 is invalid, will throw error


위 예제에서 array.at(1)을 호출하면 배열 요소 1이 유효한지 검사하고, 배열 요소 1에 대한 참조를 반환한다. 그러나 array.at(9)을 호출하면 배열 요소 9가 배열의 범위를 벗어났기 때문에 array.at(9)는 실패한다. 이때 참조를 반환하는 대신 예외를 throw한다.(std::out_of_range)at() 함수는 유효 범위 검사를 하므로 operator[]보다는 느리지만, 더 안전하다.



Size and sorting

size() 함수를 사용해서 배열의 길이를 알 수 있다.

std::array<double, 5> myArray { 9.0, 7.2, 5.4, 3.6, 1.8 };
std::cout << "length: " << myArray.size();
// length: 5


std::array는 함수에 전달될 때 포인터로 형 변환되지 않기 때문에 size() 함수는 함수 내에서 호출하더라도 정상적으로 작동한다.

#include <iostream>
#include <array>

void printLength(const std::array<double, 5>& myArray)
{
    std::cout << "length: " << myArray.size();
}

int main()
{
    std::array<double, 5> myArray { 9.0, 7.2, 5.4, 3.6, 1.8 };

    printLength(myArray);

    return 0;
}

// length: 5


표준 라이브러리에서는 "size"라는 용어는 배열 길이를 의미하므로 sizeof() 연산자의 결과와 혼동하면 안 된다. (sizeof() 결과: 배열 요소 자료형의 크기 * 배열 길이)위 예제에서 printLength() 함수에서 매개 변수로 std::array를 (const) 참조형(reference)으로 받는다는 것에 주목하자. 이는 std::array가 함수로 전달될 때 (성능상의 이유로) 컴파일러가 배열의 복사본을 만드는 것을 방지하기 위한 것이다.규칙: std::array는 항상 참조로 전달하자.std::array의 길이는 항상 알려져 있기 때문에 range-base for 루프와 함께 사용할 수 있다.

std::array<int, 5> myArray { 9, 7, 5, 3, 1 };

for (auto &element : myArray)
    std::cout << element << ' ';


<algorithm> 헤더에 있는 std::sort를 사용해서 std::array를 정렬할 수 있다.

#include <iostream>
#include <array>
#include <algorithm> // for std::sort

int main()
{
    std::array<int, 5> myArray { 7, 3, 1, 9, 5 };
    std::sort(myArray.begin(), myArray.end()); // sort the array forwards
//    std::sort(myArray.rbegin(), myArray.rend()); // sort the array backwards

    for (const auto &element : myArray)
        std::cout << element << ' ';

    return 0;
}

// 1 3 5 7 9


sort() 함수는 이터레이터(iterator)를 사용한다. 이터레이터는 아직 다루지 않은 개념이므로 이해하는 데 어려움이 있다. 이터레이터에 대한 설명은 이 포스트의 범위를 벗어나므로 다음에 할 예정이다.



정리

std::array 사용은 내장된 고정 배열을 대체하는 훌륭한 방법이다. 내장된 고정 배열보다 메모리를 더 사용하지 않으며 함수로 전달시 포인터로 형 변환되지 않는 장점이 있고, 단점은 선언할 때 배열 길이를 명시적으로 지정해야 한다는 것뿐이다.
출처: https://boycoding.tistory.com/213?category=1009770 [소년코딩:티스토리]
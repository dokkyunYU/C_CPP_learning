# 선언 방법

std::vector<int> v

C++ 에서 표준 템플릿 라이브러리인 STL(Standard Template Library)의 가장 기본적인 시퀀스 컨테이너인 vector에 대해서 설명하겠습니다.

기본적으로 배열과 비슷한 부분이 많이 있습니다.

#include<vector> 헤더파일을 포함시켜 주시고 사용하면 됩니다.

선언을 할때 vector<int> v와 같은 방식으로 선언을 하며 크기를 vector<int> v(10) 과 같이 임의 지정할 수도 있습니다.

vector에 저장할 수 있는 크기가 있으며 그것을 초과 할 경우 vector에 인자들을 복사하여 다른 메모리에 할당하면서 크기를 늘립니다.



1. 기본 선언과 인자 추가 , 탐색

```cpp
#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
 
int main() {
    //선언
    vector<int> v;

    //가장뒤에 인자추가
    v.push_back(5);        // [5]
    v.push_back(15);    // [5, 15]
    v.push_back(25);    // [5, 15, 25]
    v.push_back(1);        // [5, 15, 25, 1]
    
    //탐색
    for (unsigned int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    
    cout << "----------"<<endl;
                     
    //탐색2 iterator 이용하기
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}
```










2. size() 와 clear()
```cpp
int main() {
    vector<int> v;
    v.push_back(-11);        
    v.push_back(-22);
    v.push_back(33);
    
    //사이즈 측정 및 초기화 함수
    cout << v.size() << endl;    // 3 출력
    v.clear();                    // vector 내용 초기화
    cout << v.size() << endl;    // 0 출력
    return 0;
}
```




3. 중간에 인자 넣기( insert())
```cpp
int main() {
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('d');
    v.push_back('e');
 
    //b 다음에 c 삽입하기
    vector<char>::iterator iter;
    for (iter = v.begin(); iter != v.end(); ++iter) {
        if (*iter == 'b') {    //b찾기
            v.insert(iter+1, 'c');    //b다음에 c 삽입하기
            break;
        }
    }
 
    //결과 출력
    for (iter = v.begin(); iter != v.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
```





4. 인자 삭제하기
```cpp
int main() {
    vector<double> v;
    v.push_back(1.1);
    v.push_back(3.3);
    v.push_back(-1.3);
    v.push_back(11);
    v.push_back(-5);
 
    //음수 제거하기
    vector<double>::iterator iter;
    for (iter = v.begin(); iter != v.end(); ) {
        if (*iter < 0) {            // 음수 찾기
            iter = v.erase(iter);    // 인자 삭제, 삭제 후 다음 인자 반환
        } else {
            ++iter;
        }
    }
 
    //결과 출력
    for (iter = v.begin(); iter != v.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
```


std::vector 소개

이전 포스트에서 std::array를 소개했다. std::array는 C++의 내장 고정 배열(fixed array) 기능을 더 안전하고 유용한 형태로 제공한다.마찬가지로 C++ 표준 라이브러리에는 동적 배열(dynamic array) 작업을 더 안전하고 쉽게 해주는 std::vector를 제공한다.

An introduction to std::vector

C++ 03에서 소개된 std::vector는 자체 메모리 관리를 처리하는 동적 배열 기능을 제공한다. 즉, new와 delete를 사용하여 메모리를 동적으로 할당∙해제하지 않고도 런타임에 길이가 설정된 배열을 만들 수 있다∙ std :: vector는 <vector> 헤더에 정의되어 있다.std::vector 변수 선언은 쉽다.

#include <vector>

// no need to specify length at initialization
std::vector<int> array; 
std::vector<int> array2 = { 9, 7, 5, 3, 1 }; // use initializer list to initialize array
std::vector<int> array3 { 9, 7, 5, 3, 1 }; // use uniform initialization to initialize array (C++11 onward)


std::vector는 요청에 따라 해당 내용에 대해 동적으로 메모리를 할당하기 때문에 초기화에 상관없이 컴파일 타임에 배열 길이를 명시적으로 설정할 필요가 없다.std::array와 마찬가지로, 배열 요소에 대한 접근은 []연산자 또는 at() 함수를 통해 수행할 수 있다.

array[6] = 2;    // no bounds checking
array.at(7) = 3; // does bounds checking


위 예제에서 두 경우 모두 배열의 끝 부분에 있는 요소를 요청하면 벡터 크기가 자동으로 조정되지 않는다.C++ 11에서는 다음과 같이 초기화 리스트(initializer-list)를 사용해 std::vector에 값을 할당할 수 있다.

array = { 0, 1, 2, 3, 4 }; // okay, array length is now 5
array = { 9, 8, 7 }; // okay, array length is now 3


이 경우 std::vector는 제공된 요소 수와 일치하도록 크기가 자동으로 조정된다.



Self-cleanup prevents memory leaks

std::vector 변수가 범위(scope)를 벗어나면 자동으로 제어하는 메모리를 할당 해제한다. 이것은 편리할 뿐만 아니라 메모리 누수를 방지하는 데 유용하다.

void doSomething(bool earlyExit)
{
    int* array = new int[5] { 9, 7, 5, 3, 1 };

    if (earlyExit)
        return;

   // do stuff here

    delete[] array; // never called
}


earlyExit를 true로 설정하면 배열의 할당이 해제되지 않고 메모리가 누수 된다.그러나 array가 std::vector인 경우 array가 범위를 벗어나면 함수가 일찍 종료하는지에 관계없이 메모리는 할당 해제된다. 그러므로 std::vector는 직접 메모리 할당하는 것보다 훨씬 안전하게 사용할 수 있다.



Vectors remember their length

가리키는 배열의 길이를 모르는 내장 동적 배열과 다르게, std::vector는 길이를 추적한다. size() 함수를 통해 std::vector의 길이를 알 수 있다.

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> array { 9, 7, 5, 3, 1 };
    std::cout << "The length is: " << array.size() << '\n';

    return 0;
}
// 5




Resizing an array

std::vector의 크기는 resize() 함수 호출을 통해 조절할 수 있다.

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> array { 0, 1, 2 };
    array.resize(5); // set size to 5

    std::cout << "The length is: " << array.size() << '\n';

    for (auto const &element: array)
        std::cout << element << ' ';

    return 0;
}
// The length is: 5
// 0 1 2 0 0


주목해야 할 두 가지 사항이 있다. 첫째, 배열의 크기를 조정할 때 기존 값은 보존된다! 둘째, 새 요소는 자료형의 기본값 (정수의 경우 0)으로 초기화된다.std::vector의 크기를 더 작게 조정할 수도 있다.

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> array { 0, 1, 2, 3, 4 };
    array.resize(3); // set length to 3

    std::cout << "The length is: " << array.size() << '\n';

    for (auto const &element: array)
        std::cout << element << ' ';

    return 0;
}
// The length is: 3
// 0 1 2


std::vector의 크기를 조정하는 것은 계산 비용이 많이 들기 때문에 조정 횟수를 최소화하기 위해 노력해야 한다.
출처: https://boycoding.tistory.com/214 [소년코딩:티스토리]
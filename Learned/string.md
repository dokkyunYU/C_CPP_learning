# string 선언

```cpp
string str("abcdefg");
```
--> 선언하며 동시에 초기화


```cpp
string str1;

str1 = "abcdefg";
```
-->  string 선언 후 초기화

 

## C의 char과의 차이점
1. 문자열 긑에 null 이 들어가지 않는다.
2. 멤버함수가 많으므로 그때 그때 마다 필요한것을 가져다 쓰자.

 
  string str1 = "Arin";

  string str2 = "DSC";

 

  1) string 인자 접근하기.

   ---> str1.at(index);

      

          index 에는 숫자가 들어가게 되고 해당위치 에 해당하는 문자를 반환해준다.

          index 는 0부터 시작이다.

          만약에 index 가 해당 string 의 범위를 벗어 난다면 예외의 값을 반환한다.

    

  

   ---> str1.operator[index]

 

          c++ 의 string 에서는  배열처럼 대괄호를 이용하여 string 인자에 접근할수있다. 

          at 과 다른점은 string 의 index 범위를 검사하지 않기 때문에 at 보다 빠르게 동작한다.

          하지만 예외를 반환해주지 않는다. 시작은 0 부터이다.

 

    ---> str1.front()

 

          string 의 맨 앞 인자를 반환한다.

          

          strl.front();

           ---> A




    ---> str1.back();

 

          string의 맨 뒤 인자를 반환한다.

 

          str1.back();

            ---> n

 

  2) string size 관련 멤버함수

 

    ---> str1.size();

 

          string 의 사이즈를 반환해준다. c 에서의 strlen 이 생각난다.




    ---> str1.length();

 

          string 의 길이를 반환한다. size() 함수와 같다고 생각해주자     

 

    

    ---> str1.capacity();

 

          string 객체에 할당된 메모리 크기를 반환해준다.




    ---> str1.resize(n);

 

          string을 n의 크기로 만든다.

          만약 크기가 원래 사이즈 보다 작다면 남은 스트링을 버린다

          원래사이즈보다 크다면 빈공간으로 채운다.

 

    ---> str1.shrink_to_fit();

 

          낭비되고 있는 capacity 를 string 의 사이즈 에 맞게 줄여주는 멤버함수이다.   




    ---> str1.clear();

 

           string 에 들어있는 문자열을 지우는 함수이다. 이때 size와 length 는

           0 이되고 capacity 는 그대로 남게된다.

 

    ---> str1.empty();

          

          string 이 비어있는지 확인 하는 함수이다 .비어있다면 true 를 반환해준다.





  3) string 을 이용하여 여러 작업해보기

 

    ---> str1.c_str();

 

           C++ 스타일의 string 문자열을 C스타일의 문자열로 변경해주는 함수이다.                    




    ---> str1.substr();

 

          string index 에서부터 len만큼 잘라서 반환하는 함수이다. string 을 잘라서 반환해준다.

 

          type 은 unsigned int 이다 값으로는 -1 이 오게 되는데 이때 언더flow가 일어나서 가장큰 최대값이 반환된다. 즉 그대로 반환되게 되는것이다.

 

          예를 들어 str1.substr(); 이라 하면 "Arin" 이 나오게 되고,

                   str1.substr(1); 이라 하면 index 0 부터 세기 시작해서 1번째 인자부터 끝까지 문자열을 출력해준다. "rin" 이 나온다.

 

                   str1.substr(1,1); 이라하면 r 을 반환해준다. 1 번째 인자부터 1 의 길이만큼 문자열을 반환해준다.

    

    

    ---> str1.replace();

 

          함수를 호출하는 문자열의 index 위치에서 len 길이까지의 범위를 매개변수로 들어온str 전체로 대체 하는 함수이다.

 

          예를 들어 : str1.replace(2,2,str2); 라 하면

          "Arin" 의 2번째 인자부터 2개를 str2 로 대체한다.

          "ArDSCDSC"  같은 문자가 나오게된다.




    ---> str1.compare();

 

          매개변수로 들어온 str을 비교하여 같으면 0을 반환하고 다르면 0 이 아닌 값을 반환하는 함수이다.

 

          호출한 string 값이 매개변수로 들어온 string의 값보다 작다면(사전순으로 먼저 나올때) -1 을 반환한다.

          호출한 string 값이 매개변수로 들어온 string의 값보다 크다면 (사전순으로 느리다) 1 을 반환다.

 

          c에서의 strcmp의 반환값과 동일다 위치도 동일!




    ---> str1.copy();

 

          기본형은 size_t copy(char *arr size_t , size_t len , size_t index ) 이다

 

          첫번째 매개변수 : 호출한 문자열 첫번째 매개변수 문자열에 복사하는 함수이다. char* 인것을 보아

          C에서의 문자열 타입을 받는다.

 

          두번째 매개변수 : 복사할 문자열의 길이를 나타낸다.

 

          세번째 매개변수 : 복사를 시작할 위치이다.




              --->예시 설명

 

                  char arr[10] ; 이라는 빈 배열을 미리 만들어 놓는다.

 

                   int arrLen - str1.copy(arr,3,5); // 5번째 index 부터 3의 길이만큼 복사한다는 의미다.





    ---> str1.find();

 

          매개변수로 들어온 문자열과 호출한 문자열 중에 일치하는게 있는지 확인하는 함수이다.

          만약 일치하는 문자열이 있다면 일치하는 부분의 index를 반환해준다.

          

          첫번째 매개변수자리는 찾을 문자열

          두번째 매개변수 자리는 몇번째 인자부터 찾을것이다 라는 의미이다.




    --->  str1.push_back( s )

 

            함수를 호출하는 string 의 맨뒤에 문자 s 를 더하는 함수이다.

 

            str1.push_back('u'); "Arin" ---> "Arinu" 가 된다.

 

    ---> str1.pop_back();

 

            함수를 호출하는 string 의 맨뒤에 문자 s 를 제거해주는 함수이다. 





  4) string iterator 종류

 

    ---> str1.begin() ;

 

            문자열의 첫번째 문자를 가리키는 반복자 (iterator 포인터) 를 반환한다.




    --->  str1.end() ;

 

            문자열의 마지막의 바로 다음을 가리키는 반복자(iterator 포이턴) 를 반환한다.

    






  5) string 의 기타 멤버함수

 

    ---> swap(str1,str2);

 

            str1 과 str2 를 바꾸는 것이다.

 

    + operator str1+= str2 ; 이런식으로 쓴다 Arin     ---> ArinDSC 가 된다.         




    1. substr()으로 문자열 자르기
substr()은 문자열의 Index에서 원하는 길이의 문자열을 잘라서 string으로 리턴합니다.

substr의 Syntax는 아래와 같습니다. 인자로 index와 길이를 받고 string을 리턴합니다.

string substr (size_t pos = 0, size_t len = npos) const;
아래 예제는 문자열의 특정 부분을 자르는 코드입니다. substr(0, 5)는 Index 0에서 시작하는 5개의 문자를 잘라서 string으로 리턴합니다. substr(6, 5)는 Index 6에서 길이 5의 문자열을 잘라서 리턴합니다.

#include <iostream>
#include <string>

int main () {

    std::string str = "Hello World, C++";

    std::string newstr1 = str.substr(0, 5);
    std::string newstr2 = str.substr(6, 5);
    std::string newstr3 = str.substr(13, 3);

    std::cout << newstr1 << std::endl;
    std::cout << newstr2 << std::endl;
    std::cout << newstr3 << std::endl;

    return 0;
}
Output:

Hello
World
C++
substring(6)처럼 Index만 인자로 전달하고 길이는 전달하지 않으면 문자열의 마지막까지 자릅니다. 아래와 같이 substr(6)은 Index 6에서 문자열의 마지막까지 잘라서 string으로 리턴합니다. substr(13)은 Index 13에서 문자열 마지막까지 잘라서 리턴합니다.

#include <iostream>
#include <string>

int main () {

    std::string str="Hello World, C++";

    std::string newstr1 = str.substr(6);
    std::string newstr2 = str.substr(13);

    std::cout << newstr1 << std::endl;
    std::cout << newstr2 << std::endl;

    return 0;
}
Output:

World, C++
C++
2. substr()과 find()로 문자열 분리하기
find(separator, index)는 인자로 전달된 Index에서 separator를 찾고 그 Index를 리턴합니다. separator가 없으면 npos를 리턴합니다.

아래 예제는 find()와 substr()을 이용하여 ,를 기준으로 문자열을 분리하는 예제입니다. 문자열 "Hello,World,C++"는 아래 코드에서 Hello, World, C++으로 분리됩니다. 동작 원리는 while 안에서 문자열의 :를 찾고 substr()으로 : 직전까지 문자열을 자르는 것입니다.

#include<iostream>
#include<string>

int main() {

    std::string str = "Hello,World,C++";
    std::string separator = ",";
    int cur_position = 0;
    int position;

    while ((position = str.find(separator, cur_position)) != std::string::npos) {
        int len = position - cur_position;
        std::string result = str.substr(cur_position, len);
        std::cout << result << std::endl;
        cur_position = position + 1;
    }

    std::string result = str.substr(cur_position);
    std::cout << result << std::endl;
}
Output:

Hello
World
C++
3. getline()과 istringstream으로 문자열 분리하기
getline()과 istringstream을 이용하여 위와 같이 구분자로 문자열을 분리할 수 있습니다. 문자열을 istringstream으로 변환하고, getline()을 통해 구분자를 기준으로 문자열을 읽어올 수 있습니다.

#include<iostream>
#include<string>
#include<sstream>

int main() {

    std::string str = "Hello,World,C++";
    char separator = ',';
    std::istringstream iss(str);
    std::string str_buf;
    while (getline(iss, str_buf, separator)) {
    	  std::cout << str_buf << std::endl;
    }

    return 0;
}
Output:

Hello
World
C++
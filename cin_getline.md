C++
cin과 getline을 같이 사용할때 cin.ignore()이 필요한 이유 기록
namwhis 2019. 7. 9. 17:39
제대로 알지 못하면서 알고 있다고 생각하는것만큼 무서운것이 없습니다.

선무당이 사람 잡는다.
cin과 getline을 같이 사용할때 cin.ignore()이 필요한 이유를 잘못 알고 쓰고 있었습니다.

 

잘못된 이해

int같은 숫자형변수는 '\n'를 담지 못하기 때문에 '\n'를 버린다. (입력버퍼에 남아있다.)
getline에 '\n'가 전달되므로(입력버퍼에서 읽어옴으로) cin.ignore()를 이용해서 입력버퍼를 비워야한다.
#include <iostream>
using namespace std;
int main(void)
{
	int n;
	string s;

	cin >> n;
	cout << n << endl;
	cin.ignore();
	
	getline(cin,s);
	cout << s << endl;

	
	return 0;
}
대부분의 알고리즘 문제는 테스트케이스의 수(n)와 각 테스트케이스의 문자열(s)가 주어지는 방식이라 문제가 없었습니다만, cin, getline을 동시에 이용해서 문자열을 연속으로 받아야 하는 경우 위의 잘못된 이해로는 문제가 발생합니다.

#include <iostream>
using namespace std;
int main(void)
{
	string s1,s2;

	cin >> s1;
	cout << s1 << endl;

	getline(cin,s2);
	cout << s2 << endl;

	
	return 0;
}
입력한 s1만 출력되고 종료됩니다.

'숫자형이 아니고 문자열변수인데 왜 '\n'를 담지않고 버리지?'

 

제대로된 이해

cin은 '\n'를 변수에 담지 않는다. (입력버퍼에 남겨둔다.)
getline은 '\n'를 변수에 담는다.

cin은 '\n'를 처리하지 않고 입력버퍼에 남겨둔다.
geline은 '\n'를 입력버퍼에서 가져와서 처리한다. 
s2에  '\n'가 전달되며 '\n'를 제거 후  s2에 ''을 담기 때문에 s1과 ''이 출력되고 종료된다.
이렇게 해야 합니다.

#include <iostream>
using namespace std;
int main(void)
{
	string s1,s2;

	cin >> s1;
	cout << s1 << endl;
	
	cin.ignore();

	getline(cin,s2);
	cout << s2 << endl;

	
	return 0;
}
 

더 실험을 해봅니다.

#include <iostream>
using namespace std;
int main(void)
{
    string s;
    
    for(int i=0;i<3;i++)
    {
    	cin.ignore();
        getline(cin,s);
        cout << s << endl;
    }
	return 0;
}
입력한 문자열의 첫번째 문자가 삭제되어 출력됩니다.

(입력)
1234
1234
1234

(결과)
234
234
234
추가이해

cin.ignore();는 버퍼 전체를 비우는것이 아니라 맨 앞의 문자하나를 지운다.
getline(읽어올 입력스트림, 저장할 문자열변수)
 

몇번 실수를 해서 정리해놓습니다.
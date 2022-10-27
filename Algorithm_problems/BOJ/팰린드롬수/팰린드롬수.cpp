// 팰린드롬수
// https://www.acmicpc.net/problem/1259

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
  string ss;
  while (cin >> ss)
  {
    if ((char)ss[0] == '0')
      return 0;
    string pal = "yes";
    int ss_len = ss.length();
    for (int i = 0; i < ss_len; i++)
      if (ss[i] != ss[ss_len - i - 1])
        pal = "no";
    cout << pal << '\n';
  }
  return 0;
}
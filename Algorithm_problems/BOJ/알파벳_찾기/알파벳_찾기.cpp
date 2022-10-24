// 일파벳 찾기
// https://www.acmicpc.net/problem/10809

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
  string word;
  cin >> word;
  int alph[26] = {};
  for (int i = 0; i < 26; i++)
    alph[i] = -1;
  for (int i = 0; i < word.length(); i++)
    if (alph[word.at(i) - 'a'] == -1)
      alph[word.at(i) - 'a'] = i;
  for (int j : alph)
    cout << j << " ";
  return 0;
}
// 단어정렬
// https://www.acmicpc.net/problem/1181
// str.begin() str.end()

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool compare(string a, string b)
{
  int len_a = a.length(), len_b = b.length();
  if (len_a == len_b)
  {
    for (int i = 0; i < len_a; i++)
    {
      if ((char)a[i] == (char)b[i])
        continue;
      return (int)a[i] < (int)b[i];
    }
  }
  return len_a < len_b;
}

/*

bool compare(string a, string b)
{
  if(a.length() == b.length())
    return a < b;
  else
    return a.length() < b.length();
}

*/

int main(void)
{
  int n = 0;
  cin >> n;
  cin.ignore();
  string *str_arr = new string[n];
  string prev_str = "";
  for (int i = 0; i < n; i++)
    getline(cin, str_arr[i]);
  sort(str_arr, str_arr + n, compare);
  for (int i = 0; i < n; i++)
  {
    if (str_arr[i] != prev_str)
      cout << str_arr[i] << '\n';
    prev_str = str_arr[i];
  }
  return 0;
}
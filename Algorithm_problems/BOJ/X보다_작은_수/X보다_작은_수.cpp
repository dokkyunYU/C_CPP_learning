// X보다 작은 수
// https://www.acmicpc.net/problem/10871

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
  string A;
  stringstream AA;
  int n = 0, x = 0, num = 0;
  cin >> n >> x;
  cin.ignore();
  getline(cin, A);
  AA << A;
  while (AA >> num)
    if (num < x)
      cout << num << " ";
  return 0;
}
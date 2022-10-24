#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  string a, b;
  cin >> a >> b;
  cout << stoi(a) / stoi(b);
  return 0;
}
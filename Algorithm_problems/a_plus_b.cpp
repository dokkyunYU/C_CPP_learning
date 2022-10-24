#include <iostream>
using namespace std;
int main(void)
{
  int a = 0, b = 0;
  while (cin >> a >> b)
  {
    if (!a && !b)
      return 0;
    cout << a + b << "\n";
  }
  return 0;
}
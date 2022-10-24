// 직사각형에서_탈출
// https://www.acmicpc.net/problem/1085

#include <iostream>
using namespace std;
int main(void)
{
  int x, y, w, h;
  int distance = 0;
  cin >> x >> y >> w >> h;
  distance = min((x > w - x) ? w - x : x, (y > h - y) ? h - y : y);
  cout << distance;
  return 0;
}
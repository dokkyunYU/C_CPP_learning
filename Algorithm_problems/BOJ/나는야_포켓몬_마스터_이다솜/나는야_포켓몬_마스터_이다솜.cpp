// 나는야 포켓몬 마스터 이다솜
// https://www.acmicpc.net/problem/1620

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
  int n = 0, m = 0;
  cin >> n >> m;
  char ss[n][20], s[20];
  for (int i = 0; i < n; i++)
    scanf("%s", &ss[i]);
  for (int j = 0; j < m; j++)
  {
    scanf("%s", &s);
    printf("%c\n", s[0]);
    if (isdigit(s[0]))
      printf("%s\n", ss[atoi(s) - 1]);
    else
      for (int i = 0; i < n; i++)
        if (ss[i] == s)
        {
          printf("%d\n", i + 1);
          break;
        }
  }
  return 0;
}
// 체스판 다시 칠하기
// https://www.acmicpc.net/problem/1018

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  int N = 0, M = 0, min_cnt = 100;
  char BW[2] = {'B', 'W'};
  cin >> N >> M;
  cin.ignore();
  string *board = new string[N];
  for (int i = 0; i < N; i++)
    getline(cin, board[i]);
  for (int i = 0; i < N - 7; i++)
    for (int j = 0; j < M - 7; j++)
    {
      int cnt1 = 0, cnt2 = 0;
      for (int k = 0; k < 8; k++)
      {
        for (int t = 0; t < 8; t++)
        {
          if ((char)board[i + k][j + t] != BW[(k + t) % 2])
            cnt1++;
          if ((char)board[i + k][j + t] == BW[(k + t) % 2])
            cnt2++;
        }
      }
      if (cnt1 < min_cnt || cnt2 < min_cnt)
        min_cnt = (cnt1 > cnt2) ? cnt2 : cnt1;
    }
  cout << min_cnt;
  return 0;
}
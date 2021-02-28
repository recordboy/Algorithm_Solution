#include <iostream>
#include <algorithm>

using namespace std;

char chess[50][50];

void getChess(int N, int M) {
  char input;
  for(int i = 0;i<N;i++) {
    for(int j = 0; j < M; j++) {
      cin>>input;
      chess[i][j] = input;
    }
  }
}

void countChess_B(int N, int M, int& count_B) {
  count_B = 0;
  int row = 0;
  int col = 0;
  for(int i = N; i<N+8; i++)
  {
    row = i%2;
    for(int j = M; j<M+8; j++)
    {
      col = j%2;
      if(row==0)
      {
        if(col==0) { // 짝수 row, 짝수 col인 경우 -> 'B'
          if(chess[i][j]=='W') count_B++;}
        else // 짝수 row, 홀수 col인 경우 -> 'W'
          if(chess[i][j]=='B') count_B++;
      }
      else
      {
        if(col==0) { // 홀수 row, 짝수 col인 경우 -> 'W'
          if(chess[i][j]=='B') count_B++;}
        else // 홀수 row, 홀수 col인 경우 -> 'B'
          if(chess[i][j]=='W') count_B++;
      }
    }
  }
}

void countChess_W(int N, int M, int& count_W) {
  count_W = 0;
  int row = 0;
  int col = 0;
  for(int i = N; i<N+8; i++)
  {
    row = i%2;
    for(int j = M; j<M+8; j++)
    {
      col = j%2;
      if(row==0)
      {
        if(col==0) { // 짝수 row, 짝수 col인 경우 -> 'W'
          if(chess[i][j]=='B') count_W++;}
        else // 짝수 row, 홀수 col인 경우 -> 'B'
          if(chess[i][j]=='W') count_W++;
      }
      else
      {
        if(col==0) { // 홀수 row, 짝수 col인 경우 -> 'B'
          if(chess[i][j]=='W') count_W++;}
        else // 홀수 row, 홀수 col인 경우 -> 'W'
          if(chess[i][j]=='B') count_W++;
      }
    }
  }
}

int main(void) {
  int N = 0;
  int M = 0;
  int count_B = 0;
  int count_W = 0;
  int minimum = 100000;
  int temp = 0;
  cin >> N >> M;
  getChess(N, M);
  for(int i = 0; i<N-8+1; i++) {
    for(int j = 0; j<M-8+1; j++) {
      countChess_B(i, j, count_B);
      countChess_W(i, j, count_W);
      temp = min(count_B, count_W);
      if(temp < minimum) minimum = temp;
    }
  }
  cout<<minimum;
  return 0;
}
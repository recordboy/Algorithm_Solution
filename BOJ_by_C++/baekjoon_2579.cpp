#include <iostream>

using namespace std;

int N = 0;
int table[301] = {0, };
int score[301] = {0, };

void getTable() {
  for(int i = 1; i < N+1; i++) {
    cin >> table[i];
  }
}

int main(void) {
  cin >> N;
  getTable();
  score[1] = table[1];
  score[2] = score[1] + table[2];
  for(int i = 3; i < N+1; i++) 
    score[i] = max(score[i-3] + table[i-1], score[i-2]) + table[i];
    // N-2에서 2칸 점프하는 경우는 제약없이 가능하다.
    // N-1에서 1칸 점프하는 경우는 제약에 의해 N-1에서 반드시 이전에 2칸 점프했어야한다.
  cout << score[N];
}
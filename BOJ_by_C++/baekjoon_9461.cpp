#include <iostream>

using namespace std;

int main(void) {
  long long P[100] = {0};
  int N = 0;
  int T = 0;
  P[0] = 1, P[1] = 1, P[2] = 1, P[3] = 2, P[4] = 2; // 점화식 값 초기화
  for(int i = 5; i < 100; i++) {
    P[i] = P[i-1] + P[i-5]; // 점화식 값 대입
  }
  cin >> T;
  for(int i = 0; i < T; i++) {
    cin >> N;
    cout << P[N-1] << endl;
  }
  return 0;
}
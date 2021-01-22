#include <iostream>

using namespace std;

long long devide_conquer(int A, int B, int C) {
  if(B==1) {
    return 1LL*A % C;
  }
  if(B%2==0) { // 곱하는 횟수가 짝수인 경우
    return (1LL * (devide_conquer(A, B/2, C) % C) * ((devide_conquer(A, B/2, C) % C)) % C);
  }
  else { // 곱하는 횟수가 홀수인 경우
    return (1LL* (devide_conquer(A, B/2, C) % C) * (((devide_conquer(A, B/2, C) % C) * A) % C) % C);
  }
}

int main(void) {
  int A = 0;
  int B = 0;
  int C = 0;
  cin >> A >> B >> C;
  cout << devide_conquer(A, B, C) << endl;
  return 0;
}
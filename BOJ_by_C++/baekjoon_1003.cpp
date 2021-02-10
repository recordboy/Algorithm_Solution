#include <iostream>

using namespace std;

struct fibo{
  int cnt_zero;
  int cnt_one;
};

int main() {
  struct fibo f[41];
  f[0].cnt_one = 0;
  f[0].cnt_zero = 1;
  f[1].cnt_one = 1;
  f[1].cnt_zero = 0;
  for(int i = 2; i < 41; i++) { // fill fibonacci array
    f[i].cnt_one = f[i-1].cnt_one + f[i-2].cnt_one;
    f[i].cnt_zero = f[i-1].cnt_zero + f[i-2].cnt_zero;
  }
  int T = 0;
  int N = 0;
  cin >> T;
  for(int i = 0; i < T; i++) {
    cin >> N;
    cout << f[N].cnt_zero << " " << f[N].cnt_one << endl;
  }
  return 0;
}
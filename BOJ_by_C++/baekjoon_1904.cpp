#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N = 0;
  cin >> N;
  vector<int> tile(N+1, 0);
  tile[1] = 1, tile[2] = 2; // tile[0]은 사용하지 않는다.
  for(int i = 3; i < N+1; i++)
    tile[i] = (tile[i-1] + tile[i-2]) % 15746;
  cout<<tile[N];
  return 0;
}
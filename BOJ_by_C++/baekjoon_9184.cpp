#include <iostream>
#include <vector>

using namespace std;

vector <vector <vector <int>>> w(21, vector<vector<int>>(21, vector<int>(21, 0)));
// 3차원 배열 생성 및 0으로 초기화
// 앞의 2가지의 기저 조건이 존재하므로 a, b, c의 

int solve(int a, int b, int c) {

  if((a<=0)||(b<=0)||(c<=0)) {
    return 1;
  }
  if((a>20)||(b>20)||(c>20)) {
    return solve(20, 20, 20);
  }
  // 기저 조건을 먼저 판단한다.

  if(w[a][b][c] != 0)
    return w[a][b][c];
  // 메모이제이션이 되어있는 경우에 곧바로 return 해준다.

  if((a<b)&&(b<c)) { // 메모이제이션 이후에 값을 return 해주도록 한다.
    w[a][b][c] = (solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c));
    return w[a][b][c];
  }
  else {
    w[a][b][c] = (solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1));
    return w[a][b][c];
  }
}

int main(void) {
  int a, b, c;
  int ret = 0;
  cin >> a >> b >> c;
  while((a!=-1)||(b!=-1)||(c!=-1)) {
    ret = solve(a, b, c);
    printf("w(%d, %d, %d) = %d\n", a, b, c, ret);
    cin >> a >> b >> c;
  }
  return 0;
}
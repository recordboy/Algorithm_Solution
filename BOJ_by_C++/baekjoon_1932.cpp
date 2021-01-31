#include <iostream>

using namespace std;

int triangle[500][500];
int result[500][500];
int N = 0;

void getTriangle() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i+1; j++) {
      cin >> triangle[i][j];
    }
  }
}

int main(void) {
  int level = 0;
  int col = 0;
  int maximum = 0;
  cin >> N;
  getTriangle();
  while(level < N) {
    if(level==0) { // 맨 처음은 누적 값이 없기 때문에 값을 바로 할당
      result[0][0] = triangle[0][0];
      level++;
      continue;
    }
    for(col = 0; col < level+1; col++) {
      if(col==0) { // 각 level의 좌측 끝인 경우
        result[level][col] = result[level-1][col] + triangle[level][col];
      }
      else if(col==level) { // 각 level의 우측 끝인 경우
        result[level][col] = result[level-1][col-1] + triangle[level][col];
      }
      else {
        result[level][col] = max(result[level-1][col-1], result[level-1][col]) + triangle[level][col];
      }
    }
    level++; // 다음 level에 대해 수행
  }
  for(int i = 0; i < N; i++) {
    if(maximum < result[N-1][i])
      maximum = result[N-1][i];
  }
  cout<<maximum;
  return 0;
}
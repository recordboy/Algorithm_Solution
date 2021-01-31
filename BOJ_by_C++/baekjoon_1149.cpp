#include <iostream>

using namespace std;

int house[1000][3];
int cost[1000][3];
int N = 0;

void getColor() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> house[i][j];
    }
  }
}

int main(void) {
  int minimum = 0;
  cin >> N;
  getColor();
  cost[0][0] = house[0][0], cost[0][1] = house[0][1], cost[0][2] = house[0][2];
  for(int level = 1; level < N; level++) {
    for(int col = 0; col < 3; col++) {
      if(col == 0) // 해당 level의 color가 RED인 경우
        cost[level][col] = min(cost[level-1][1], cost[level-1][2]) + house[level][col];
      else if(col == 1) // 해당 level의 color가 RED인 경우
        cost[level][col] = min(cost[level-1][0], cost[level-1][2]) + house[level][col];
      else // 해당 level의 color가 RED인 경우
        cost[level][col] = min(cost[level-1][0], cost[level-1][1]) + house[level][col];
    }
  }
  minimum = min(min(cost[N-1][0], cost[N-1][1]), cost[N-1][2]);
  cout<<minimum;
  return 0;
}
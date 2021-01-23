#include <iostream>
#include <vector>

using namespace std;

void getCost(vector<int> &v, int size) {
  int temp = 0;
  for(int i = 0; i < size; i++) {
    cin >> temp;
    v.emplace_back(temp);
  }
}

void getDistance(vector<int> &v, int size) {
  int temp = 0;
  for(int i = 0; i < size; i++) {
    cin >> temp;
    v.emplace_back(temp);
  }
}

void findMinimum(vector<int> &c, vector<int> &d, int size, long long &ret) {
  int current_min_cost = c[0];
  int i = 0;
  if(size == 2) {
    ret = 1LL*c[0]*d[0];
    return;
  }
  while(i < size) {
    if(current_min_cost > c[i])
      current_min_cost = c[i];
    ret += 1LL*d[i]*current_min_cost;
    i += 1;
  }
}

int main(void) {
  int N = 0;
  long long total = 0;
  cin >> N; // 도시의 개수 입력
  vector<int> cost;
  vector<int> distance;
  getDistance(distance, N-1);
  getCost(cost, N);
  findMinimum(cost, distance, N, total);
  cout << total;
  return 0;
}
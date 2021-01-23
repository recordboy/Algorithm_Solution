#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void putTime(vector<int> &delayTime, int size) {
  int temp = 0;
  for(int i = 0; i < size; i++) {
    cin >> temp;
    delayTime.emplace_back(temp);
  }
}

int getSum(vector<int> &delayTime, int size) {
  int total = 0;
  for(int i = 0; i < size; i++) {
    total += (size - i)*delayTime[i];
  }
  return total;
}

int main() {
  int N = 0;
  cin >> N;
  vector<int> delayTime;
  putTime(delayTime, N);
  sort(delayTime.begin(), delayTime.end());
  cout << getSum(delayTime, N);
  return 0;
}
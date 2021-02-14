#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
  int N = 0;
  int input = 0;
  cin >> N;
  vector<int> nums;
  for(int i = 0; i < N; i++) {
    scanf("%d", &input);
    nums.emplace_back(input);
  }
  sort(nums.begin(), nums.end());
  for(int i = 0; i < N; i++) {
    printf("%d\n", nums[i]);
  }
  return 0;
}
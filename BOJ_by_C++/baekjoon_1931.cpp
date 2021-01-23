#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meeting {
  int start;
  int end;
} typedef meet;

bool compare(meet a, meet b) {
  if(a.end == b.end) {
    return a.start < b.start;
  }
  return a.end < b.end;
}

int main(void) {
  int N = 0;
  int index = 1;
  int last = 0;
  int cnt = 1;
  meet temp;
  cin >> N;
  vector<meet> m;
  for(int i = 0; i < N; i++) {
    cin >> temp.start >> temp.end;
    m.emplace_back(temp);
  }
  sort(m.begin(), m.end(), compare);
  last = m[0].end; // 초기화
  while(index < N) {
    if(m[index].start >= last) { // 다음 회의를 찾은 경우
      last = m[index].end;
      cnt++;
    }
    index++;
  }
  cout << cnt;
  return 0;
}
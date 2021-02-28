#include <iostream>
#include <vector>

using namespace std;

vector<int> sel = {0, 0, 0}; // 선택된 3개의 원소를 담을 vector
bool visited[100] = {0, };

void dfs(int level, vector<int> card, int& max, int limit, int nCard) {
  if(level==3) {
    int temp = 0;
    for(auto i = sel.begin() ; i != sel.end() ; i++)
      temp += (*i);
    if((temp<=limit)&&(temp>max))
      max = temp;
  }
  for(int i = 0; i < nCard; i++) {
    if(level==0) {
      sel[level] = card[i];
      visited[i] = true;
      dfs(level+1, card, max, limit, nCard);
      visited[i] = false;
    }
    else {
      if((!visited[i])&&(level<3)) { // 조합을 선택하는 문제이기 때문에
        sel[level] = card[i];
        visited[i] = true;
        dfs(level+1, card, max, limit, nCard);
        visited[i] = false;
      }
    }
  }
}

int main() {
  vector<int> name;
  
  int N = 0;
  int M = 0;
  int input = 0;
  int max = 0;

  cin >> N >> M;

  for(int i = 0;i<N;i++) {
    cin >> input;
    name.emplace_back(input);
  }
  dfs(0, name, max, M, N);
  cout<<max;
  return 0;
}


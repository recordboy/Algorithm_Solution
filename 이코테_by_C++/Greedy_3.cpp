#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n, m = 0;
  int mininum = 0;
  int result = 0;
  cin >> n >> m;
  vector<vector<int>> card(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> card[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    sorted(card[i].begin(), card[i].end());
    for(int j = 0; j < m; j++)
      cout << card[i][j] << ' ';
    cout << endl;
  }

  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int zero = 0;
int one = 0;
int m_one = 0;

void setPaper(vector<vector<int>> &v, int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      cin >> v[i][j];
    }
  }
}

int checkPaper(vector<vector<int>> &v, int size, int row, int col) {
  int standard = v[row][col]; // 첫번째 원소를 flag로 사용
  for(int i = row; i < row + size; i++) {
    for(int j = col; j < col + size; j++) {
      if(v[i][j]==standard)
        continue;
      else 
        return 2; // 전체가 동일하지 않을 경우의 return code
    }
  }
  return standard;
}

void getPaper(vector<vector<int>> &v, int size, int row, int col) {
  if(size == 1) {
    if(v[row][col]==(-1)) m_one++;
    else if(v[row][col]==0) zero++;
    else one++;
    return;
  }
  else {
    if(checkPaper(v, size, row, col)==1) one++;
    else if(checkPaper(v, size, row, col)==0) zero++;
    else if(checkPaper(v, size, row, col)==(-1)) m_one++;
    else {
      getPaper(v, size/3, row, col);
      getPaper(v, size/3, row, col+size/3);
      getPaper(v, size/3, row, col+size*2/3);
      getPaper(v, size/3, row+size/3, col);
      getPaper(v, size/3, row+size/3, col+size/3);
      getPaper(v, size/3, row+size/3, col+size*2/3);
      getPaper(v, size/3, row+size*2/3, col);
      getPaper(v, size/3, row+size*2/3, col+size/3);
      getPaper(v, size/3, row+size*2/3, col+size*2/3);
    }
  }
}

int main(void) {
  int N = 0;
  cin >> N;
  vector<vector<int>> paper(N, vector<int>(N, 2));
  setPaper(paper, N);
  getPaper(paper, N, 0, 0);
  cout << m_one << endl << zero << endl << one << endl;
  return 0;
}
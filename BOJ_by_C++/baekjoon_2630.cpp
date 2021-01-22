#include <iostream>
#include <vector>

using namespace std;

static int blue;
static int white;

void setPaper(vector<vector<int>> &v, int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      cin >> v[i][j];
    }
  }
}

void getTotal(vector<vector<int>> &v, int size, int row, int col) {
  
  bool cnt_blue = true;
  bool cnt_white = true;

  if(size==1) {
    if(v[row][col]==1) blue++;
    else white++;
    return;
  }

  if(v[row][col]==1) {
    for(int i = row; i < row + size; i++) {
      for(int j = col; j < col + size; j++) {
        if(v[i][j]==0) {
          cnt_blue = false;
          break;
        }
      }
    }
  }
  else {
    for(int i = row; i < row + size; i++) {
      for(int j = col; j < col + size; j++) {
        if(v[i][j]==1) {
          cnt_white = false;
          break;
        }
      }
    }
  }

  if((v[row][col]==0)&&cnt_white) 
    white++;
  else if((v[row][col]==1)&&cnt_blue) 
    blue++;
  else {
    getTotal(v, size/2, row, col);
    getTotal(v, size/2, row+(size/2), col);
    getTotal(v, size/2, row, col+(size/2));
    getTotal(v, size/2, row+(size/2), col+(size/2));
  }
}

int main(void) {
  int N = 0;
  cin >> N;
  vector<vector<int>> paper(N, vector<int>(N, 0));
  setPaper(paper, N);
  getTotal(paper, N, 0, 0);
  cout << white << endl << blue;
  return 0;
}
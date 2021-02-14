#include <iostream>

using namespace std;

int sudoku[9][9];
bool rowCheck[9][10]; // i번째 row에 j가 존재하면 true
bool colCheck[9][10]; // i번째 col에 j가 존재하면 true
bool squareCheck[9][10]; // i번째 square에 j가 존재하면 true

void getSudoku() {
  int input = 0;
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cin >> input;
      sudoku[i][j] = input;
      if(sudoku[i][j] != 0) {
        rowCheck[i][sudoku[i][j]] = true;
        colCheck[j][sudoku[i][j]] = true;
        squareCheck[(i/3)*3+j/3][sudoku[i][j]] = true;
      }
      else {
        rowCheck[i][sudoku[i][j]] = false;
        colCheck[j][sudoku[i][j]] = false;
        squareCheck[(i/3)*3+j/3][sudoku[i][j]] = false;
      }
    }
  }
}

bool promising(int row, int col, int input) {
  // row, col, square 중에서 하나라도 이미 input 값이 존재하면 non-promising
  if((rowCheck[row][input])||(colCheck[col][input])||(squareCheck[(row/3)*3+(col/3)][input]))
    return false;
  return true;
}

void showSudoku() {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cout<<sudoku[i][j]<<" ";
    }
    cout<<endl;
  }
}

void dfs(int level) {

  int row = level / 9;
  int col = level % 9;

  if(level == 81) {
    showSudoku();
    exit(0);
  }
  if(sudoku[row][col] == 0) { // (i, j)의 값이 0인 경우에만 백트래킹 실행한다.
    for(int input = 1; input < 10; input++) {
      if(promising(row, col, input)) {
        sudoku[row][col] = input;
        rowCheck[row][input] = true;
        colCheck[col][input] = true;
        squareCheck[(row/3)*3+(col/3)][input] = true;
        dfs(level+1);
        sudoku[row][col] = 0;
        rowCheck[row][input] = false;
        colCheck[col][input] = false;
        squareCheck[(row/3)*3+(col/3)][input] = false; // 백트래킹 수행
      }
    }
  }
  else
    dfs(level+1);
}

int main(void) {
  getSudoku();
  dfs(0);
  return 0;
}
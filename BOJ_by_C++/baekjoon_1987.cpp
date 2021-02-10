#include <iostream>
#include <vector>

using namespace std;

int R = 0;
int C = 0;
int maximum = -1;

void getBoard(vector<vector<char>> &board) {
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cin>>board[i][j];
    }
  }
}

bool promising(const int row, const int col, vector<vector<char>> &board, vector<bool> &visited) {
  if((row < 0)||(row > (R-1))||(col < 0)||(col > (C-1))) // vector array index를 벗어난 경우 -> return false
    return false;
  if(visited[board[row][col]-65]) // 경로에 vector array의 element를 이미 포함한 경우 -> return false
    return false;
  return true;
}

void dfs(int row, int col, vector<vector<char>> &board, vector<bool> &visited, int level) {
  if(level > maximum) { // 최대로 알파벳을 포함하는 경우를 maximum으로 갱신
    maximum = level;
  }
  int direction;
  if(level == 0) { // 처음 좌측 상단에서 시작하는 경우를 포함
    visited[board[row][col]-65] = true;
    dfs(row, col, board, visited, level+1);
  }
  for(direction = 0; direction < 4; direction++) { // 백트래킹 실행 구문
    if(direction == 0) { // 윗 방향으로 이동하는 경우
      if(promising(row - 1, col, board, visited)) {
        visited[board[row-1][col]-65] = true;
        dfs(row - 1, col, board, visited, level+1);
        visited[board[row-1][col]-65] = false;
      }
    }
    else if(direction == 1) { // 아랫 방향으로 이동하는 경우
      if(promising(row + 1, col, board, visited)) {
        visited[board[row+1][col]-65] = true;
        dfs(row + 1, col, board, visited, level+1);
        visited[board[row+1][col]-65] = false;
      }
    }
    else if(direction == 2) { // 왼쪽 방향으로 이동하는 경우
      if(promising(row, col - 1, board, visited)) {
        visited[board[row][col-1]-65] = true;
        dfs(row, col - 1, board, visited, level+1);
        visited[board[row][col-1]-65] = false;
      }
    }
    else if(direction == 3) { // 오른쪽 방향으로 이동하는 경우
      if(promising(row, col + 1, board, visited)) {
        visited[board[row][col+1]-65] = true;
        dfs(row, col + 1, board, visited, level+1);
        visited[board[row][col+1]-65] = false;
      }
    }
  }
}

int main(void) {
  int level = 0;
  cin >> R >> C;
  vector<vector<char>> board(R, vector(C , ' '));
  vector<bool> visited(26, false); // 26개의 알파벳 대문자를 표시할 vector 배열
  getBoard(board);
  dfs(0, 0, board, visited, 0);
  cout<<maximum;
  return 0;
}
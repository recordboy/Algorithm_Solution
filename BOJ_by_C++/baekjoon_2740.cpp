#include <iostream>
#include <vector>

using namespace std;

void getMatrix(vector<vector<int>> &v, int row, int col) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cin >> v[i][j];
    }
  }
}

void showMatrix(vector<vector<int>> &v, int row, int col) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int N, M, K;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M, 0)); // vector A
  getMatrix(A, N, M);
  cin >> M >> K;
  vector<vector<int>> B(M, vector<int>(K, 0)); // vector B
  getMatrix(B, M, K);
  vector<vector<int>> result(N, vector<int>(K, 0)); // vector result
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < K; j++) {
      for(int k = 0; k < M; k++) result[i][j] += A[i][k]*B[k][j];
    }
  }
  showMatrix(result, N, K);
  return 0;
}
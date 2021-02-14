#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int score[20][20];
int scoreStart = 0;
int scoreLink = 0;
int minimum = 100000;

void getScore(int N) {
  int input = 0;
  for(int i = 0; i<N; i++) {
    for(int j = 0; j<N; j++) {
      cin >> input;
      score[i][j] = input;
    }
  }
}

void calcScore(vector<int> &start, vector<int> &link, int nTeam) {
  scoreStart = 0;
  scoreLink = 0;
  for(int i = 0; i<nTeam; i++) {
    for(int j = 0; j<nTeam; j++) {
      if(i == j) continue;
      else {
        scoreStart = scoreStart + score[start[i]][start[j]];
        scoreLink = scoreLink + score[link[i]][link[j]];
      }
    }
  }
}

void dfs(int level, vector<int> &start, vector<int> &link, int nTeam) {
  int i = 0;
  if(level == nTeam) {
    vector<bool> visited(2*nTeam, 0);
    for(i = 0; i<nTeam; i++) {
      if(start[i] != -1) visited[start[i]] = true;
    }
    for(i = 0; i<nTeam; i++) {
      for(int j = 0; j<2*nTeam; j++) {
        if(!visited[j]) {
          visited[j] = true;
          link[i] = j;
          break;
        }
      }
    }
    calcScore(start, link, nTeam);
    minimum = min(minimum, abs(scoreStart-scoreLink));
  }
  if(level < nTeam) {
    if(level == 0) {
      for(i = 0; i<nTeam*2; i++) {
        start[level] = i;
        dfs(level+1, start, link, nTeam);
      }
    }
    else {
      for(i = 0; i<nTeam*2; i++) {
        if(start[level-1] < i) {
          start[level] = i;
          dfs(level+1, start, link, nTeam);
        }
      }
    }
  }
}

int main(void) {
  int N = 0;
  cin >> N;
  int nTeam = N/2;
  vector<int> vectorStart(N/2, -1); // 선택되지 않은 index는 -1
  vector<int> vectorLink(N/2, -1); // 선택되지 않은 index는 -1
  getScore(N); 
  dfs(0, vectorStart, vectorLink, nTeam);
  cout<<minimum;
  return 0;
}
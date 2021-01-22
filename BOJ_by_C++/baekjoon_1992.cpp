#include <iostream>
#include <vector>
#include <string>

using namespace std;

string zero = "0000000000000000000000000000000000000000000000000000000000000000";
string one = "1111111111111111111111111111111111111111111111111111111111111111";
bool isZero();

void setTree(vector<string> &v, int size) {
  string temp;
  for(int i = 0; i < size; i++) {
    cin >> temp;
    v[i] = temp;
  }
}

void getQuadtree(vector<string> &v, int size) {
  vector<string> v_zero_total(size, zero.substr(0, size));
  vector<string> v_one_total(size, one.substr(0, size));
  vector<string> v_zero(size/2, zero.substr(0, size/2));
  vector<string> v_one(size/2, one.substr(0, size/2));
  if (v == v_zero_total) cout << "0";
  else if (v == v_one_total) cout << "1";
  else {
    cout << "("; // 해당 노드에서의 시작 부분
    // 전체가 1또는 0으로 이루어져있는지 확인하기 위한 vector<string> 생성
    vector<string> v_sub1, v_sub2, v_sub3, v_sub4;
    int num = 0;
    while(num < 4) {
      switch(num) {
        case 0:
         for(int i = 0; i < size/2; i++) 
           v_sub1.emplace_back(v[i].substr(0, size/2));
         num++;
         break;
        case 1:
         for(int i = 0; i < size/2; i++) 
          v_sub2.emplace_back(v[i].substr(size/2, size/2));
          num++;
          break;
        case 2:
         for(int i = size/2; i < size; i++) 
          v_sub3.emplace_back(v[i].substr(0, size/2));
          num++;
          break;
        case 3:
         for(int i = size/2; i < size; i++) 
            v_sub4.emplace_back(v[i].substr(size/2, size));
          num++;
          break;
        default: 
          break;
     }
    }
    if (v_sub1 == v_one) cout << "1";
    else if (v_sub1 == v_zero) cout << "0";
    else getQuadtree(v_sub1, size/2);
    if (v_sub2 == v_one) cout << "1";
    else if (v_sub2 == v_zero) cout << "0";
    else getQuadtree(v_sub2, size/2);
    if (v_sub3 == v_one) cout << "1";
    else if (v_sub3 == v_zero) cout << "0";
    else getQuadtree(v_sub3, size/2);
    if (v_sub4 == v_one) cout << "1";
    else if (v_sub4 == v_zero) cout << "0";
    else getQuadtree(v_sub4, size/2);
    cout << ")"; // 해당 노드에서의 끝 부분
  }
}

int main(void) {
  int N = 0;
  cin >> N;
  vector<string> tree(N);
  setTree(tree, N);
  getQuadtree(tree, N);
  return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string input;
  int operand = 0;
  int total = 0;
  int operate = 1; // (+) : 1, (-) : -1

  cin >> input;

  // (-) 뒤의 모든 operand는 빼준다.
  for(char elem : input) {
    if(elem == '+') {
      total += operand;
      operand = 0;
    }
    else if(elem == '-') {
      total += operand;
      operate = -1;
      operand = 0;
    }
    else {
      operand = operand*10 + (int)(elem-48)*operate;
    }
  }

  total += operand;

  cout << total;

  return 0;
}
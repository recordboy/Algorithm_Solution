#include <iostream>

using namespace std;

int result[1000001] ={0, };

int main(void) {
  int N = 0;
  bool two, three = false;
  cin >> N;

  result[1] = 0, result[2] = 1, result[3] = 1; // 1, 2, 3에 대해 초기화
  for(int i = 4; i < N+1; i++) {
    if(i%2==0) two = true;
    if(i%3==0) three = true; // 2또는 3으로 나누어지는지 확인, 1로 빼는 것은 항상 가능하다.
    if(two&&three) // 2의 배수 && 3의 배수
      result[i] = min(min(result[i-1], result[i/2]), result[i/3]) + 1; 
    else if(two&&!three) // 2의 배수
      result[i] = min(result[i-1], result[i/2]) + 1;
    else if(!two&&three) // 3의 배수
      result[i] = min(result[i-1], result[i/3]) + 1;
    else // !(2의 배수 && 3의 배수)
      result[i] = result[i-1] + 1;
    two = false;
    three = false;
  }
  cout << result[N];
  return 0;
}
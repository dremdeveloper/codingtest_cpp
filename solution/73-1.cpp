#include <vector>

using namespace std;

// 피보나치 수열의 n번째 값을 계산하는 함수
int solution(int n) {
  vector<int> fib = {0, 1}; // fib(0) = 0, fib(1) = 1
  for (int i = 2; i <= n; ++i) {
    fib.push_back((fib[i - 1] + fib[i - 2]) % 1234567);
  }
  return fib[n];
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution(3) << endl; //출력값 : 2
  cout << solution(2) << endl; //출력값 : 5
  
  return 0;
}

#include <vector>
using namespace std; // using 지시문 추가

int solution(int n) {
  vector<int> fib = {0, 1}; // F(0) = 0, F(1) = 1
  for (int i = 2; i <= n; i++) {
    fib.push_back(fib[i - 1] + fib[i - 2]);
  }
  return fib[n] % 1234567;
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution(3) << endl; //출력값 : 2
  cout << solution(5) << endl; //출력값 : 5
  
  return 0;
}

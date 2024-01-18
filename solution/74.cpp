#include <vector>

using namespace std;

long long solution(int n) {
  // ❶ 바닥의 가로 길이가 1인 경우, 바닥을 채우는 방법의 수는 1
  if (n == 1) {
    return 1;
  }
  // ❷ 바닥의 가로 길이가 2인 경우, 바닥을 채우는 방법의 수는 2
  if (n == 2) {
    return 2;
  }
  // ❸ 동적 계획법을 위한 배열 초기화
  // dp[i]는 가로 길이가 i일 때 바닥을 채우는 방법의 수
  vector<long long> dp(n + 1, 0);
  dp[1] = 1;
  dp[2] = 2;
  // ❹ 가로 길이가 3부터 n까지의 각각의 경우에 대해 바닥을 채우는 방법의 수를 구함
  for (int i = 3; i <= n; i++) {
    // ❺ dp[i]는 dp[i-1]과 dp[i-2]를 더한 값
    dp[i] = (dp[i - 1] + dp[i - 2]) % 100Q0000007;
  }
  // ❻ 바닥의 가로 길이가 n일 때 바닥을 채우는 방법의 수인 dp[n]을 반환
  return dp[n];
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution(4) << endl; //출력값 : 5
  
  return 0;
}

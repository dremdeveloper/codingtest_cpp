#include <vector>
#include <algorithm>

using namespace std;

// 조약돌 배치 패턴에 대해 최대 가중치를 계산하는 함수
int solution(vector<vector<int>> arr) {
  // ❶ 입력 벡터의 열의 개수
  int n = arr[0].size(); 
  // ❷ dp 벡터 초기화
  vector<vector<int>> dp(4, vector<int>(n, 0)); 

  // ❸ 첫 번째 열의 가중치 초기화 (0: 상단, 1: 중앙, 2: 하단, 3: 상단과 하단)
  dp[0][0] = arr[0][0];
  dp[1][0] = arr[1][0];
  dp[2][0] = arr[2][0];
  dp[3][0] = arr[0][0] + arr[2][0];

  // ❹ 두 번째 열부터 마지막 열까지 가중치를 구함
  for (int i = 1; i < n; ++i) {
    // 패턴 0이 선택된 경우, 이전은 패턴 {1, 2} 가능
    dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[2][i - 1]);
    // 패턴 1이 선택된 경우, 이전은 패턴 {0, 2, 3} 가능
    dp[1][i] = arr[1][i] + max({dp[0][i - 1], dp[2][i - 1], dp[3][i - 1]});
    // 패턴 2가 선택된 경우, 이전은 패턴 {0, 1}이 가능
    dp[2][i] = arr[2][i] + max(dp[0][i - 1], dp[1][i - 1]);
    // 패턴 3이 선택된 경우, 이전은 패턴 {1}이 가능
    dp[3][i] = arr[0][i] + arr[2][i] + dp[1][i - 1];
  }

  // ❺ 마지막 열의 가중치 중, 최대 가중치를 반환합니다.
  return max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1], dp[3][n - 1]});
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution({{1, 3, 3, 2}, {2, 1, 4, 1}, {1, 5, 2, 3}}) << endl; //출력값 : 19
  cout << solution({{1, 7, 13, 2, 6}, {2, -4, 2, 5, 4}, {5, 3, 5, -3, 1}}) << endl; //출력값 : 32
  
  return 0;
}

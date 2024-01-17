#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 두 문자열의 LCS 길이를 계산하는 함수
int solution(string str1, string str2) {
  // ❶ 두 문자열의 길이를 저장
  int m = str1.length();
  int n = str2.length();

  // ❷ LCS를 저장할 테이블 초기화
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  // ❸ 동적 프로그래밍을 통해 LCS 길이 계산
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      // ❹ 현재 비교하는 문자가 같으면
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      // ❺ 현재 비교하는 문자가 같지 않으면
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // ❻ LCS 길이 반환
  return dp[m][n];
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution("ABCBDAB","BDCAB") << endl; //출력값: 4
  cout << solution("AGGTAB", "GXTXAYB") << endl; //출력값 :4
  return 0;
}

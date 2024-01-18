#include <vector>
#include <algorithm>

using namespace std;

// 최장 증가 부분 수열(LIS)의 길이를 계산하는 함수
int solution(const vector<int> nums) {
  int n = nums.size();
  // ❶ dp[i]는 nums[i]를 마지막으로 하는 LIS의 길이를 저장하는 배열입니다.
  vector<int> dp(n, 1);

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      // ❷ nums[i]와 nums[j]를 비교하여, nums[i]가 더 큰 경우에만 처리합니다.
      if (nums[i] > nums[j]) {
        // ❸ nums[i]를 이용하여 만든 부분 수열의 길이와
        // nums[j]를 이용하여 만든 부분 수열의 길이 + 1 중 최댓값을 저장합니다.
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  // ❹ dp 벡터에서 최댓값을 찾아 최장 증가 부분 수열의 길이를 반환합니다.
  return *max_element(dp.begin(), dp.end());
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution({1, 4, 2, 3, 1, 5, 7, 3}) << endl; //출력값 : 5
  cout << solution({3, 2, 1}) << endl; //출력값 : 1
  
  return 0;
}

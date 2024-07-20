//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 동적 계획법을 사용하여 최장 증가 부분 수열(LIS)을 계산하는 함수
int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); // 각 원소를 초기값 1로 초기화

    // LIS 계산
    for (int i = 1; i < n; ++i) { // arr[i]를 마지막 원소로 하는 LIS 계산
        for (int j = 0; j < i; ++j) { // arr[j] (0 <= j < i)를 마지막 원소로 하는 LIS 고려
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) { // arr[i]가 arr[j]보다 크고 dp[i]가 dp[j] + 1보다 작으면
                dp[i] = dp[j] + 1; // dp[i] 갱신
            }
        }
    }

    // dp 배열 중 최댓값이 LIS 길이
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80}; // 예시 배열
    cout << "LIS 길이: " << lis(arr) << endl;

    return 0;
}

/*
동적 계획법(DP)와 최장 증가 부분 수열(LIS) 계산:

1. 최장 증가 부분 수열(LIS) 개념:
   - LIS는 주어진 수열에서 각 원소들이 증가하는 형태의 가장 긴 부분 수열을 의미.
   - 예: 수열 [10, 22, 9, 33, 21, 50, 41, 60, 80]에서 LIS는 [10, 22, 33, 50, 60, 80]으로 길이는 6.
   - 부분 수열은 원본 수열의 원소 순서를 유지해야 함.

2. 동적 계획법(DP) 기본 원리:
   - 큰 문제를 작은 부분 문제로 분할하여 해결.
   - 동일한 부분 문제의 반복 계산을 피하기 위해 결과를 저장(memoization).
   - 시간 복잡도를 줄이고 효율성을 높이는 기법.

3. 중복 부분 문제(Overlapping Subproblems):
   - 동일한 작은 문제들이 여러 번 반복하여 계산되는 문제.
   - LIS의 경우, 특정 위치까지의 LIS 길이를 여러 번 계산하게 됨.
   - 동적 계획법은 이러한 중복 계산을 피하여 효율성을 높임.

4. 최적 부분 구조(Optimal Substructure):
   - 문제의 최적 해결 방법이 부분 문제의 최적 해결 방법으로 구성되는 성질.
   - LIS의 경우, arr[i]까지의 최적해는 arr[j] (j < i)까지의 최적해를 이용하여 구성됨.
   - 예: arr[i]를 포함한 LIS는 arr[j] (arr[j] < arr[i])까지의 LIS에 arr[i]를 추가한 것.

5. LIS 계산의 기본 원리:
   - dp[i]는 arr[i]를 마지막 원소로 가지는 LIS의 길이를 저장.
   - 초기값으로 모든 dp[i]를 1로 설정 (각 원소 자체가 길이 1의 LIS이므로).

6. LIS 계산에 동적 계획법 적용:
   - 이중 반복문을 사용하여 dp 배열을 갱신.
     - 외부 반복문(i): arr[i]를 마지막 원소로 하는 LIS를 계산.
     - 내부 반복문(j): arr[j]를 마지막 원소로 하는 LIS를 고려.
   - dp[i] 갱신 조건:
     - arr[i] > arr[j]인 경우: arr[i]가 arr[j] 뒤에 올 수 있는 경우.
     - dp[i] < dp[j] + 1인 경우: arr[j]를 포함하는 LIS에 arr[i]를 추가하여 더 긴 LIS를 만들 수 있는 경우.
   - dp[i] = dp[j] + 1로 갱신: 더 긴 LIS를 만들 수 있는 경우 dp[i] 갱신.

7. LIS 계산의 시간 복잡도:
   - 이중 반복문을 사용하므로 O(n^2) 시간 복잡도.
   - dp 배열을 사용하여 중복 계산을 피하고 효율적으로 계산.

결론:
   - LIS 문제는 DP의 이점(시간 복잡도 감소)을 크게 활용할 수 있음.
   - 중복 부분 문제와 최적 부분 구조를 가지므로 DP를 적용하면 효율성 개선이 큼.
*/

#include <iostream>
#include <vector>

// 문제의 정의:
// N개의 계단이 존재하고, 한 번에 1개 또는 2개의 계단을 오를 수 있을 때, 
// 계단을 오르는 방법의 총 수를 구하는 문제입니다.

// 최적 부분 구조:
// 현재 계단에 도달하는 방법은 이전 계단에서 한 계단 오르거나, 
// 두 계단 아래에서 두 계단 오르는 두 가지 방법으로 나뉩니다.
// 즉, f(n) = f(n-1) + f(n-2)의 형태로 나타낼 수 있습니다.

// 중복 부분 문제:
// 동일한 부분 문제(예: f(n-1), f(n-2))가 여러 번 반복되어 계산됩니다.
// 동적 계획법을 사용하면 이러한 중복 계산을 피할 수 있습니다.

int countWays(int n);

int main() {
    int n;
    std::cout << "계단의 수를 입력하세요: ";
    std::cin >> n;

    int result = countWays(n);
    std::cout << "계단을 오르는 방법의 총 수: " << result << std::endl;

    return 0;
}

// 계단을 오르는 방법의 총 수를 계산하는 함수
int countWays(int n) {
    // 동적 계획법을 위한 배열 선언
    std::vector<int> dp(n + 1);

    // 초기값 설정
    dp[1] = 1; // 계단 1개를 오르는 방법은 1가지
    dp[2] = 2; // 계단 2개를 오르는 방법은 2가지 (1+1 또는 2)

    // 동적 계획법을 이용한 계산
    // 점화식: dp[i] = dp[i - 1] + dp[i - 2]
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

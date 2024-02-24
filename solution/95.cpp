#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp; // DP 테이블
int maxAlp = 0, maxCop = 0; // 필요한 최대 알고력과 코딩력

// 현재 알고력(a)와 코딩력(b)에서 필요한 최소 학습 시간을 구하는 함수
int solve(int a, int b, vector<vector<int>> &problems) {
    // 기저 사례: 현재 알고력과 코딩력이 목표를 달성한 경우
    if (a >= maxAlp && b >= maxCop) {
        return 0;
    }
    int &ret = dp[a][b]; // 메모이제이션
    if (ret != -1) return ret; // 이미 계산된 경우

    ret = 1e9; // 최소 값을 찾기 위해 큰 값으로 초기화
    // 모든 문제를 순회하며 풀 수 있는 문제를 찾아 시도
    for (int i = 0; i < problems.size(); i++) {
        if (a >= problems[i][0] && b >= problems[i][1]) { // 문제를 풀 수 있는 경우
            int nextA = min(maxAlp, a + problems[i][2]); // 다음 알고력
            int nextB = min(maxCop, b + problems[i][3]); // 다음 코딩력
            ret = min(ret, solve(nextA, nextB, problems) + problems[i][4]); // 문제를 풀어 알고력과 코딩력을 향상시키는 경우
        }
    }
    // 알고력 또는 코딩력을 1씩 올리는 경우 중 최소값 찾기
    ret = min(ret, min(solve(min(maxAlp, a + 1), b, problems) + 1,
                       solve(a, min(maxCop, b + 1), problems) + 1));
    return ret;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    // 필요한 최대 알고력과 코딩력을 구함
    for (int i = 0; i < problems.size(); i++) {
        maxAlp = max(maxAlp, problems[i][0]);
        maxCop = max(maxCop, problems[i][1]);
    }
    dp.resize(151, vector<int>(151, -1)); // DP 테이블 초기화
    answer = solve(alp, cop, problems); // 최소 학습 시간 계산
    return answer;
}

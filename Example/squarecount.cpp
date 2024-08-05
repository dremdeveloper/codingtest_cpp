#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int ROW = 3;
const int COL = 4;

// 문제의 정의:
// ROW x COL 크기의 사각형에서 만들 수 있는 모든 정사각형의 개수를 구하는 문제입니다.

// 최적 부분 구조:
// 현재 셀에서 만들 수 있는 정사각형의 크기는 
// 위쪽, 왼쪽, 왼쪽 위 대각선 셀에서 만들 수 있는 정사각형 크기의 최솟값에 1을 더한 값입니다.

// 중복 부분 문제:
// 동일한 부분 문제(예: 위쪽, 왼쪽, 왼쪽 위 대각선 셀)가 여러 번 계산됩니다.

// 점화식:
// dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1

int countSquares();

int main() {
    int result = countSquares();
    cout << "만들 수 있는 정사각형의 총 개수: " << result << endl;
    return 0;
}

// ROW x COL 크기의 사각형에서 만들 수 있는 모든 정사각형의 개수를 계산하는 함수
int countSquares() {
    vector<vector<int>> dp(ROW, vector<int>(COL, 1)); // 모든 값을 1로 초기화

    // 동적 계획법을 이용한 계산
    for (int i = 1; i < ROW; ++i) {
        for (int j = 1; j < COL; ++j) {
            // dp[i][j]는 현재 셀에서 만들 수 있는 가장 큰 정사각형의 크기를 나타냄
            dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
    }

    int totalSquares = 0;
    // 모든 dp 값 합산
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            totalSquares += dp[i][j];
        }
    }

    return totalSquares;
}

/*
예제 출력:
20

예제 설명:
3x4 행렬에서 만들 수 있는 정사각형의 개수는 다음과 같습니다:
- 1x1 크기의 정사각형: 12개
- 2x2 크기의 정사각형: 6개
- 3x3 크기의 정사각형: 2개
총 합계: 12 + 6 + 2 = 20개
*/

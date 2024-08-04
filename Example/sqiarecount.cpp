#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 문제의 정의:
// n x n 크기의 사각형에서 만들 수 있는 모든 정사각형의 개수를 구하는 문제입니다.

// 최적 부분 구조:
// 현재 셀에서 만들 수 있는 정사각형의 크기는 
// 위쪽, 왼쪽, 왼쪽 위 대각선 셀에서 만들 수 있는 정사각형 크기의 최솟값에 1을 더한 값입니다.

// 중복 부분 문제:
// 동일한 부분 문제(예: 위쪽, 왼쪽, 왼쪽 위 대각선 셀)가 여러 번 계산됩니다.

// 점화식:
// dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1

int countSquares(vector<vector<int>>& matrix);

int main() {
    int n;
    cout << "사각형의 크기를 입력하세요: ";
    cin >> n;

    // n x n 크기의 행렬 초기화 (1로 초기화하여 모든 셀이 정사각형이 될 수 있도록)
    vector<vector<int>> matrix(n, vector<int>(n, 1));

    int result = countSquares(matrix);
    cout << "만들 수 있는 정사각형의 총 개수: " << result << endl;

    return 0;
}

// n x n 크기의 사각형에서 만들 수 있는 모든 정사각형의 개수를 계산하는 함수
int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int totalSquares = 0;

    // 초기값 설정
    for (int i = 0; i < n; ++i) {
        dp[i][0] = matrix[i][0];
        dp[0][i] = matrix[0][i];
        totalSquares += dp[i][0] + dp[0][i];
    }
    totalSquares -= dp[0][0]; // 중복된 [0][0] 값을 빼줍니다.

    // 동적 계획법을 이용한 계산
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 1) {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                totalSquares += dp[i][j];
            }
        }
    }

    return totalSquares;
}

/*
예제 입력:
3

예제 출력:
14

예제 설명:
3x3 행렬에서 만들 수 있는 정사각형의 개수는 다음과 같습니다:
- 1x1 크기의 정사각형: 9개
- 2x2 크기의 정사각형: 4개
- 3x3 크기의 정사각형: 1개
총 합계: 9 + 4 + 1 = 14개
*/

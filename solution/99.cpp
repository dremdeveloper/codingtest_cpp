#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 보드 게임의 최종 상태에서 파괴되지 않은 건물의 수를 계산하는 함수
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size(); // 보드의 세로 크기
    int m = board[0].size(); // 보드의 가로 크기
    vector<vector<int>> diff(n, vector<int>(m, 0)); // 보드의 각 위치에 대한 누적 영향력 차이를 저장할 2차원 벡터

    // 스킬을 적용하여 diff 배열에 누적 영향력 차이를 계산
    for(auto& s : skill) {
        int type = s[0], r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4], degree = (type == 1) ? -s[5] : s[5];
        diff[r1][c1] += degree;
        if(c2 + 1 < m) diff[r1][c2 + 1] -= degree;
        if(r2 + 1 < n) diff[r2 + 1][c1] -= degree;
        if(r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += degree;
    }

    // diff 배열을 이용하여 각 행의 누적 영향력을 계산
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            diff[i][j] += diff[i][j - 1];
        }
    }

    // diff 배열을 이용하여 각 열의 누적 영향력을 계산
    for(int j = 0; j < m; ++j) {
        for(int i = 1; i < n; ++i) {
            diff[i][j] += diff[i - 1][j];
        }
    }

    // 최종 상태의 보드를 계산하며 파괴되지 않은 건물의 수를 세기
    int answer = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] + diff[i][j] > 0) ++answer; // 파괴되지 않은 경우
        }
    }

    return answer;
}

//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
/*
N-Queen 문제 알고리즘:
- 시간 복잡도: O(N!) (이론적으로는 최대)
- 용도: N x N 체스판에 N개의 퀸을 배치하는 방법을 찾는 데 사용됩니다.
- 동작 과정:
  1. 현재 행에서 각 열에 퀸을 배치하며 가능한지 체크합니다.
  2. 배치가 가능하면 다음 행으로 이동합니다.
  3. 배치가 불가능하면 이전 행으로 돌아갑니다(백트래킹).

도식화 예 (N=4인 경우의 한 가지 해):
  | Q | - | - | - |
  | - | - | Q | - |
  | - | - | - | Q |
  | - | Q | - | - |
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n) {
    // 열 확인
    for (int row = 0; row < i; row++)
        if (board[row][j] == 1)
            return false;

    // 왼쪽 대각선 확인
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x--; y--;
    }

    // 오른쪽 대각선 확인
    x = i;
    y = j;
    while (x >= 0 && y < n) {
        if (board[x][y] == 1)
            return false;
        x--; y++;
    }

    // 배치 가능
    return true;
}

void solveNQueen(int board[][10], int i, int n) {
    // 기저 조건
    if (i == n) {
        // N개의 퀸을 모두 배치함: 현재 배치를 출력
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {
                    cout << "Q ";
                } else {
                    cout << "- ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // 현재 행에서 각 열을 시도
    for (int j = 0; j < n; j++) {
        if (isSafe(board, i, j, n)) {
            board[i][j] = 1; // 퀸 배치
            solveNQueen(board, i + 1, n); // 다음 행으로 이동
            board[i][j] = 0; // 백트래킹: 배치 취소
        }
    }
}

int main() {
    int n = 4;
    int board[10][10] = {0}; // 체스판 초기화

    solveNQueen(board, 0, n); // 첫 번째 행부터 시작
    return 0;
}

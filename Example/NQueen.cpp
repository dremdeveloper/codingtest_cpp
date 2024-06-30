#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// N Queen 문제: n x n 체스판에 n개의 퀸을 서로 공격하지 못하게 배치하는 문제
const int N = 4; // 퀸의 개수
vector<int> board(N, -1); // 보드 배열, 인덱스는 행을, 값은 열을 나타냄

// 보드의 현재 상태를 출력하는 함수
void printBoard() {
    // 각 행을 반복
    for (int i = 0; i < N; ++i) {
        // 각 열을 반복
        for (int j = 0; j < N; ++j) {
            // 현재 위치에 퀸이 있는지 확인
            if (board[i] == j) {
                cout << "Q "; // 퀸이 있으면 "Q" 출력
            } else {
                cout << ". "; // 퀸이 없으면 "." 출력
            }
        }
        cout << endl; // 한 행이 끝나면 줄바꿈
    }
    cout << endl; // 보드 전체 출력 후 줄바꿈
}

// 현재 위치에 퀸을 놓아도 되는지 확인하는 유망함수
bool isSafe(int row, int col) {
    // 현재 행 이전의 모든 행을 검사
    for (int i = 0; i < row; ++i) {
        // 1. 같은 열에 퀸이 있는지 확인
        if (board[i] == col) {
            return false; // 같은 열에 퀸이 있으면 false 반환
        }
        // 2. 같은 대각선에 퀸이 있는지 확인
        if (abs(board[i] - col) == abs(i - row)) {
            return false; // 같은 대각선에 퀸이 있으면 false 반환
        }
    }
    return true; // 어떤 충돌도 없으면 true 반환
}

// N Queen 문제를 해결하기 위한 재귀 함수
void solveNQueens(int row, int &solutions) {
    // 모든 행에 퀸을 배치한 경우 (기저 조건)
    if (row == N) {
        // 해결책을 찾았으므로 해결책 수 증가
        solutions++;
        // 현재 보드 상태를 출력
        printBoard();
        return; // 함수 종료
    }

    // 현재 행의 모든 열에 대해 반복
    for (int col = 0; col < N; ++col) {
        // 현재 위치에 퀸을 놓을 수 있는지 확인
        if (isSafe(row, col)) {
            board[row] = col; // 현재 행의 열에 퀸을 놓음
            solveNQueens(row + 1, solutions); // 다음 행에 대해 재귀 호출
            // 퀸을 제거할 필요 없음, 다음 반복에서 덮어쓰기 때문에
        }
    }
}

int main() {
    int solutions = 0; // 해결책 수를 저장할 변수

    solveNQueens(0, solutions); // 첫 번째 행부터 시작

    cout << "총 해결책 수: " << solutions << endl; // 총 해결책 수 출력

    return 0;
}

/*

. Q . . 
. . . Q 
Q . . . 
. . Q . 

. . Q . 
Q . . . 
. . . Q 
. Q . . 

총 해결책 수: 2
*/

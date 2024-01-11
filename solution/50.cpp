#include <vector>
#include <algorithm>

using namespace std;

//❶ 현재 행에 이미 다른 퀸이 있는지 확인하는 함수
bool isSameRow(int placedRow, int currentRow) {
  return placedRow == currentRow;
}

//❷ 대각선에 다른 퀸이 있는지 확인하는 함수
bool isDiagonalAttack(int placedCol, int placedRow, int currentCol, int currentRow) {
  return abs(placedCol - currentCol) == abs(placedRow - currentRow);
}

//❸ 퀸을 안전하게 배치할 수 있는지 확인하는 함수
bool isSafePosition(const vector<int> &queen, int col, int row) {
  for (int i = 0; i < col; ++i) {
    if (isSameRow(queen[i], row) || isDiagonalAttack(i, queen[i], col, row)) {
      return false;
    }
  }
  return true;
}

//❹ 퀸을 배치하는 함수
long long placeQueens(vector<int> &queen, int col) {
  int n = queen.size();
  if (col == n) {
    return 1;
  }

  long long count = 0;
  for (int row = 0; row < n; ++row) {
    //❺ 퀸을 놓을수 있는 위치인 경우 퀸을 놓음
    if (isSafePosition(queen, col, row)) {
      queen[col] = row;
      count += placeQueens(queen, col + 1);
      queen[col] = -1;
    }
  }
  return count;
}

long long solution(int n) {
  vector<int> queen(n, -1);

  //❻ 퀸을 놓을수 있는 경우의 수를 반환
  return placeQueens(queen, 0);
}





//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution(4) << endl; // 출력값 : 2
  return 0;
}

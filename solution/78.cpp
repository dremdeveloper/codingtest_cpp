#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board) {
  //❶ 주어진 2차원 보드의 행과 열의 개수를 변수에 저장합니다.
  int ROW = board.size(), COL = board[0].size();

  //❷ 각 행과 열을 순회하며 가장 큰 정사각형의 길이 확인
  for (int i = 1; i < ROW; ++i) {
    for (int j = 1; j < COL; ++j) {
      //❸ 현재 위치의 값이 1인 경우
      if (board[i][j] == 1) {
        //❹ 현재 위치에서 위, 왼쪽, 대각선 왼쪽 위의 값을 구함
        int up = board[i - 1][j];
        int left = board[i][j - 1];
        int up_left = board[i - 1][j - 1];

        //❺ 현재 위치의 값을 이전 위치들의 값들 중 가장 작은 값에 1을 더한 값으로 업데이트
        board[i][j] = min(min(up, left), up_left) + 1;
      }
    }
  }

  //❻ 보드에서 가장 큰 값(최대 정사각형의 한 변의 길이) 확인
  int max_val = 0;
  for (const auto& row : board) {
    max_val = max(max_val, *max_element(row.begin(), row.end()));
  }
  //❼ 최대 정사각형 넓이 반환
  return max_val * max_val;
}




//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution({{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}}) << endl; //출력값 : 9
  cout << solution({{0, 0, 1, 1}, {1, 1, 1, 1}}) << endl; //출력값 : 4  
  return 0;
}

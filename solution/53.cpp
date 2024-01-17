#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
int n, m;

 //❶ 현재 위치가 게임판을 벗어나는지 확인
bool isOutOfBounds(int r, int c) {
  return r < 0 || r >= n || c < 0 || c >= m;
}
int playGame(vector<vector<int>>& board, int curR, int curC, int opR, int opC) {
  //❷ 현재 위치가 0인 경우는 불가능하므로 스텝을 0으로 반환  
  if (board[curR][curC] == 0) return 0;
  int bestSteps = 0;
    
  //❸ 현재 위치를 기준으로 가능한 방향 모두 확인  
  for (int dir = 0; dir < 4; ++dir) {
    int nextR = curR + dx[dir];
    int nextC = curC + dy[dir];
    //❹ 다음 위치가 범위를 멋어난 경우는 탐색에서 제외
    if (isOutOfBounds(nextR, nextC) || board[nextR][nextC] == 0) continue;
    //❺ 현재 위치로 이동해보고 다음 턴 진행
    board[curR][curC] = 0;
    int steps = playGame(board, opR, opC, nextR, nextC) + 1;
    board[curR][curC] = 1;
      
    //❻ 현재까지 구한 최대 이동횟수와, 현재 이동횟수를 가지고 최선을 다하는 경우의 이동횟수를 구함
    if (bestSteps % 2 == 0 && steps % 2 == 1) bestSteps = steps;
    else if (bestSteps % 2 == 0 && steps % 2 == 0) bestSteps = max(bestSteps, steps);
    else if (bestSteps % 2 == 1 && steps % 2 == 1) bestSteps = min(bestSteps, steps);
  }
  return bestSteps;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
  n = board.size();
  m = board[0].size();
    
  //❼  최선을 다한경우 이동횟수를 반환  
  return playGame(board, aloc[0], aloc[1], bloc[0], bloc[1]);
}

//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
  cout <<solution( {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, {1, 0}, {1, 2}) << endl;//출력값 : 5
  cout <<solution( {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {1, 0}, {1, 2}) << endl;//출력값 : 4
  
  return 0;
}

#include <string>
#include <vector>
#include <queue>

using namespace std;

// 현재 좌표와, 해당 좌표까지 이동횟수
struct Point {
  int y, x, cnt;
};

// 상하좌우로 이동하기 위한 오프셋
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m;

// 현재 좌표가 유효한 좌표인이 확인
bool isWithinRange(int y, int x) {
  return 0 <= y && y < n && 0 <= x && x < m;
}

// 시작 좌표를 확인
Point findStartPoint(char start, vector<string> &maze) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maze[i][j] == start) {
        return {i, j, 0};
      }
    }
  }
  return {-1, -1, -1}; // 시작점을 찾지 못한 경우
}

int bfs(char start, char end, vector<string>& maze) {
  
  //❶ 방문여부를 체크하는 배열
  bool visited[101][101] = {false};
  queue<Point> q;
    
  //❷ 시작노드부터 너비우선 탐색하도록 추가
  q.push(findStartPoint(start, maze));

  while (!q.empty()) {
    Point current = q.front();
    q.pop();

    //❸ 목적지에 도달했으면 해당 목적지 까지 이동횟수를 반환
    if (maze[current.y][current.x] == end) {
      return current.cnt;
    }
    //❹ 현재위치 기준 상하좌우를 확인 
    for (int i = 0; i < 4; i++) {
      int ny = current.y + dy[i];
      int nx = current.x + dx[i];

      if (isWithinRange(ny, nx) && !visited[ny][nx] && maze[ny][nx] != 'X') {
        //❺ 후보좌표가 미로 범위내에 있고, 아직 방문하지 않았으면 탐색대상으로 추가
        q.push({ny, nx, current.cnt + 1});
        visited[ny][nx] = true;
      }
    }
  }
  return -1;
}

int solution(vector<string> maze) {
  n = maze.size();
  m = maze[0].size();

  //❻ 시작지점부터 L까지 최단거리를 구함 
  int distanceToL = bfs('S', 'L', maze);
  if (distanceToL == -1) return -1;

  //❼ L부터 도착지점까지 최단거리를 구함
  int distanceToE = bfs('L', 'E', maze);
  return distanceToE == -1 ? -1 : distanceToL + distanceToE;
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution({"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"}) << endl; //출력값 : 16
  cout << solution({"LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"}) << endl; //출력값 : -1
  
  return 0;
}

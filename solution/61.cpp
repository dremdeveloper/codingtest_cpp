#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//❶ 현재칸의 좌표와 이전칸에서 현재칸으로 가는 비용
struct Pos {
  int r;
  int c;
  int heightDiff;
  bool operator<(const Pos &p) const {
    return heightDiff > p.heightDiff;
  }
};

int dy[4] = {-1, 0, 1, 0},  dx[4] = {0, 1, 0, -1};
bool visited[301][301];
//❷ 다음 이동할 칸이 격자 내에 존재하는 좌표인지 확인
bool isValid(int nr, int nc, int rows, int cols) {
  return nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc];
}

int solution(vector<vector<int>> land, int height) {
  int totalCost = 0;
  int rows = land.size(), cols = land[0].size();

  priority_queue<Pos> pq;
  pq.push({0, 0, 0});

  while (!pq.empty()) {
    Pos current = pq.top();
    pq.pop();

    //❸ 이미 방문한 칸은, 또 방문하지 않음
    if (visited[current.r][current.c])
      continue;
    //❹ 현재 칸으로 이동하는 비용을 추가
    totalCost += current.heightDiff;
    //❺ 현재칸의 인접 칸을 순회
    for (int i = 0; i < 4; i++) {
      int nr = current.r + dy[i], nc = current.c + dx[i];
      if (isValid(nr, nc, rows, cols)) {
        //❻ 이동가능한 칸과 현재칸의 높이차를 구함
        int diff = abs(land[current.r][current.c] - land[nr][nc]);
        //❼ 높이차가 사다리 설치 기준보다 큰 경우
        if (diff > height)
          pq.push({nr, nc, diff});
        //❽ 높이차가 사다리 설치 기준보다 크지 않은 경우
        else
          pq.push({nr, nc, 0});
      }
    }
    //❾ 현재 칸을 방문여부를 표시
    visited[current.r][current.c] = true;
  }

  return totalCost;
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

void init()
{
  for(int i = 0 ; i <= 300; i++)
    for(int j = 0; j <= 300; j++)
      visited[i][j] = 0;
}

int main()
{
  cout << solution({{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}}, 3) << endl; //출력값 : 15
  init();
  cout << solution({{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}}, 1) << endl; //출력값 : 18
  
  return 0;
}

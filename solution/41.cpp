#include <vector>
#include <queue>
using namespace std;

const int MAX_SIZE = 100;
const int dx[4] = {-1, 0, 1, 0}; 
const int dy[4] = {0, 1, 0, -1}; 
int check[MAX_SIZE][MAX_SIZE];

//❶ 좌표 정보 및 관련 연산을 하기 위한 구조체
struct Point {
  int y, x;

  Point(int y, int x) : y(y), x(x) {}

  bool isValid(int width, int height) const {
    return y >= 0 && y < height && x >= 0 && x < width;
  }

  Point move(int i) const {
    return Point(y + dy[i], x + dx[i]);
  }

  bool canMoveTo(const vector<vector<int>>& maps) const {
    return maps[y][x] == 1 && check[y][x] == 0;
  }
};

queue<Point> q; // BFS를 위한 큐

int solution(vector<vector<int>> maps) {
  int width = maps[0].size(), height = maps.size();
  q.push({0, 0});
  check[0][0] = 1;

  // ❷ 너비우선탐색 진행
  while (!q.empty()) {
    Point current = q.front();
    q.pop();
   //❸ 현재좌표 기준으로 상하좌우를 확인
    for (int i = 0; i < 4; i++) {
      Point next = current.move(i);
      //❹ 범위나 좌표이고 벽이 아닌 경우
      if (next.isValid(width, height) && next.canMoveTo(maps)) {
        check[next.y][next.x] = check[current.y][current.x] + 1;
        q.push({next.y, next.x});
      }
    }
  }

 //❺ 목적지에 도달가능 여부를 확인 
  int destinationX = width - 1, destinationY = height - 1;
  if (check[destinationY][destinationX] == 0) {
    return -1; // 도착 지점에 도달할 수 없음
  }

  return check[destinationY][destinationX]; // 도착 지점까지의 최단 거리 반환
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

void init()
{
  for(int i = 0 ; i < MAX_SIZE; i++)
    for(int j = 0 ; j < MAX_SIZE; j++)
      check[i][j] = false;
}
int main()
{
  
  cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}}) << endl; //출력값 : 11
  init();
  cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}}) << endl; //출력값 : -1

  return 0;
}

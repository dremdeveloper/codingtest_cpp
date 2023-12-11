#include <string>

using namespace std;

bool visited[11][11][4]; // ❶ 특정 좌표에서 특정 방향으로 이동한 적이 있는지 체크하는 배열

// ❷ 상하좌우로 좌표를 이동할 때 필요한 좌표의 오프셋 배열 
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

// ❸ 각 문자에 해당하는 오프셋 배열의 인덱스를 반환
int todir(char dir) {
    int ret;
    if (dir == 'U') ret = 0;
    else if (dir == 'R') ret = 1;
    else if (dir == 'D') ret = 2;
    else ret = 3;
    return ret;
}

// ❹ 특정좌표가 주어진 좌표평면을 벗어나는지 확인
bool isNotValid(int x, int y)
{
    return x < 0 || y < 0 || x > 10 || y > 10;
}
// ❺ 현재와 반대 방향의 오프셋 배열 인덱스 반환
int opposite_direction(int dir)
{
    return (dir+2) % 4;
}

int solution(string dirs)
{
    int answer = 0;
    int x = 5, y = 5; // ❻ 시작 좌표를 설정

    for (auto c : dirs) {
     // ❼ 반복문을 순회하며 nx, ny는  x, y가 dirs대로 움직였을 때 위치가 됨 
        int dir = todir(c);
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // ❽ 좌표평면을 벗어난 경우 더 이상 이동하지 않음
        if (isNotValid(nx,ny)) {
            continue;
        }

        // ❾  다음 좌표가 아직 방문하지 않은 좌표인 경우
        if(visited[y][x][dir] == false) {
          // ❿ 방문이 중복 체크되지 않도록 해당 경로의 양방향을 방문 체크
            visited[y][x][dir] = true;
            visited[ny][nx][opposite_direction(dir)] = true;
            answer++;
        }
      // ⓫ 현재좌표를 이동한 좌표로 업데이트
        x = nx;
        y = ny;
    }
    return answer;
}




//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
    cout << solution("ULURRDLLU") << endl; // 7
    cout << solution("LULLLLLLU") << endl; // 7 

    return 0;
}

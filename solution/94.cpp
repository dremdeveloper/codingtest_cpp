#include <string>
#include <vector>
#include <queue>

using namespace std;

// x, y 위치에서 주변에 'P'가 있는지 검사
bool hasClosePerson(const vector<string>& map, int N, int M, int x, int y) {
    const int dx[4] = { -1, 0, 1, 0 }; // 상하좌우 이동
    const int dy[4] = { 0, -1, 0, 1 };

    queue<pair<int, int>> q;
    bool visited[5][5] = {}; // 방문 여부
    visited[x][y] = true;
    q.push({ x, y });

    for (int layer = 0; layer < 2; layer++) {
        int size = q.size();
        while (size--) {
            pair<int, int> cur = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nextX = cur.first + dx[dir], nextY = cur.second + dy[dir];
                if (!(0 <= nextX && nextX < 5 && 0 <= nextY && nextY < 5)) continue;
                if (visited[nextX][nextY] || map[nextX][nextY] == 'X') continue;
                if (map[nextX][nextY] == 'P') return true;
                visited[nextX][nextY] = true;
                q.push({ nextX, nextY });
            }
        }
    }
    return false;
}

// 지도 전체에서 'P'들이 규칙에 맞게 배치되었는지 확인
bool isSafe(const vector<string>& map, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'P' && hasClosePerson(map, N, M, i, j)) return false;
        }
    }
    return true;
}

// 각 대기실 별로 안전한지 검사하여 결과 반환
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (const auto& place : places) {
        answer.push_back(isSafe(place, 5, 5) ? 1 : 0);
    }
    return answer;
}


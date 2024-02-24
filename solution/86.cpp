#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int maxHeight, maxWidth, targetRow, targetCol, maxSteps;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };
char dir[4] = { 'd', 'l', 'r', 'u' };
string path = "";
bool found = false;

// 보드 내에 있는지 확인
bool InBounds(int x, int y) {
    return x > 0 && x <= maxHeight && y > 0 && y <= maxWidth;
}

// 남은 이동 횟수로 도달 가능한지 확인
bool CanReach(int x, int y, int steps) {
    return abs(x - targetRow) + abs(y - targetCol) <= steps;
}

// 경로 찾기
void Search(int x, int y, int steps, string currPath) {
    if (steps == 0 && x == targetRow && y == targetCol) {
        found = true;
        path = currPath;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (!InBounds(nextX, nextY) || !CanReach(nextX, nextY, steps - 1)) continue;
        Search(nextX, nextY, steps - 1, currPath + dir[i]);
        if (found) return;
    }
}

// 메인 함수
string solution(int n, int m, int x, int y, int r, int c, int k) {
    maxHeight = n;
    maxWidth = m;
    targetRow = r;
    targetCol = c;
    maxSteps = k;

    if (!CanReach(x, y, k) || ((abs(x - r) + abs(y - c)) % 2) != (k % 2)) return "impossible";
    Search(x, y, k, "");
    return path;
}


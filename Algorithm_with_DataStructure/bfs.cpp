//#############################################################
//# | cafe       | http://cafe.naver.com/dremdelover          |
//# | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
//# | business   | ultrasuperrok@gmail.com                    |
//#############################################################
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 전역 인접 리스트 및 방문 리스트
vector<vector<int>> adj;
vector<bool> visited;

// 그래프에 간선을 추가하는 함수
// 인자: u (정점), v (연결된 정점)
void add_edge(int u, int v) {
    adj[u].push_back(v); // 정점 u의 인접 리스트에 정점 v를 추가
}

// 너비 우선 탐색(BFS)을 수행하는 함수
// 인자: start (시작 정점)
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < adj[v].size(); ++i) {
            if (!visited[adj[v][i]]) {
                visited[adj[v][i]] = true;
                q.push(adj[v][i]);
            }
        }
    }
}

// 메인 함수: 그래프 생성 및 BFS 수행
int main() {
    // 정점의 개수
    int V = 5;
    adj.resize(V);

    // 그래프에 간선 추가 (주어진 다이어그램에 따라)
    add_edge(0, 1); // A -> B
    add_edge(0, 2); // A -> C
    add_edge(1, 3); // B -> D
    add_edge(1, 4); // B -> E

    cout << "너비 우선 탐색 (정점 0에서 시작):\n";
    bfs(0);
  
/*  
 BFS 호출 과정 설명 (예: 정점 0에서 시작):
 1. bfs(0) 호출 -> 0 출력, 인접 정점 1과 2를 큐에 추가
 2. 큐에서 1을 꺼내어 출력 -> 인접 정점 3과 4를 큐에 추가
 3. 큐에서 2를 꺼내어 출력 -> 인접 정점 없음
 4. 큐에서 3을 꺼내어 출력 -> 인접 정점 없음
 5. 큐에서 4를 꺼내어 출력 -> 인접 정점 없음
 6. 큐가 비어 있으므로 탐색 종료
*/

    return 0;
}

/*
 너비 우선 탐색(BFS)의 개념:
 - BFS는 그래프 탐색 알고리즘 중 하나로, 시작 정점에서 출발하여 인접한 모든 정점을 먼저 탐색한 후,
   다음 깊이의 정점들을 탐색하는 방식이다.
 - BFS는 큐를 사용하여 구현되며, 시간 복잡도는 O(V + E)이다. 여기서 V는 정점의 수, E는 간선의 수를 의미한다.

 BFS를 사용해야 하는 경우:
 - 최단 경로를 찾아야 하는 경우 (예: 최단 경로 문제)
 - 레벨 순서 탐색을 해야 하는 경우 (예: 각 레벨별로 노드를 처리해야 하는 문제)
 - 사이클 검출 (무방향 그래프에서)

 DFS 대신 BFS를 사용해야 하는 경우:
 - 경로의 길이가 중요한 경우 (BFS는 최단 경로를 보장함)
 - 큐를 사용하여 더 적은 메모리로 처리가 가능한 경우 (특히 넓은 그래프에서)
 - 모든 정점을 같은 레벨에서 순서대로 처리해야 하는 경우
*/

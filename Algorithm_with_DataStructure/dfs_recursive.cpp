#include <iostream>
#include <vector>

using namespace std;

// 전역 인접 리스트 및 방문 리스트
vector<vector<int>> adj;
vector<bool> visited;

// 그래프에 간선을 추가하는 함수
// 인자: v (정점), w (연결된 정점)
void add_edge(int v, int w) {
    adj[v].push_back(w); // 정점 v의 인접 리스트에 정점 w를 추가
}

// 깊이 우선 탐색(DFS)을 수행하는 함수
// 인자: v (현재 정점)
void dfs(int v) {
    // 현재 정점을 방문했다고 표시하고 출력
    visited[v] = true;
    cout << v << " ";

    // 현재 정점에 인접한 모든 정점을 순회
    for (int i = 0; i < adj[v].size(); ++i) {
        if (!visited[adj[v][i]]) {
            dfs(adj[v][i]);
        }
    }
}

// 전체 그래프를 DFS로 순회하는 함수
// 인자: V (정점의 개수)
void dfs_traversal(int V) {
    // 모든 정점을 방문하지 않은 상태로 초기화
    visited.assign(V, false);

    // 모든 정점에 대해 DFS 수행
    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

// 메인 함수: 그래프 생성 및 DFS 수행
int main() {
    // 정점의 개수
    int V = 5;
    adj.resize(V);

    // 그래프에 간선 추가 (주어진 다이어그램에 따라)
    add_edge(0, 1); // A -> B
    add_edge(0, 2); // A -> C
    add_edge(1, 3); // B -> D
    add_edge(1, 4); // B -> E

    cout << "깊이 우선 탐색 (정점 0에서 시작):\n";
    dfs_traversal(V);
  /*
   재귀 호출 과정 설명 (예: 정점 0에서 시작):
 dfs_traversal(5) 호출
    dfs(0) 호출 -> 0 출력
        dfs(1) 호출 -> 1 출력
            dfs(3) 호출 -> 3 출력
            dfs(4) 호출 -> 4 출력
        dfs(2) 호출 -> 2 출력
    - dfs_traversal 종료
  */

    return 0;
}

/*
 깊이 우선 탐색(DFS)의 개념:
 - DFS는 그래프 탐색 알고리즘 중 하나로, 시작 정점에서 출발하여 한 방향으로 가능한 깊이까지 탐색한 후,
   더 이상 갈 곳이 없으면 이전 정점으로 되돌아와 다른 방향으로 탐색을 계속하는 방식이다.
 - 시간 복잡도는 O(V + E)이며, 여기서 V는 정점의 수, E는 간선의 수를 의미한다.

 DFS를 사용해야 하는 경우:
 - 그래프의 모든 정점을 방문해야 하는 경우
 - 경로 찾기 (예: 미로 탐색)
 - 사이클 검출
 - 위상 정렬
 - 강한 연결 요소 찾기

 BFS를 사용할 수 없고 DFS를 사용해야 하는 경우:
 - 재귀적 성질을 이용해야 할 때 (예: 백트래킹 문제)
 - 공간 복잡도가 중요한 경우 (BFS는 큐를 사용하여 더 많은 메모리를 필요로 함)

*/

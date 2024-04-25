//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>

using namespace std;


/*
그래프의 최종 모습 (인접 리스트 형식):
Vertex 0: -> 1 -> 4
Vertex 1: -> 0 -> 2 -> 3 -> 4
Vertex 2: -> 1 -> 3
Vertex 3: -> 1 -> 2 -> 4
Vertex 4: -> 0 -> 1 -> 3
이 구조는 무방향 그래프이며, 각 정점은 해당하는 연결된 정점들과 직접 연결됩니다. 각 정점의 리스트를 통해 모든 간선이 표현됩니다.

시간 복잡도 설명:
- addEdge 함수는 O(1)
- printGraph 함수는 O(V + E)
*/


// addEdge 함수는 그래프의 인접 리스트에 양방향 간선을 추가합니다.
// 이 함수의 시간 복잡도는 O(1), 간선을 두 리스트에 추가하는 데 상수 시간이 걸립니다.
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); // 정점 u에서 v로의 간선 추가
    adj[v].push_back(u); // 무방향 그래프이므로, 정점 v에서 u로의 간선도 추가
}

// printGraph 함수는 그래프의 인접 리스트를 출력합니다.
// 각 정점마다 연결된 모든 정점을 순회하므로, 시간 복잡도는 O(V + E) 입니다.
// 여기서 V는 정점의 수, E는 간선의 수입니다.
void printGraph(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        cout << "Vertex " << i << ":";
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << " -> " << adj[i][j];
        }
        cout << "\n";
    }
}

int main() {
    int V = 5; // 그래프의 정점 개수 설정
    vector<vector<int>> adjList(V); // 각 정점의 인접 리스트를 저장할 벡터 생성

    // 간선 추가
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    // 그래프 출력
    printGraph(adjList);

    return 0;
}


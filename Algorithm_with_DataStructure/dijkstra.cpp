//#############################################################
//# | cafe       | http://cafe.naver.com/dremdelover          |
//# | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
//# | business   | ultrasuperrok@gmail.com                    |
//#############################################################
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

// 무한대를 나타내기 위해 사용되는 상수
const int INF = numeric_limits<int>::max();

// 전역 변수 선언
vector<vector<pair<int, int>>> graph; // 그래프를 인접 리스트 형태로 저장
vector<int> dist;                    // 각 노드까지의 최단 거리를 저장
vector<int> prev;                    // 각 노드의 직전 노드를 저장

// 다익스트라 알고리즘 함수
void dijkstra(int start) {
    int n = graph.size();        // 그래프의 노드 개수
    dist.assign(n, INF);         // 최단 거리 배열을 무한대로 초기화
    prev.assign(n, -1);          // 직전 노드 배열을 -1로 초기화
    dist[start] = 0;             // 시작 노드의 거리는 0으로 설정
    
    // 최소 힙 (우선순위 큐)을 사용하여 최단 거리를 찾음
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});         // 시작 노드를 큐에 추가
    
    // 초기 상태
    /*
    Initial state:
    Node:  A  B  C  D  E
    Dist:  0  INF  INF  INF  INF
    Prev:  -1  -1  -1  -1  -1
    */

    // 큐가 빌 때까지 반복
    while (!pq.empty()) {
        int d = pq.top().first;  // 현재 노드까지의 거리
        int u = pq.top().second; // 현재 노드
        pq.pop();                // 큐에서 제거
        
        // 현재 노드까지의 거리가 이미 더 짧은 경로가 있으면 무시
        if (d > dist[u]) continue;

        // 현재 노드의 모든 인접 노드를 탐색
        for (const auto& edge : graph[u]) {
            int v = edge.first;   // 인접 노드
            int weight = edge.second; // 가중치
            
            // 더 짧은 경로를 발견한 경우
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight; // 최단 거리 업데이트
                prev[v] = u;                // 직전 노드 업데이트
                pq.push({dist[v], v});      // 큐에 추가
            }
        }
    }
}

// 경로를 출력하는 함수 (재귀 호출 사용)
void printPath(int node) {
    if (node == -1) return;     // base case: 시작 노드에 도달
    printPath(prev[node]);      // 직전 노드로 재귀 호출
    cout << node << " ";        // 현재 노드 출력
}

// 다익스트라 알고리즘 수행 과정 주석
/*
Initial state:
Node:  A  B  C  D  E
Dist:  0  INF  INF  INF  INF
Prev:  -1  -1  -1  -1  -1

1. A 노드 선택 (현재 최단 거리: 0)
- 인접 노드 B, C, E 업데이트:
After visiting A:
Node:  A  B  C  D  E
Dist:  0  4  4  INF  1
Prev:  -1  0  0  -1  0

2. E 노드 선택 (현재 최단 거리: 1)
- 인접 노드 C 업데이트:
After visiting E:
Node:  A  B  C  D  E
Dist:  0  4  3  INF  1
Prev:  -1  0  4  -1  0

3. C 노드 선택 (현재 최단 거리: 3)
- 인접 노드 B, D 업데이트:
After visiting C:
Node:  A  B  C  D  E
Dist:  0  4  3  11  1
Prev:  -1  0  4  2  0

4. B 노드 선택 (현재 최단 거리: 4)
- 인접 노드 업데이트 없음
After visiting B:
Node:  A  B  C  D  E
Dist:  0  4  3  11  1
Prev:  -1  0  4  2  0

5. D 노드 선택 (현재 최단 거리: 11)
- 인접 노드 B 업데이트:
After visiting D:
Node:  A  B  C  D  E
Dist:  0  4  3  11  1
Prev:  -1  0  4  2  0

최종 상태:
Node:  A  B  C  D  E
Dist:  0  4  3  11  1
Prev:  -1  0  4  2  0
*/

/*
다익스트라 알고리즘에 대한 설명:
1. 다익스트라 알고리즘의 개념:
   다익스트라 알고리즘은 가중치가 있는 그래프에서 특정 시작 노드로부터 다른 모든 노드까지의 최단 경로를 찾는 알고리즘입니다.
   이 알고리즘은 그래프의 모든 간선의 가중치가 양수일 때 유효합니다.

2. 다익스트라 알고리즘의 과정:
   1) 시작 노드의 거리를 0으로 설정하고, 나머지 노드의 거리는 무한대로 설정합니다.
   2) 모든 노드를 미방문 집합에 추가합니다.
   3) 현재 노드에서 인접한 모든 노드의 거리를 계산하여 더 짧은 경로가 발견되면 거리를 업데이트합니다.
   4) 현재 노드를 방문한 것으로 표시하고, 미방문 노드 중 최단 거리를 가진 노드를 선택하여 3) 과정을 반복합니다.
   5) 모든 노드를 방문할 때까지 3)과 4) 과정을 반복합니다.

3. 다익스트라 알고리즘의 시간 복잡도:
   - 인접 리스트를 사용한 구현: O((V+E)log V), 여기서 V는 노드의 개수, E는 간선의 개수입니다.
     (우선순위 큐를 사용하여 최소 거리를 찾고 업데이트하는데 log V 시간이 걸립니다)

4. 다익스트라 알고리즘의 한계:
   - 음수 가중치를 가진 간선이 있는 그래프에서는 동작하지 않습니다. 음수 가중치가 있는 경우 벨만-포드 알고리즘을 사용해야 합니다.

코드 실행 결과:
Node	Distance	Path
0	0		0 
1	4		0 1 
2	3		0 4 2 
3	11	0 4 2 3 
4	1		0 4 
*/

int main() {
    // 그래프를 인접 리스트 형태로 정의
    // 각 pair는 (인접 노드, 가중치)를 의미
    graph = {
        {{1, 4}, {2, 4}, {4, 1}},   // A (0)
        {},                         // B (1)
        {{1, 6}, {3, 8}},           // C (2)
        {{1, 2}},                   // D (3)
        {{2, 2}}                    // E (4)
    };

    int start = 0; // 시작 노드 (A)
    dijkstra(start); // 다익스트라 알고리즘 실행
    
    // 결과 출력
    cout << "Node\tDistance\tPath" << endl;
    for (int i = 0; i < dist.size(); ++i) {
        cout << i << "\t" << dist[i] << "\t\t";
        printPath(i);
        cout << endl;
    }
    
    return 0;
}

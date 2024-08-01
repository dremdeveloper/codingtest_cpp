#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> Edge; // (비용, 정점)

vector<vector<Edge>> graph; // 그래프를 전역 변수로 선언

// 문제의 정의:
// 주어진 그래프에서 모든 정점을 최소 비용으로 연결하는 최소 신장 트리(MST)를 찾는 문제입니다.
// 정점은 1부터 6까지 번호가 매겨져 있으며, 간선에는 가중치가 부여되어 있습니다.

// 프림 알고리즘 설명:
// 프림 알고리즘은 하나의 시작 정점에서 출발하여 MST를 단계적으로 확장해 나가는 방식입니다.
// 1. 시작 정점을 선택하고, 해당 정점을 MST 집합에 추가합니다.
// 2. MST 집합에 인접한 간선 중에서 가장 가중치가 작은 간선을 선택하여 연결된 정점을 MST 집합에 추가합니다.
// 3. 이 과정을 모든 정점이 MST 집합에 포함될 때까지 반복합니다.
// 우선순위 큐를 사용하여 현재 정점에서 가장 가중치가 작은 간선을 효율적으로 선택할 수 있습니다.

// 왜 그리디로 풀리는지:
// 탐욕적 선택 속성: 매 단계에서 현재 MST에 인접한 간선 중에서 가장 비용이 적은 간선을 선택하여 MST를 확장합니다.
// 이렇게 하면 항상 부분 문제의 최적해가 전체 문제의 최적해로 이어집니다.
// 최적 부분구조: 현재 선택한 간선이 전체 최소 신장 트리의 일부라면, 남은 간선들로 구성된 부분 문제도 최소 신장 트리가 됩니다.
// 즉, 작은 문제를 해결하여 전체 문제를 해결할 수 있습니다.

// greater<Edge> 설명:
// priority_queue는 기본적으로 큰 값을 먼저 꺼내는 최대 힙입니다. 하지만 프림 알고리즘에서는 가장 작은 가중치를 먼저 선택해야 하므로
// greater<Edge>를 사용하여 최소 힙을 만듭니다. 이는 Edge의 첫 번째 요소(비용)를 기준으로 오름차순 정렬하여 작은 값이 먼저 나오도록 합니다.

// 그래프를 인접 리스트 형태로 표현
void addEdge(int u, int v, int weight) {
    graph[u].push_back(make_pair(weight, v));
    graph[v].push_back(make_pair(weight, u));
}

// 프림 알고리즘으로 최소 신장 트리 구하기
int primMST(int V) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<int> key(V + 1, INT_MAX); // 최소 비용을 저장하는 배열 (정점 번호 1부터 사용)
    vector<bool> inMST(V + 1, false); // MST에 포함 여부를 저장하는 배열
    int result = 0; // MST의 총 비용

    // 시작 정점은 1로 설정하고 초기화
    key[1] = 0;
    pq.push(make_pair(0, 1));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // 이미 MST에 포함된 정점은 무시
        if (inMST[u]) {
            continue;
        }

        // 현재 정점을 MST에 포함시키고 비용을 더함
        inMST[u] = true;
        result += key[u];

        // 인접한 정점의 비용을 업데이트
        for (auto& edge : graph[u]) {
            int weight = edge.first;
            int v = edge.second;

            // 아직 MST에 포함되지 않고, 현재 정점을 통해 더 저렴하게 갈 수 있는 경우
            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    return result;
}

int main() {
    int V = 6; // 정점의 개수
    graph.resize(V + 1); // 정점 번호 1부터 사용

    // 그래프의 간선 추가 (이미지를 참고하여 작성)
    addEdge(1, 2, 9);
    addEdge(1, 4, 7);
    addEdge(2, 4, 8);
    addEdge(2, 3, 2);
    addEdge(2, 6, 5);
    addEdge(3, 6, 3);
    addEdge(3, 4, 6);
    addEdge(3, 5, 4);
    addEdge(4, 5, 5);

    cout << "최소 신장 트리의 비용: " << primMST(V) << endl;

    return 0;
}

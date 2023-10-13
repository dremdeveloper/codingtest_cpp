//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
/*
크루스칼 알고리즘(Kruskal's algorithm)은 그래프에서 최소 신장 트리를 찾는 알고리즘 중 하나입니다.
개념: 가장 가중치가 작은 간선부터 선택하되, 싸이클을 형성하지 않도록 하는 간선을 선택합니다.

시간 복잡도: O(ElogE) 또는 O(ElogV), E는 간선의 수, V는 정점의 수 입니다.
간선을 정렬하는 데 O(ElogE)의 시간이 걸리고, 유니온-파인드 연산은 O(a(n))으로, 접하시는 모든 코테에서 사실상 O(1)이라고 보아도 무방합니다.

적용 예시: 네트워크 디자인(모든 노드를 가장 적은 비용으로 연결), 물류 네트워크 최적화 등 다양한 곳에서 활용됩니다.
도식화 설명:
노드들: A(1), B(2), C(3), D(4), E(5)
간선들: AB(3), AD(4), BD(2), BE(3), BC(1), CE(4), DE(5)

1. 초기 상태: 모든 노드가 독립적인 집합으로 있습니다.
A B C D E

2. 간선 선택: 가중치가 가장 낮은 BC 간선을 선택합니다.
선택된 간선: BC
A (BC) D E

3. 간선 선택: 다음으로 가중치가 가장 낮은 BD 간선을 선택합니다.
선택된 간선: BC, BD
A (BCD) E

이런 식으로 나머지 간선들도 처리하여 MST를 완성합니다.
*/


#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// 간선 구조체 정의
struct Edge {
    int u, v, w;  // u와 v는 연결된 노드, w는 가중치
    // 연산자 오버로딩을 사용하여 정렬 기능을 적용합니다.
    bool operator<(Edge const& other) {
        return w < other.w;  // 가중치를 기준으로 정렬
    }
};

vector<int> parent, rank_;

/*
  find_set 함수: 정점 v가 속한 집합의 대표를 찾습니다.
  이 함수는 경로 압축 기법을 사용하여 높은 효율성을 가집니다.
  경로 압축: find_set를 실행하는 도중에 만나는 모든 정점들이 직접 대표를 가리키게 됩니다.
*/
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

/*
  union_sets 함수: 두 정점 a와 b를 연결합니다. 
  이 함수는 합치기에 의한 랭크(rank) 기법을 사용하여 효율적인 연산을 보장합니다.
  합치기에 의한 랭크: 두 트리를 합칠 때 높이가 더 낮은 트리를 더 높은 트리 밑에 넣습니다.
*/
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

int main() {
    int n = 5;  // 노드의 수
    int m = 7;  // 간선의 수
    vector<Edge> edges = {
        {1, 2, 3}, 
        {1, 4, 4}, 
        {2, 4, 2}, 
        {2, 5, 3}, 
        {2, 3, 1}, 
        {3, 5, 4}, 
        {4, 5, 5}
    };

    // 크루스칼 알고리즘 구현
    int cost = 0;  // 최소 신장 트리의 가중치 합
    vector<Edge> result;  // 최소 신장 트리를 구성하는 간선들
    parent.resize(n+1);
    rank_.resize(n+1);
    // 초기화
    for (int i=1; i<=n; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }
    // 간선들을 가중치 기준으로 정렬
    sort(edges.begin(), edges.end());

    // 모든 간선에 대해서 순회
    for (Edge e : edges) {
        // 사이클이 형성되지 않는다면 (즉, 두 노드의 대표 노드가 다르다면)
        if (find_set(e.u) != find_set(e.v)) {
            // 가중치 합에 추가
            cost += e.w;
            // 결과 간선 집합에 추가
            result.push_back(e);
            // 두 노드를 하나의 집합으로 합치기
            union_sets(e.u, e.v);
        }
    }

    // 결과 출력
    cout << "Cost: " << cost << endl;  // 최소 가중치 합 출력
    cout << "Edges in MST: " << endl;  // 최소 신장 트리를 구성하는 간선 출력
    for (Edge e : result) {
        cout << e.u << " - " << e.v << " (Weight: " << e.w << ")" << endl;
    }

    return 0;
}

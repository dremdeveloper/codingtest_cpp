//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

#include <iostream>
#include <vector>
using namespace std;

// Find 연산: 특정 원소가 속한 집합의 대표(루트) 원소를 찾는 함수입니다.
// 경로 압축(Path Compression)을 통해 트리의 높이를 낮춰 탐색 속도를 향상시킵니다.
// 이는 재귀적으로 부모 노드를 찾아가며, 각 노드의 부모를 직접 루트 노드로 갱신합니다.
int find(int parent[], int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]); // 경로 압축 적용
    }
    return parent[x];
}

// Union 연산: 두 집합을 하나로 합치는 함수입니다.
// 유니온 바이 랭크(Union by Rank)를 통해 트리의 높이를 최소화하여 성능을 최적화합니다.
// 랭크가 높은 트리의 루트를 낮은 트리의 루트로 설정하여 트리의 균형을 유지합니다.
void unite(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        // 랭크가 높은 트리를 다른 트리에 합침
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// 두 노드가 같은 집합에 속해 있는지 확인하는 함수입니다.
// 두 노드의 루트 노드를 비교하여 같은 집합에 속하는지 여부를 반환합니다.
// 같은 루트 노드를 갖고 있으면 연결된 것입니다.
bool connected(int parent[], int x, int y) {
    return find(parent, x) == find(parent, y);
}

// 주어진 노드와 간선 목록, 쿼리 목록을 바탕으로 두 노드가 연결되어 있는지 확인하는 함수입니다.
vector<int> solution(int n, int m, const vector<pair<int, int>>& edges, int q, const vector<pair<int, int>>& queries) {
    int parent[n]; // 각 노드의 부모 노드를 저장하는 배열입니다.
    int rank[n] = {0}; // 각 노드의 트리 높이를 저장하는 배열입니다.
    
    // 초기화: 모든 노드를 각각의 집합으로 설정합니다.
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    // 간선 정보 입력 및 Union 연산 수행합니다.
    // 각 간선에 대해 Union 연산을 호출하여 두 노드를 같은 집합으로 만듭니다.
    for (int i = 0; i < m; ++i) {
        unite(parent, rank, edges[i].first, edges[i].second);
    }
    
    vector<int> result(q); // 결과를 저장할 벡터입니다.
    for (int i = 0; i < q; ++i) {
        if (connected(parent, queries[i].first, queries[i].second)) {
            result[i] = 1;  // 연결됨
        } else {
            result[i] = 0;  // 연결되지 않음
        }
    }
    
    return result; // 결과를 반환합니다.
}

int main() {
    // 예시 입력
    int n = 6;
    int m = 3;
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    int q = 2;
    vector<pair<int, int>> queries = {{0, 2}, {0, 3}};
    
    // solution 함수 호출
    vector<int> result = solution(n, m, edges, q, queries);
    
    // 결과 출력
    for (int i = 0; i < q; ++i) {
        cout << result[i] << endl;
    }
    
    return 0;
}

/*
입력 예시:
6
3
0 1
1 2
3 4
2
0 2
0 3

출력 예시:
1
0

제약사항:
- 1 <= n <= 10^4
- 0 <= edges.length <= 10^4
- 0 <= queries.length <= 10^4
- edges[i].length == 2
- queries[i].length == 2
- 0 <= edges[i][j] < n
- 0 <= queries[i][j] < n

입력값 설명:
- 첫 번째 줄: 그래프의 노드 개수 n
- 두 번째 줄: 간선의 개수 m
- 세 번째 줄부터: m개의 줄에 간선 목록, 각 줄마다 두 개의 정수 u와 v가 주어지며 이는 노드 u와 노드 v가 연결되었음을 의미합니다.
- 그 다음 줄: 쿼리 개수 q
- 그 다음 줄부터: q개의 줄에 쿼리 목록, 각 줄마다 두 개의 정수 x와 y가 주어지며 이는 노드 x와 노드 y가 연결되어 있는지 확인하는 쿼리입니다.

출력값 설명:
- 각 쿼리에 대해 두 노드가 연결되어 있으면 1, 그렇지 않으면 0을 출력합니다.

시간 복잡도:
- Find 연산: 평균적으로 O(α(N)), 여기서 α는 아커만 함수의 역함수로 매우 느리게 증가하는 함수입니다.
  - 경로 압축(Path Compression)을 사용하여 트리의 높이를 최소화합니다.
  - 따라서 대부분의 경우 거의 상수 시간에 가깝게 동작합니다.
- Union 연산: 평균적으로 O(α(N))
  - 유니온 바이 랭크(Union by Rank)를 사용하여 트리의 높이를 최소화합니다.
  - 두 트리를 합칠 때, 트리의 높이가 더 작은 트리를 큰 트리에 합쳐 트리의 높이를 낮춥니다.
- 전체 시간 복잡도: O(N + M + Q * α(N))
  - N: 노드의 개수
  - M: 간선의 개수
  - Q: 쿼리의 개수
  - α(N): 아커만 함수의 역함수로, 매우 느리게 증가하여 사실상 상수 시간으로 간주될 수 있습니다.

시간 복잡도 근거:
- 경로 압축과 유니온 바이 랭크 기법을 사용함으로써 각 연산의 시간 복잡도가 매우 낮아집니다.
- 아커만 함수의 역함수는 대부분의 실용적인 문제 크기에서 상수 시간에 가깝기 때문에, 전체적인 시간 복잡도는 매우 효율적입니다.
*/


//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>

using namespace std;

/*
그래프의 최종 모습 (인접 행렬 형식):
Adjacency Matrix:
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0
이 구조는 무방향 그래프를 나타내며, 각 정점은 해당하는 다른 정점들과 1로 표시된 연결을 가집니다.
시간 복잡도 설명:
- addEdge 함수는 O(1)
- printGraph 함수는 O(V^2)
*/


// addEdge 함수는 그래프의 인접 행렬에 양방향 간선을 추가합니다.
// 'u'와 'v'는 연결될 두 정점입니다. 'adjMatrix'는 인접 행렬을 나타내는 2차원 벡터입니다.
// 이 함수의 시간 복잡도는 O(1), 특정 행렬 위치에 접근하여 값을 설정하는데 상수 시간이 걸립니다.
void addEdge(vector<vector<int>>& adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;  // 정점 u에서 v로의 간선을 추가
    adjMatrix[v][u] = 1;  // 무방향 그래프이므로, 정점 v에서 u로도 간선을 추가
}

// printGraph 함수는 그래프의 인접 행렬을 출력합니다.
// 각 행과 열을 순회하며, 각 정점간 연결 상태를 출력합니다.
// 시간 복잡도는 O(V^2) 입니다. 여기서 V는 정점의 수입니다.
void printGraph(const vector<vector<int>>& adjMatrix) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < adjMatrix.size(); ++i) {
        for (int j = 0; j < adjMatrix[i].size(); ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int V = 5; // 그래프의 정점 개수
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0)); // 모든 값을 0으로 초기화된 VxV 크기의 2차원 벡터 생성

    // 간선 추가
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    // 그래프 출력
    printGraph(adjMatrix);

    return 0;
}



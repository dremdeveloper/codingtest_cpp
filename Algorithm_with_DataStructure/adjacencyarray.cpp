//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
using namespace std;

// 인접 행렬의 노드 개수 (고정)
const int numNodes = 2;

// 인접 행렬 배열
int adjMatrix[numNodes][numNodes];

// 인접 행렬을 초기화하는 함수
// 모든 값을 0으로 설정
void initializeMatrix() {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// 간선을 추가하는 함수
// u에서 v로 가는 간선의 가중치를 설정
void addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
}

// 인접 행렬을 출력하는 함수
// 값이 0인 경우 '-'로 출력
void printMatrix() {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (adjMatrix[i][j] == 0)
                cout << "- ";
            else
                cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 인접 행렬 초기화
    initializeMatrix();

    // 엣지 추가: 서울(0)에서 부산(1)으로 가는 엣지, 가중치 400
    addEdge(0, 1, 400);

    // 인접 행렬 출력
    printMatrix();

    /*
    최종적인 인접 행렬의 모습:
    - 400 
    -  - 
    */

    return 0;
}

/*
인접 행렬 설명:
- 인접 행렬은 그래프를 행렬 형태로 표현하는 방법입니다.
- 행과 열의 인덱스는 각각의 노드를 나타내고, 행렬의 값은 간선의 가중치를 나타냅니다.
- 만약 간선이 없는 경우 0으로 표시되며, 이 코드에서는 '-'로 출력됩니다.

인접 행렬의 시간 복잡도:
- 인접 행렬을 사용하여 그래프를 표현할 경우, 공간 복잡도는 O(V^2)입니다. 여기서 V는 노드의 개수입니다.
- 간선이 존재하는지 확인하는 작업은 O(1)의 시간 복잡도를 가집니다.
- 모든 간선을 탐색하는 작업은 O(V^2)의 시간 복잡도를 가집니다.

최종적인 인접 행렬의 모습:
- 400 
-  - 
*/



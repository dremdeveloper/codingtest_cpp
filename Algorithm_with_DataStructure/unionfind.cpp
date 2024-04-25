//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

#include <iostream>

using namespace std;

const int MAX_SIZE = 100;  // 집합의 최대 크기, 필요에 따라 조정 가능
int parent[MAX_SIZE];      // 각 원소의 부모 원소를 저장
int nodeRank[MAX_SIZE];        // 각 트리의 높이를 저장

// n개의 원소에 대해 각각을 독립적인 집합으로 초기화
void initialize(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // 초기에 각 원소의 부모는 자기 자신
        nodeRank[i] = 0;    // 초기 트리의 높이는 0
    }
}

// Find 함수: 주어진 원소 x의 루트 원소를 찾는다.
// 경로 압축을 사용하여 효율성 증가: find를 실행하는 동안 만나는 모든 노드를 직접 루트에 연결
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // 경로 압축
    }
    return parent[x];
}

// Union 함수: 두 원소 x, y가 포함된 집합을 합친다.
// 랭크를 사용하여 두 트리를 균형있게 합침
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {  // 두 원소가 다른 집합에 속해있는 경우
        if (nodeRank[rootX] > nodeRank[rootY]) {
            parent[rootY] = rootX;  // 더 높은 랭크의 트리 아래에 낮은 랭크의 트리를 합침
        } else if (nodeRank[rootX] < nodeRank[rootY]) {
            parent[rootX] = rootY;  // 반대 경우
        } else {
            parent[rootY] = rootX;
            nodeRank[rootX]++;  // 같은 높이의 트리를 합치면 결과 트리의 높이가 증가
        }
    }
}

int main() {
    int n = 10;  // 예시로 10개의 원소로 집합을 생성
    initialize(n);

    // 연산 수행 및 각 스텝에서의 트리 변화 설명
    unionSets(0, 1);
    unionSets(1, 2);
    unionSets(3, 4);
    unionSets(0, 4);

    // 모든 원소에 대해 find를 호출하여 경로 압축 적용
    for (int i = 0; i < n; i++) {
        find(i);
    }

    // 최종 트리 구조 출력
    for (int i = 0; i < n; i++) {
        cout << "Parent of " << i << ": " << parent[i] << ", nodeRank: " << nodeRank[i] << endl;
    }

    return 0;
}

/*
최종 트리 구조 (경로 압축 후):
최종 트리 구조 (경로 압축 후):
        0 (root)
       /|\
      / | \
     1  3  4
     |
     2

설명:
- 노드 0이 루트 노드입니다.
- 노드 1, 3, 4는 직접적으로 노드 0에 연결되어 있습니다.
- 노드 2는 노드 1에 연결되어 있었지만, 경로 압축을 통해 직접 노드 0에 연결되어 있습니다.
- 노드 5, 6, 7, 8, 9는 각각 자기 자신이 루트입니다 (독립적인 집합 그림에 표시하지 않음).

이 구조는 경로 압축 기법이 적용된 후 모든 노드가 가능한 직접적으로 루트 노드에 연결되도록 최적화되어 있음을 보여줍니다.

*/

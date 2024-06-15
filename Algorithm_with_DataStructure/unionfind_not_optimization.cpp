#include <iostream>

const int MAX_SIZE = 10;  // 예제에서는 최대 요소 수를 10으로 설정

int parent[MAX_SIZE];

// 초기화 함수: n개의 요소로 초기화
void initialize(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;  // 초기에는 모든 요소가 자기 자신을 부모로 가짐
    }
}

// find 함수: 루트를 찾기 위한 기본적인 방법
// 이 함수는 트리의 루트를 찾기 위해 부모 배열을 순회합니다.
// 시간복잡도: O(n) (최악의 경우, 트리가 한쪽으로 치우쳐 있을 때)
int find(int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

// union 함수: 두 집합을 합침
// 이 함수는 두 집합을 합치는 작업을 수행합니다.
// 시간복잡도: O(n) (find 함수의 시간복잡도에 의해 결정됨)
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        parent[rootY] = rootX;  // 단순히 y의 루트를 x의 루트로 변경
    }
}

int main() {
    int n = 10;  // 예제용 요소 수
    initialize(n);

    // 초기 상태:
    // 각 요소가 자신을 루트로 가짐
    // 0 1 2 3 4 5 6 7 8 9
    // | | | | | | | | | |
    // 0 1 2 3 4 5 6 7 8 9

    // unionSets(1, 2) 호출 후:
    unionSets(1, 2);
    // 트리 구조:
    //  1
    //  |
    //  2
    //
    // 부모 배열: [0, 1, 1, 3, 4, 5, 6, 7, 8, 9]

    // unionSets(3, 4) 호출 후:
    unionSets(3, 4);
    // 트리 구조:
    //  3
    //  |
    //  4
    //
    // 부모 배열: [0, 1, 1, 3, 3, 5, 6, 7, 8, 9]

    // unionSets(2, 4) 호출 후:
    unionSets(2, 4);
    // 트리 구조:
    //   1
    //  / 
    // 2   
    // |
    // 3
    // |
    // 4
    //
    // 부모 배열: [0, 1, 1, 1, 1, 5, 6, 7, 8, 9]

    // unionSets(5, 6) 호출 후:
    unionSets(5, 6);
    // 트리 구조:
    //  5
    //  |
    //  6
    //
    // 부모 배열: [0, 1, 1, 1, 1, 5, 5, 7, 8, 9]

    // find 연산 수행 및 결과 출력
    std::cout << "find(1): " << find(1) << std::endl;  // 1
    // 트리 구조: 변화 없음
    //   1
    //  /|\
    // 2 3 4

    std::cout << "find(2): " << find(2) << std::endl;  // 1
    // 트리 구조: 변화 없음
    //   1
    //  /|\
    // 2 3 4

    std::cout << "find(3): " << find(3) << std::endl;  // 1
    // 트리 구조: 변화 없음
    //   1
    //  /|\
    // 2 3 4

    std::cout << "find(4): " << find(4) << std::endl;  // 1
    // 트리 구조: 변화 없음
    //   1
    //  /|\
    // 2 3 4

    std::cout << "find(5): " << find(5) << std::endl;  // 5
    // 트리 구조: 변화 없음
    //  5
    //  |
    //  6

    std::cout << "find(6): " << find(6) << std::endl;  // 5
    // 트리 구조: 변화 없음
    //  5
    //  |
    //  6

    return 0;
}

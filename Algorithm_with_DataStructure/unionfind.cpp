//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

#include <iostream>

const int MAX_SIZE = 10;  // 예제에서는 최대 요소 수를 10으로 설정

int parent[MAX_SIZE];
int rank[MAX_SIZE];

// 초기화 함수: n개의 요소로 초기화
void initialize(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;  // 초기에는 모든 요소가 자기 자신을 부모로 가짐
        rank[i] = 0;    // 초기 랭크는 0으로 설정
    }
}

// find 함수: 경로 압축 기법을 사용하여 루트 찾기
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // 경로 압축
    }
    return parent[x];
}

// union 함수: rank를 사용하여 두 집합 합치기
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        // rank가 더 낮은 트리를 더 높은 트리 밑에 붙임
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            ++rank[rootX];
        }
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
    // 랭크 배열: [0, 1, 0, 0, 0, 0, 0, 0, 0, 0]

    // unionSets(3, 4) 호출 후:
    unionSets(3, 4);
    // 트리 구조:
    //  3
    //  |
    //  4
    //
    // 부모 배열: [0, 1, 1, 3, 3, 5, 6, 7, 8, 9]
    // 랭크 배열: [0, 1, 0, 1, 0, 0, 0, 0, 0, 0]

    // unionSets(2, 4) 호출 후:
    unionSets(2, 4);
    // 트리 구조:
    //   1
    //  / \
    // 2   3
    //      |
    //      4
    //
    // 부모 배열: [0, 1, 1, 1, 3, 5, 6, 7, 8, 9]
    // 랭크 배열: [0, 2, 0, 1, 0, 0, 0, 0, 0, 0]

    // unionSets(5, 6) 호출 후:
    unionSets(5, 6);
    // 트리 구조:
    //  5
    //  |
    //  6
    //
    // 부모 배열: [0, 1, 1, 1, 3, 5, 5, 7, 8, 9]
    // 랭크 배열: [0, 2, 0, 1, 0, 1, 0, 0, 0, 0]

    // find 연산 수행 및 결과 출력
    std::cout << "find(1): " << find(1) << std::endl;  // 1
    // 트리 구조: 변화 없음
    //   1
    //  / \
    // 2   3
    //      |
    //      4

    std::cout << "find(2): " << find(2) << std::endl;  // 1
    // 트리 구조:
    //   1
    //  /|\
    // 2 3 4
    // 경로 압축이 일어나 2와 4가 직접 1을 가리키게 됩니다.

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

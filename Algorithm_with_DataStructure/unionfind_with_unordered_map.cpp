//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <unordered_map>

using namespace std;

// 노드 값을 키로 가지는 부모와 랭크를 저장하는 맵
unordered_map<long long, long long> parent;
unordered_map<long long, int> rank;

// 초기화 함수: 주어진 노드를 초기화
// 이 함수는 주어진 노드를 초기화하여 자기 자신을 루트로 가지도록 합니다.
// 시간복잡도: O(1) (각 노드의 초기화는 상수 시간에 이루어짐)
void initialize(long long x) {
    parent[x] = x;  // 초기에는 모든 노드가 자기 자신을 부모로 가짐
    rank[x] = 0;    // 초기 랭크는 0으로 설정
}

// find 함수: 경로 압축 기법을 사용하여 루트 찾기
// 이 함수는 경로 압축 기법을 사용하여 주어진 노드의 루트 노드를 찾습니다.
// 경로 압축을 통해 트리의 높이를 줄여 이후 연산의 효율성을 높입니다.
// 시간복잡도: 거의 O(1)로 간주될 수 있습니다 (아커만 함수의 역함수에 비례).
long long find(long long x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // 경로 압축
    }
    return parent[x];
}

// union 함수: rank를 사용하여 두 집합 합치기
// 이 함수는 두 집합을 합치는 작업을 수행합니다. 
// 두 집합의 루트를 비교하여, 더 낮은 랭크의 트리를 더 높은 랭크의 트리 밑에 붙여 트리의 높이를 최소화합니다.
// 시간복잡도: 거의 O(1)로 간주될 수 있습니다 (아커만 함수의 역함수에 비례).
void unionSets(long long x, long long y) {
    long long rootX = find(x);
    long long rootY = find(y);

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
    // 노드 값이 매우 큰 경우를 가정하여 몇 가지 노드를 초기화
    initialize(1000000000);
    initialize(1000000001);
    initialize(2000000000);
    initialize(2000000001);

    // unionSets 연산 수행
    unionSets(1000000000, 1000000001);
    unionSets(2000000000, 2000000001);
    unionSets(1000000001, 2000000001);

    // find 연산 수행 및 결과 출력
    cout << "find(1000000000): " << find(1000000000) << endl;
    cout << "find(1000000001): " << find(1000000001) << endl;
    cout << "find(2000000000): " << find(2000000000) << endl;
    cout << "find(2000000001): " << find(2000000001) << endl;

    return 0;
}

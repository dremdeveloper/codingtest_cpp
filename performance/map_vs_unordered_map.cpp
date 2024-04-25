//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

#include <iostream>
#include <unordered_map>
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;

// map과 unordered_map의 삽입 시간비교

//unordered_map은 해시 테이블을 기반으로 하며, 평균적으로 O(1)의 시간 복잡도를 제공한다. 그러나 최악의 경우, 모든 요소가 하나의 버킷에 모일 때 O(n)이 될 수 있다.
//map은 레드-블랙 트리(Red-Black Tree)를 기반으로 하는 균형 이진 검색 트리로, 모든 주요 연산(삽입, 삭제, 검색)에 O(log n)의 시간 복잡도가 걸린다.

// 성능 차이의 주된 이유는 다음과 같다:
// - unordered_map은 해시 함수로 구현되어있으므로 삽입/삭제시 정렬이 따로 필요없다
// - map은 항상 정렬된 상태를 유지해야 하므로 삽입과 검색이 더 오래 걸릴 수 있다.(매번 정렬해야 함)

int main() {
    const int NUM_ELEMENTS = 100000; // 원소 수

    unordered_map<int, int> unorderedMap;
    map<int, int> orderedMap;

    // unordered_map에 대한 삽입 성능 측정
    auto start = high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        unorderedMap[i] = i;
    }
    auto end = high_resolution_clock::now();
    auto durationUnorderedInsert = duration_cast<milliseconds>(end - start);
    cout << "Insertion into unordered_map: " << durationUnorderedInsert.count() << " ms" << endl;

    // map에 대한 삽입 성능 측정
    start = high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        orderedMap[i] = i;
    }
    end = high_resolution_clock::now();
    auto durationOrderedInsert = duration_cast<milliseconds>(end - start);
    cout << "Insertion into map: " << durationOrderedInsert.count() << " ms" << endl;

    // unordered_map에 대한 검색 성능 측정
    start = high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        auto it = unorderedMap.find(i);
    }
    end = high_resolution_clock::now();
    auto durationUnorderedSearch = duration_cast<milliseconds>(end - start);
    cout << "Search in unordered_map: " << durationUnorderedSearch.count() << " ms" << endl;

    // map에 대한 검색 성능 측정
    start = high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        auto it = orderedMap.find(i);
    }
    end = high_resolution_clock::now();
    auto durationOrderedSearch = duration_cast<milliseconds>(end - start);
    cout << "Search in map: " << durationOrderedSearch.count() << " ms" << endl;



    return 0;
}

//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

#include <iostream>
#include <set>
#include <unordered_set>
#include <chrono>

using namespace std;
using namespace std::chrono;

//set과 unordered_set의 성능 측정

// std::set은 레드-블랙 트리(Red-Black Tree)를 기반으로 하는 균형 이진 검색 트리로, 모든 주요 연산(삽입, 삭제, 검색)에 O(log n)의 시간 복잡도가 걸린다.
// std::unordered_set은 해시 테이블을 기반으로 하며, 평균적으로 O(1)의 시간 복잡도를 제공한다. 그러나 최악의 경우, 모든 요소가 하나의 버킷에 모일 때 O(n)이 될 수 있다.

// 성능 차이의 주된 이유는 다음과 같다:
// - set은 트리 기반 구조로서 정렬된 상태를 유지하며, 원소 검색이 로그 시간 복잡도를 갖는다.
// - unordered_set은 해시 테이블을 사용하여 평균적으로 더 빠른 접근 시간을 제공하지만, 해시 충돌이 발생하면 성능이 저하될 수 있다.


int main() {
    const int NUM_ELEMENTS = 100000;  // 원소 수

    set<int> mySet;
    unordered_set<int> myUnorderedSet;

    // set에 대한 삽입 성능 측정
    auto start = high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        mySet.insert(i);
    }
    auto end = high_resolution_clock::now();
    auto durationSetInsert = duration_cast<milliseconds>(end - start);
    cout << "Insertion into set: " << durationSetInsert.count() << " ms" << endl;

    // unordered_set에 대한 삽입 성능 측정
    start = high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        myUnorderedSet.insert(i);
    }
    end = high_resolution_clock::now();
    auto durationUnorderedSetInsert = duration_cast<milliseconds>(end - start);
    cout << "Insertion into unordered_set: " << durationUnorderedSetInsert.count() << " ms" << endl;

    // set에 대한 검색 성능 측정
    start = high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        auto it = mySet.find(i);
    }
    end = high_resolution_clock::now();
    auto durationSetSearch = duration_cast<milliseconds>(end - start);
    cout << "Search in set: " << durationSetSearch.count() << " ms" << endl;

    // unordered_set에 대한 검색 성능 측정
    start = high_resolution_clock::now();
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        auto it = myUnorderedSet.find(i);
    }
    end = high_resolution_clock::now();
    auto durationUnorderedSetSearch = duration_cast<milliseconds>(end - start);
    cout << "Search in unordered_set: " << durationUnorderedSetSearch.count() << " ms" << endl;


    return 0;
}

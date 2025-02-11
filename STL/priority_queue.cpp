//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <queue>

using namespace std;

// priority_queue는 힙(기본적으로는 최대 힙)을 기반으로 한 STL 컨테이너입니다.
// - 가장 높은 우선순위를 가진 요소에 빠르게 접근할 수 있습니다.
// 좋은 사용 시기:
// - 데이터 중에서 가장 높은 (또는 낮은) 우선순위를 가진 요소에 빠르게 접근하고자 할 때.
// 성능 이슈:
// - 모든 요소를 정렬된 상태로 유지하는 것보다 우선순위 큐의 힙 구조가 더 효율적입니다.

int main() {

    // priority_queue 선언 (기본적으로 최대 힙)
    priority_queue<int> pq;

    // push: O(log n)
    pq.push(3);
    pq.push(1);
    pq.push(4);

    // top: O(1)
    cout << pq.top() << endl;  // 출력: 4 (가장 높은 우선순위)

    // pop: O(log n)
    pq.pop();

    // size: O(1)
    cout << pq.size() << endl;  // 출력: 2

    // 힙의 우선순위에 따라 순회 : O(n)
    while(!pq.empty()) {
        cout << pq.top() << " ";  // 출력: 3 1
        pq.pop();
    }
    cout << endl;

    // clear: priority_queue에는 clear 메서드가 없습니다. 대신, 새로운 빈 큐로 교체하는 방식을 사용할 수 있습니다.
    priority_queue<int> empty;
    swap(pq, empty);

    return 0;

}


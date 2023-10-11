//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <queue>

using namespace std;

// std::queue는 C++ STL에 포함된 컨테이너 어댑터입니다.
// - FIFO(First-In-First-Out) 원칙에 따라 동작하는 데이터 구조입니다.
// 좋은 사용 시기:
// - 데이터를 순서대로 처리해야 할 때, 예를 들면, 너비 우선 탐색(BFS) 알고리즘, 대기열 구현 등.
// 성능 이슈:
// - STL queue는 일반적으로 빠른 연산을 제공합니다. 하지만, 중간 요소에 직접 접근할 수 없습니다. 중간 요소를 검색하거나 수정하려면 다른 자료구조를 사용하는 것이 좋습니다.

int main() {

    queue<int> q;

    // push: 큐의 끝에 요소 추가, O(1)
    q.push(1);
    q.push(2);
    q.push(3);

    // front: 큐의 첫 번째 요소에 접근, O(1)
    cout << "Front element: " << q.front() << endl;  // 출력: Front element: 1

    // pop: 큐의 첫 번째 요소 제거, O(1)
    q.pop();
    cout << "Front element after pop: " << q.front() << endl;  // 출력: Front element after pop: 2

    // empty: 큐가 비어 있는지 확인, O(1)
    if (!q.empty()) {
        cout << "Queue is not empty" << endl;  // 출력: Queue is not empty
    }

    // size: 큐의 크기 확인, O(1)
    cout << "Queue size: " << q.size() << endl;  // 출력: Queue size: 2

    // 성능 저하 예제:
    // queue는 중간 요소에 직접 접근할 수 없으므로, 중간 요소를 검색하거나 수정하는 연산이 필요한 경우 
    // queue보다는 다른 자료 구조를 사용하는 것이 좋습니다.
   
    return 0;

}


//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <set>

using namespace std;

// set은 균형 이진 트리(Red-Black Tree)를 기반으로 한 STL 컨테이너입니다.
// - 모든 요소는 유일하며 정렬된 순서로 저장됩니다.
// 좋은 사용 시기:
// - 중복 없이 요소를 저장하고 싶을 때.
// - 요소가 항상 정렬된 상태로 유지되어야 할 때.
// 성능 이슈:
// - 연속된 메모리에 저장되지 않아 cache locality가 떨어집니다.
// - 단순히 중복 제거만 원하면 unordered_set이 더 빠를 수 있습니다.

int main() {

    // set 선언
    set<int> s;

    // insert: O(log n)
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(1); // 중복된 값은 추가되지 않습니다.

    // find: O(log n)
    auto it = s.find(3);
    if(it != s.end()) {
        cout << "Found: " << *it << endl;  // 출력: Found: 3
    }

    // erase: O(log n)
    s.erase(1);

    // size: O(1)
    cout << s.size() << endl;  // 출력: 2

    // 순회 (정렬된 순서대로): O(n)
    for(int num : s) {
        cout << num << " ";  // 출력: 3 4
    }
    cout << endl;

    // lower_bound & upper_bound: O(log n)
    // lower_bound는 주어진 값보다 크거나 같은 첫 번째 요소의 iterator를 반환합니다.
    it = s.lower_bound(3);
    if(it != s.end()) {
        cout << "Lower bound of 3: " << *it << endl;  // 출력: Lower bound of 3: 3
    }

    // upper_bound는 주어진 값보다 큰 첫 번째 요소의 iterator를 반환합니다.
    it = s.upper_bound(3);
    if(it != s.end()) {
        cout << "Upper bound of 3: " << *it << endl;  // 출력: Upper bound of 3: 4
    }

    // clear: O(n)
    s.clear();

    // 성능 저하 예제:
    // set은 원소의 삽입, 삭제, 검색에 log n의 시간이 걸립니다.
    // 연속적인 메모리 접근이 필요하거나, 중복만을 피하려는 경우에는 unordered_set을 사용하는 것이 더 효율적일 수 있습니다.
 
    return 0;

}


//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <unordered_set>

using namespace std;

// unordered_set은 해시 테이블을 기반으로 한 STL 컨테이너입니다.
// - 모든 요소는 유일합니다.
// - 내부적인 순서가 정의되어 있지 않습니다.
// 좋은 사용 시기:
// - 중복 없이 요소를 저장하고 싶을 때.
// - 내부 정렬 순서가 중요하지 않을 때.
// 성능 이슈:
// - 해시 충돌이 발생하면 성능이 떨어질 수 있습니다.

int main() {

    // unordered_set 선언
    unordered_set<int> us;

    // insert: O(1) 평균, O(n) 최악의 경우 (해시 충돌 시)
    us.insert(3);
    us.insert(1);
    us.insert(4);
    us.insert(1); // 중복된 값은 추가되지 않습니다.

    // find: O(1) 평균, O(n) 최악의 경우
    auto it = us.find(3);
    if(it != us.end()) {
        cout << "Found: " << *it << endl;  // 출력: Found: 3
    }

    // erase: O(1) 평균, O(n) 최악의 경우
    us.erase(1);

    // size: O(1)
    cout << us.size() << endl;  // 출력: 2

    // 순회 (정의된 순서가 없습니다): O(n)
    for(int num : us) {
        cout << num << " ";  // 출력: 3 4 (또는 4 3, 순서는 보장되지 않습니다.)
    }
    cout << endl;

    // clear: O(n)
    us.clear();

    return 0;
}


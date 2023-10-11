//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <unordered_map>

using namespace std;

// unordered_map은 해시 테이블을 기반으로 한 STL 컨테이너입니다.
// - 키는 정렬되지 않은 순서로 저장됩니다.
// - 각 키는 유일합니다.
// 좋은 사용 시기:
// - 키를 기준으로 데이터를 매우 빠르게 검색하고자 할 때.
// - 키의 정렬 순서가 중요하지 않을 때.
// 성능 이슈:
// - 해시 충돌이 발생하면 성능이 떨어질 수 있습니다.
// - 연속된 메모리에 데이터를 저장하지 않기 때문에 cache locality가 떨어집니다.

int main() {

    // unordered_map 선언
    unordered_map<string, int> um;

    // insert: O(1) 평균, O(n) 최악의 경우 (해시 충돌 시)
    um.insert(make_pair("apple", 100));
    um.insert({"banana", 200});

    // operator[]: O(1) 평균, O(n) 최악의 경우
    um["cherry"] = 300;

    // find: O(1) 평균, O(n) 최악의 경우
    auto it = um.find("banana");
    if(it != um.end()) {
        cout << "banana: " << it->second << endl;  // 출력: banana: 200
    }

    // erase: O(1) 평균, O(n) 최악의 경우
    um.erase("apple");

    // size: O(1)
    cout << um.size() << endl;   // 출력: 2

    // 순회: O(n)
    for(auto it = um.begin(); it != um.end(); ++it) {
        cout << it->first << ": " << it->second << endl;  // 출력: banana: 200, cherry: 300
    }

    // clear: O(n)
    um.clear();

    return 0;
}


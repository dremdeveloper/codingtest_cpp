//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <map>

using namespace std;

// map은 키-값 쌍을 저장하는 균형 이진 트리를 기반으로 한 STL 컨테이너입니다.
// - 키는 정렬된 순서로 저장됩니다.
// - 각 키는 유일합니다.
// 좋은 사용 시기:
// - 키를 기준으로 데이터를 빠르게 검색하고자 할 때.
// - 키-값 쌍의 삽입과 삭제가 정렬된 순서를 유지하면서 자주 발생할 때.
// 성능 이슈:
// - 연속된 메모리에 데이터를 저장하지 않기 때문에 cache locality가 떨어집니다.

int main() {

    // map 선언
    map<string, int> m;

    // insert: O(log n)
    m.insert(make_pair("apple", 100));
    m.insert({"banana", 200});

    // operator[]: O(log n)
    m["cherry"] = 300;

    // find: O(log n)
    auto it = m.find("banana");
    if(it != m.end()) {
        cout << "banana: " << it->second << endl;  // 출력: banana: 200
    }

    // erase: O(log n)
    m.erase("apple");

    // size: O(1)
    cout << m.size() << endl;   // 출력: 2

    // begin, end를 사용한 순회: O(n)
    for(auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second << endl;  // 출력: banana: 200, cherry: 300
    }

    // clear: O(n)
    m.clear();

    return 0;
}


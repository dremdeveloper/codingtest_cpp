//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // unordered_set 컨테이너 설명
    // - unordered_set은 중복을 허용하지 않는 순서가 없는 집합입니다.
    // - 원소는 해시 테이블로 관리되며, 자동으로 정렬되지 않습니다.
    // - 삽입, 삭제, 탐색 등의 주요 연산은 평균 O(1)의 시간복잡도를 가집니다.
    // - 최악의 경우, 해시 충돌로 인해 시간복잡도가 O(N)이 될 수 있습니다.

    // unordered_set을 사용해야 하는 경우:
    // - 중복되지 않는 값의 집합을 효율적으로 저장하고 관리해야 할 때.
    // - 원소의 순서가 중요하지 않을 때.
    // - 평균 O(1)의 시간복잡도를 갖는 빠른 삽입, 삭제, 탐색이 필요할 때.

    // unordered_set을 사용하지 말아야 하는 경우:
    // - 원소의 순서가 중요할 때 (이 경우 set을 사용).
    // - 해시 함수가 비효율적으로 동작하여 충돌이 많이 발생할 경우.
    // - 데이터의 크기가 매우 크고, 메모리 사용이 중요한 경우 (해시 테이블은 메모리 사용량이 많을 수 있음).

    // unordered_set 컨테이너 선언
    // value: int (학생 ID)
    unordered_set<int> studentSet;

    // 삽입: 학생 ID를 셋에 추가
    // insert 함수
    // 인자: 삽입할 값 (value)
    // 동작: 값이 존재하지 않으면 삽입
    // 시간복잡도: 평균 O(1), 최악 O(N)
    studentSet.insert(101);
    studentSet.insert(102);
    studentSet.insert(103);

    // 셋의 모든 요소 출력
    cout << "Initial unordered_set content:\n";
    for (const auto& value : studentSet) {
        cout << "ID: " << value << endl;
    }

    // 출력값:
    // Initial unordered_set content:
    // ID: 101
    // ID: 102
    // ID: 103

    // 탐색: 특정 ID가 셋에 있는지 찾기
    // find 함수
    // 인자: 찾을 값 (value)
    // 동작: 값이 존재하면 iterator 반환, 없으면 end() 반환
    // 시간복잡도: 평균 O(1), 최악 O(N)
    auto it = studentSet.find(102);
    if (it != studentSet.end()) {
        cout << "\nStudent with ID 102 found.\n";
    } else {
        cout << "\nStudent with ID 102 not found.\n";
    }

    // 출력값:
    // Student with ID 102 found.

    // 삭제: 특정 ID의 학생 정보 삭제
    // erase 함수
    // 인자: 삭제할 값 (value)
    // 동작: 값이 존재하면 해당 값을 삭제
    // 시간복잡도: 평균 O(1), 최악 O(N)
    studentSet.erase(101);
    cout << "\nAfter erasing ID 101:\n";
    for (const auto& value : studentSet) {
        cout << "ID: " << value << endl;
    }

    // 출력값:
    // After erasing ID 101:
    // ID: 102
    // ID: 103

    // [] 연산자는 unordered_set에서는 사용할 수 없음. 대신 find를 사용해야 함.
    // find 함수
    // 인자: 찾을 값 (value)
    // 동작: 값이 존재하면 iterator 반환, 없으면 end() 반환
    // 시간복잡도: 평균 O(1), 최악 O(N)
    it = studentSet.find(103);
    if (it != studentSet.end()) {
        cout << "\nStudent with ID 103 found: " << *it << endl;
    } else {
        cout << "\nStudent with ID 103 not found.\n";
    }

    // 출력값:
    // Student with ID 103 found: 103

    return 0;
}


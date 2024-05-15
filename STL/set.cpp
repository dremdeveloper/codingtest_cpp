//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    // 초기화
    std::set<int> s;

    // insert: 원소 삽입
    // 시간복잡도: O(log N)
    s.insert(10);  // {10}
    s.insert(20);  // {10, 20}
    s.insert(10);  // {10, 20} (중복된 값은 삽입되지 않음)

    // find: 원소 탐색
    // 시간복잡도: O(log N)
    auto it = s.find(10); // 10을 가리키는 반복자 반환
    if (it != s.end()) {
        std::cout << "Found: " << *it << std::endl; // 출력: Found: 10
    } else {
        std::cout << "Not Found" << std::endl;
    }

    // erase: 원소 삭제
    // 시간복잡도: O(log N)
    s.erase(10); // {20}

    // find 메서드를 사용하여 삭제된 원소를 찾으려 하면
    it = s.find(10);
    if (it != s.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not Found" << std::endl; // 출력: Not Found
    }

    // set을 사용해야 하는 경우
    // 1. 중복을 허용하지 않는 경우
    // 예: 유일한 사용자 ID를 저장하는 경우
    std::set<int> uniqueIds;
    uniqueIds.insert(1);
    uniqueIds.insert(2);
    uniqueIds.insert(1); // 중복 삽입 무시
    for (int id : uniqueIds) {
        std::cout << "User ID: " << id << std::endl; // 출력: User ID: 1, User ID: 2
    }

    // 2. 정렬된 순서가 필요한 경우
    // 예: 정렬된 데이터가 필요한 상황
    std::set<int> sortedData;
    sortedData.insert(5);
    sortedData.insert(1);
    sortedData.insert(3);
    for (int val : sortedData) {
        std::cout << "Sorted Value: " << val << std::endl; // 출력: Sorted Value: 1, 3, 5
    }

    // 3. 탐색, 삽입, 삭제의 성능이 중요한 경우
    // 예: 데이터의 존재 여부를 빈번히 검사해야 하는 경우
    std::set<int> dataSet;
    dataSet.insert(15);
    if (dataSet.find(15) != dataSet.end()) {
        std::cout << "15 is in the set" << std::endl;
    }

    // set을 사용하지 말아야 하는 경우
    // 1. 중복된 원소를 허용해야 하는 경우
    // 예: 동일한 값을 여러 번 저장해야 하는 경우
    std::multiset<int> multiSet;
    multiSet.insert(10);
    multiSet.insert(10); // 중복된 값도 저장됨
    std::cout << "Multiset contains " << multiSet.count(10) << " instances of 10" << std::endl;

    // 2. 정렬이 필요 없는 경우
    // 예: 순서가 중요하지 않고 단순히 데이터를 저장하고자 하는 경우
    std::vector<int> vec = {5, 3, 8, 1};
    vec.push_back(10);
    std::cout << "Vector: ";
    for (int v : vec) {
        std::cout << v << " "; // 출력: Vector: 5 3 8 1 10
    }
    std::cout << std::endl;

    // 3. O(1) 시간 복잡도가 필요한 경우
    // 예: 빈번한 삽입과 삭제가 필요한 경우
    std::unordered_set<int> unorderedSet;
    unorderedSet.insert(5);
    unorderedSet.insert(10);
    unorderedSet.erase(5);
    if (unorderedSet.find(10) != unorderedSet.end()) {
        std::cout << "10 is in the unordered set" << std::endl;
    }

    return 0;
}



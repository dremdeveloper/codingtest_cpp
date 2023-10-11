//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// std::max_element는 C++ STL의 algorithm 헤더에 포함된 최대 요소 검색 함수입니다.
// - 주어진 범위 내에서 최대 값을 가진 요소의 반복자를 반환합니다.
// 좋은 사용 시기:
// - 배열이나 컨테이너에서 최대 값을 가진 요소를 찾고 싶을 때.
// 성능 이슈:
// - max_element는 선형 시간 복잡도를 갖는 알고리즘입니다. 대규모 데이터에서는 성능 저하가 발생할 수 있습니다.

int main() {

    vector<int> v = {1, 3, 7, 2, 5, 9, 4};

    // 기본 동작: 범위 내 최대 값을 가진 요소 찾기, O(n)
    auto it = max_element(v.begin(), v.end());
    if(it != v.end()) {
        cout << "Max element: " << *it << endl;  // 출력: Max element: 9
    }

    // 사용자 정의 비교 함수를 사용하여 최소 요소 찾기
    auto minIt = max_element(v.begin(), v.end(), [](int a, int b) {
        return a > b;  // 반대로 비교
    });
    if(minIt != v.end()) {
        cout << "Min element using custom comparator: " << *minIt << endl;  // 출력: Min element using custom comparator: 1
    }

    // 성능 저하 예제:
    // max_element는 모든 요소를 확인하기 때문에 대규모 데이터에서는 시간이 오래 걸릴 수 있습니다.
    // 필요한 경우, 데이터의 구조를 최적화하거나 다른 알고리즘/자료구조를 사용하여 성능을 향상시킬 수 있습니다.
}


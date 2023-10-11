//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이진 탐색은 정렬된 배열이나 컨테이너에서 특정 값을 빠르게 찾는 알고리즘입니다.
// - 이진 탐색은 로그 시간 복잡도를 가지며, 정렬된 데이터에서 특정 값을 빠르게 찾을 때 사용됩니다.
// 좋은 사용 시기:
// - 큰 데이터셋에서 특정 값이 포함되어 있는지 빠르게 확인하거나, 특정 값의 위치를 찾을 때.

int main() {

    vector<int> v = {1, 3, 4, 5, 9, 10};

    // binary_search: 범위 내에서 값의 존재 확인, O(log n)
    bool found = binary_search(v.begin(), v.end(), 5);
    cout << (found ? "5 is in the vector." : "5 is not in the vector.") << endl;  // 출력: 5 is in the vector.

    // lower_bound: 값이 들어갈 수 있는 첫 번째 위치의 이터레이터 반환, O(log n)
    auto lb = lower_bound(v.begin(), v.end(), 5);
    cout << "5 would get inserted at index: " << (lb - v.begin()) << endl;  // 출력: 5 would get inserted at index: 3

    // upper_bound: 값보다 큰 첫 번째 위치의 이터레이터 반환, O(log n)
    auto ub = upper_bound(v.begin(), v.end(), 5);
    cout << "First element greater than 5 is at index: " << (ub - v.begin()) << endl;  // 출력: First element greater than 5 is at index: 4

    // 성능 저하 예제:
    // 데이터가 정렬되어 있지 않으면 이진 탐색은 올바른 결과를 반환하지 않을 수 있습니다.
    vector<int> unsorted = {10, 1, 9, 5, 3, 4};
    found = binary_search(unsorted.begin(), unsorted.end(), 5);  // 이 경우에는 정확한 결과를 기대하기 어렵습니다.

    return 0;
}


//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// std::sort는 C++ STL의 algorithm 헤더에 포함된 정렬 함수입니다.
// - 일반적으로 빠른 정렬 알고리즘을 구현하고 있습니다.
// 좋은 사용 시기:
// - 배열이나 컨테이너의 요소를 빠르게 정렬할 때.
// 성능 이슈:
// - 대부분의 경우 빠르게 동작하지만, 특정 데이터 패턴에서 성능 저하가 발생할 수 있습니다.

int main() {

    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

    // 기본 정렬: 오름차순, O(n log n) 
    sort(v.begin(), v.end());
    for(int i : v) cout << i << " ";  // 출력: 1 1 2 3 4 5 6 9
    cout << endl;

    // 사용자 정의 비교 함수를 사용하여 내림차순 정렬
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });
    for(int i : v) cout << i << " ";  // 출력: 9 6 5 4 3 2 1 1
    cout << endl;

    // partial_sort: 일부만 정렬, O(n log m) 
    // 여기서 m은 [v.begin(), v.begin() + 3) 범위의 길이
    partial_sort(v.begin(), v.begin() + 3, v.end());
    for(int i : v) cout << i << " ";  // 출력: 1 1 2 9 6 5 4 3
    cout << endl;

    return 0;
}


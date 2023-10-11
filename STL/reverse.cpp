//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// std::reverse는 C++ STL의 algorithm 헤더에 포함된 순서 반전 함수입니다.
// - 주어진 범위의 요소 순서를 반대로 만듭니다.
// 좋은 사용 시기:
// - 배열이나 컨테이너의 요소 순서를 반전하고 싶을 때.
// 성능 이슈:
// - reverse는 선형 시간 복잡도를 갖는 알고리즘입니다. 대부분의 사용 사례에서 효율적으로 동작합니다.

int main() {

    vector<int> v = {1, 2, 3, 4, 5};

    // 기본 동작: 범위 내 요소의 순서 반전, O(n)
    reverse(v.begin(), v.end());
    for(int i : v) cout << i << " ";  // 출력: 5 4 3 2 1
    cout << endl;

    // 부분 범위의 요소 순서 반전
    reverse(v.begin() + 1, v.end() - 1);
    for(int i : v) cout << i << " ";  // 출력: 5 2 3 4 1
    cout << endl;

    // 성능 저하 예제:
    // reverse는 일반적으로 선형 시간 내에 완료되므로 성능 저하를 걱정할 필요가 적습니다.
    // 그러나 매우 큰 데이터 셋에서는 다른 연산과 결합될 때 성능에 영향을 줄 수 있습니다.
   
    return 0;

}


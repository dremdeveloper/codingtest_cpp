//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// std::count는 C++ STL의 algorithm 헤더에 포함된 요소 계산 함수입니다.
// - 주어진 범위 내에서 특정 값을 가진 요소의 개수를 반환합니다.
// 좋은 사용 시기:
// - 배열이나 컨테이너에서 특정 값의 개수를 알고 싶을 때.
// 성능 이슈:
// - count는 선형 시간 복잡도를 갖는 알고리즘입니다. 대규모 데이터에서는 성능 저하가 발생할 수 있습니다.

// 조건 함수: 짝수를 확인하는 함수
bool isEven(int i) {
    return i % 2 == 0;
}

int main() {

    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 3, 3};

    // 기본 동작: 범위 내에서 값 3의 개수 계산, O(n)
    int cnt = count(v.begin(), v.end(), 3);
    cout << "Number of 3s: " << cnt << endl;  // 출력: Number of 3s: 3

    // count_if: 조건에 맞는 요소의 개수 계산, O(n)
    int evenCount = count_if(v.begin(), v.end(), isEven);
    cout << "Number of even numbers: " << evenCount << endl;  // 출력: Number of even numbers: 3

    return 0;
}


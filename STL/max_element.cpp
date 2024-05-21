//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element
using namespace std;

int main() {
    // 예시 벡터 생성
    vector<int> v = {1, 3, 4, 5, 7, 9, 10};

    // 최대값 찾기
    auto max_it = max_element(v.begin(), v.end());

    // 결과 출력
    cout << "최대값: " << *max_it << " (위치: " << distance(v.begin(), max_it) << ")" << endl;

    return 0;
}

/*
출력값:

최대값: 10 (위치: 6)
*/

// max_element에 대한 설명
/*
std::max_element 함수는 주어진 범위에서 가장 큰 요소를 찾는 데 사용됩니다.
이 함수는 선형 탐색 알고리즘을 사용하여 값을 찾습니다.

설명:
1. 반환값: 가장 큰 값을 가리키는 반복자를 반환합니다.
   반환된 반복자를 사용하여 해당 값에 접근할 수 있습니다.
2. 범위: 시작 반복자와 끝 반복자를 인자로 받아, 이 범위 내에서 탐색을 수행합니다.

시간복잡도:
- std::max_element 함수의 시간복잡도는 O(N)입니다. 여기서 N은 범위 내의 요소 수입니다.

예제:
벡터가 {1, 3, 4, 5, 7, 9, 10}로 주어졌을 때,
max_element(v.begin(), v.end())를 호출하면 반복자가 10을 가리킵니다.
*/



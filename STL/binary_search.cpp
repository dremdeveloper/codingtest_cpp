//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm> // for std::binary_search and std::sort
using namespace std;

int main() {
    // 예시 벡터 생성
    vector<int> v = {1, 3, 4, 5, 7, 9, 10};

    // 찾고자 하는 값
    int value1 = 5;
    int value2 = 6;

    // 이진 탐색 사용 예시
    bool found1 = binary_search(v.begin(), v.end(), value1);
    bool found2 = binary_search(v.begin(), v.end(), value2);

    // 결과 출력
    cout << "값 " << value1 << "를 찾는 중: " << (found1 ? "찾음" : "찾지 못함") << endl;
    cout << "값 " << value2 << "를 찾는 중: " << (found2 ? "찾음" : "찾지 못함") << endl;

    return 0;
}

/*
출력값:

값 5를 찾는 중: 찾음
값 6를 찾는 중: 찾지 못함
*/

// binary_search에 대한 설명
/*
std::binary_search 함수는 정렬된 범위에서 특정 값을 찾는 데 사용됩니다.
이진 탐색 알고리즘을 사용하여 값의 존재 여부를 확인합니다.

주의해야 할 점:
1. 정렬된 상태에서 사용: binary_search 함수는 정렬된 범위에서만 올바르게 동작합니다.
   정렬되지 않은 범위에서 사용하면 결과가 올바르지 않습니다.
2. 반환값: 찾고자 하는 값이 존재하면 true를 반환하고, 존재하지 않으면 false를 반환합니다.

시간복잡도:
- std::binary_search 함수의 시간복잡도는 O(log N)입니다. 여기서 N은 범위 내의 요소 수입니다.

예제:
벡터가 {1, 3, 4, 5, 7, 9, 10}로 주어졌을 때,
binary_search(v.begin(), v.end(), 5)를 호출하면 true를 반환하고,
binary_search(v.begin(), v.end(), 6)를 호출하면 false를 반환합니다.
*/


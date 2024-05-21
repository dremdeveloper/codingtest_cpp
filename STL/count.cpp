//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm> // for std::count
using namespace std;

int main() {
    // 예시 벡터 생성
    vector<int> v = {1, 2, 3, 4, 5, 1, 2, 1};

    // count 함수 사용 예시
    // std::count 함수는 주어진 범위에서 특정 값이 몇 번 나타나는지 센다.
    // 여기서 v.begin()과 v.end()는 벡터의 시작과 끝을 나타내며,
    // 1은 찾고자 하는 값이다.
    int count_of_1 = count(v.begin(), v.end(), 1);

    // 결과 출력
    cout << "벡터에서 1의 개수: " << count_of_1 << endl;

    // 출력값:
    // 벡터에서 1의 개수: 3

    // 시간 복잡도:
    // std::count 함수의 시간 복잡도는 O(N)이다.
    // 여기서 N은 주어진 범위의 요소 수를 나타낸다.

    // count 함수를 사용해야 하는 경우
    // 데이터 집합에서 특정 값의 출현 빈도를 알고 싶을 때 유용하다.
    // 예를 들어, 설문조사 결과에서 특정 답변이 몇 번 나왔는지 확인할 때 사용할 수 있다.

    return 0;
}


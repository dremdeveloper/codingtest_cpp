//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>

int main() {
    // C++의 vector는 동적 배열을 구현한 컨테이너입니다.
    // 연속된 메모리 위치에 데이터를 저장하기 때문에 랜덤 액세스가 가능하며, O(1)의 시간복잡도를 갖습니다.
    // 배열과 비슷하지만, 크기가 동적으로 변경될 수 있습니다.
    // 주로 알려진 크기가 없고, 자주 수정되지 않는 데이터를 저장할 때 사용됩니다.

    // vector의 선언
    std::vector<int> vec;

    // push_back: O(1) 평균, O(n) 최악의 경우 (재할당이 필요할 때)
    // 맨 뒤에 요소 추가
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // [] operator: O(1)
    // 랜덤 액세스
    std::cout << vec[1] << std::endl;  // 출력: 2

    // at: O(1)
    // 랜덤 액세스, 범위를 검사
    std::cout << vec.at(2) << std::endl;  // 출력: 3

    // front: O(1)
    // 첫 번째 요소 액세스
    std::cout << vec.front() << std::endl;  // 출력: 1

    // back: O(1)
    // 마지막 요소 액세스
    std::cout << vec.back() << std::endl;   // 출력: 3

    // size: O(1)
    // 벡터의 크기 반환
    std::cout << vec.size() << std::endl;   // 출력: 3

    // pop_back: O(1)
    // 마지막 요소 제거
    vec.pop_back();

    // resize: O(n)
    // 벡터 크기 조절. 필요한 경우 값을 채워 넣거나 기존 값 삭제
    vec.resize(5, 100);  // {1, 2, 100, 100, 100}

    // clear: O(n)
    // 모든 요소 제거
    vec.clear();

    // 성능 이슈:
    // 1. 벡터의 중간에 요소를 삽입하거나 제거할 경우, O(n)의 시간복잡도를 갖게 되며 성능 저하가 발생할 수 있습니다.
    // 예:
    // vec.insert(vec.begin() + 1, 100);  // 두 번째 위치에 100 삽입
    // vec.erase(vec.begin());            // 첫 번째 요소 제거

    // 2. 벡터가 자주 재할당되면 (즉, push_back을 자주 호출하여 벡터의 용량을 초과하면) 성능 저하가 발생할 수 있습니다.
    // 이를 피하기 위해 reserve 메서드를 사용하여 미리 메모리를 할당해두는 것이 좋습니다.
    // 예:
    // vec.reserve(1000);

    return 0;
}


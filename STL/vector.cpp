//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 벡터 초기화 방법 1: 기본 생성자
    vector<int> vec1;  // 빈 벡터 선언: vec1 = {}

    // 벡터 초기화 방법 2: 크기 지정, 모든 원소 0으로 초기화
    vector<int> vec2(5);  // vec2 = {0, 0, 0, 0, 0}

    // 벡터 초기화 방법 3: 크기와 초기값 지정
    vector<int> vec3(5, 1);  // vec3 = {1, 1, 1, 1, 1}

    // 벡터 초기화 방법 4: 초기화 리스트 사용
    vector<int> vec4 = {1, 2, 3, 4, 5};  // vec4 = {1, 2, 3, 4, 5}

    // 벡터 초기화 방법 5: 다른 벡터로부터 초기화
    vector<int> vec5(vec4);  // vec5 = {1, 2, 3, 4, 5}

    // 벡터 초기화 방법 6: 다른 벡터의 부분 범위로부터 초기화
    vector<int> vec6(vec4.begin() + 1, vec4.end() - 1);  // vec6 = {2, 3, 4}

    // 벡터 메서드 예시
    vector<int> vec;

    // push_back: 벡터의 끝에 원소를 추가합니다.
    // vec.push_back(값)
    // 벡터의 맨 끝에 '값'을 추가합니다.
    // 시간복잡도: 평균 O(1)
    vec.push_back(10);  // vec = {10}
    vec.push_back(20);  // vec = {10, 20}
    vec.push_back(30);  // vec = {10, 20, 30}

    // pop_back: 벡터의 마지막 원소를 제거합니다.
    // vec.pop_back()
    // 벡터의 맨 끝에 있는 원소를 제거합니다.
    // 시간복잡도: O(1)
    vec.pop_back();  // vec = {10, 20}

    // insert: 지정한 위치에 원소를 삽입합니다.
    // vec.insert(위치, 값)
    // '위치'에 '값'을 삽입합니다. '위치'는 반복자로 지정합니다.
    // vec.begin()은 첫 번째 원소를 가리킵니다.
    // vec.begin() + 1은 두 번째 원소를 가리킵니다.
    // 시간복잡도: O(n)
    vec.insert(vec.begin() + 1, 15);  // vec = {10, 15, 20}

    // erase: 지정한 위치의 원소를 제거합니다.
    // vec.erase(위치)
    // '위치'의 원소를 제거합니다. '위치'는 반복자로 지정합니다.
    // vec.begin()은 첫 번째 원소를 가리킵니다.
    // 시간복잡도: O(n)
    vec.erase(vec.begin());  // vec = {15, 20}

    // size: 벡터의 크기를 반환합니다.
    // vec.size()
    // 현재 벡터에 저장된 원소의 개수를 반환합니다.
    // 시간복잡도: O(1)
    cout << "Size of vector: " << vec.size() << endl;  // 출력: Size of vector: 2

    // vector를 사용해야 하는 경우
    // 1. 동적 배열이 필요한 경우
    // 예: 프로그램 실행 중에 배열의 크기를 변경해야 하는 경우
    vector<int> dynamicArray;
    for (int i = 0; i < 10; ++i) {
        dynamicArray.push_back(i * 2);  // {0, 2, 4, 6, 8, 10, 12, 14, 16, 18}
    }
    cout << "Dynamic array: ";
    for (int v : dynamicArray) {
        cout << v << " ";
    }
    cout << endl;

    // 2. 임의 접근이 필요한 경우
    // 예: 특정 인덱스에 빠르게 접근해야 하는 경우
    cout << "Third element: " << dynamicArray[2] << endl;  // 출력: Third element: 4

    // 3. 데이터의 크기가 자주 바뀌는 경우
    // 예: 데이터의 추가와 삭제가 빈번하게 발생하는 경우
    vector<int> flexibleArray;
    flexibleArray.push_back(1); // {1}
    flexibleArray.push_back(2); // {1, 2}
    flexibleArray.pop_back();   // {1}

    // vector를 사용하지 말아야 하는 경우
    // 1. 값을 자주 찾아야 할 때
    // 예: 원소의 존재 여부를 자주 검사해야 하는 경우에는 비효율적
    // 대안: std::set 또는 std::unordered_set 사용
    vector<int> searchVector = {1, 2, 3, 4, 5};
    if (find(searchVector.begin(), searchVector.end(), 3) != searchVector.end()) {
        cout << "3 is in the vector" << endl;
    }

    // 2. 맨 앞에 원소를 추가해야 할 때
    // 예: 벡터의 맨 앞에 원소를 자주 삽입해야 하는 경우에는 비효율적
    // 대안: std::deque 또는 std::list 사용
    vector<int> inefficientFrontInsert = {1, 2, 3, 4, 5};
    inefficientFrontInsert.insert(inefficientFrontInsert.begin(), 0); // {0, 1, 2, 3, 4, 5}

    return 0;
}

//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm> // sort() 함수가 포함된 헤더

// 사용자 정의 비교 함수
bool compare(int a, int b) {
    // 내림차순 정렬을 위한 비교: a가 b보다 클 때 true를 반환
    // sort 함수가 비교 시 compare(a, b)가 true를 반환하면 a가 b보다 앞에 있어야 한다고 판단하여 a와 b의 위치를 교환하지 않음
    return a > b;
}

int main() {
    // 정렬할 벡터 생성
    std::vector<int> v = {5, 2, 9, 1, 5, 6};

    // 벡터를 오름차순으로 정렬
    // std::sort는 기본적으로 < 연산자를 사용하여 정렬
    // v.begin()은 첫 번째 요소, v.end()는 마지막 요소의 다음 위치를 가리킴 (v.end()는 정렬 대상에 포함되지 않음)
    std::sort(v.begin(), v.end());

    // 오름차순으로 정렬된 벡터 출력
    std::cout << "오름차순 정렬: ";
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    // 출력값: 1 2 5 5 6 9

    // 벡터를 다시 섞어서 초기 상태로 되돌림
    v = {5, 2, 9, 1, 5, 6};

    // 벡터를 사용자 정의 비교 함수로 정렬 (내림차순)
    // std::sort는 compare 함수가 true를 반환할 때 첫 번째 요소가 두 번째 요소보다 앞에 있어야 한다고 판단
    // compare 함수는 a > b일 때 true를 반환하므로, 큰 값이 작은 값 앞에 오게 되어 내림차순 정렬이 이루어짐
    std::sort(v.begin(), v.end(), compare);

    // 내림차순으로 정렬된 벡터 출력
    std::cout << "내림차순 정렬: ";
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    // 출력값: 9 6 5 5 2 1

    // 벡터를 다시 섞어서 초기 상태로 되돌림
    v = {5, 2, 9, 1, 5, 6};

    // 벡터의 앞 3개 요소만 오름차순으로 정렬
    // v.begin()에서 v.begin() + 3까지 정렬
    // 정렬 범위: [5, 2, 9] (v.begin() + 3는 정렬 대상에 포함되지 않음)
    std::sort(v.begin(), v.begin() + 3);

    // 부분 정렬된 벡터 출력
    std::cout << "부분 정렬 (앞 3개 요소 오름차순): ";
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    // 출력값: 2 5 9 1 5 6

    // 벡터를 다시 섞어서 초기 상태로 되돌림
    v = {5, 2, 9, 1, 5, 6};

    // 역방향 반복자를 사용하여 벡터를 내림차순으로 정렬
    // v.rbegin()은 마지막 요소, v.rend()는 첫 번째 요소의 이전 위치를 가리킴 (v.rend()는 정렬 대상에 포함되지 않음)
    std::sort(v.rbegin(), v.rend());

    // 역방향으로 정렬된 벡터 출력
    std::cout << "역방향 반복자로 정렬 (내림차순): ";
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    // 출력값: 9 6 5 5 2 1

    return 0;
}



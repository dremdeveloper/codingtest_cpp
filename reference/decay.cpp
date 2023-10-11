//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <type_traits>  // decay를 사용하기 위해 포함

using namespace std;

void printSize(int* ptr) {
    // 배열이 함수로 전달될 때 decay되어 포인터 크기만을 가지게 된다.
    cout << "함수 내에서 ptr의 크기: " << sizeof(ptr) << endl;
}

int main() {
    // 1. Decay란?
    // Decay는 특정 타입이 다른 상황에서 다른 타입으로 암시적으로 변환되는 것을 의미합니다.
    // 가장 일반적인 예는 배열 이름이 포인터로 변환되는 것과 함수 이름이 함수 포인터로 변환되는 것입니다.

    int arr[5] = {1, 2, 3, 4, 5};

    // 배열의 이름 'arr'은 주소로 해석되며 포인터로 decay됩니다.
    int* ptr = arr; 

    cout << "arr[0]: " << arr[0] << " *ptr: " << *ptr << endl; // arr[0]: 1 *ptr: 1
    cout << "arr의 크기: " << sizeof(arr) << endl; // arr의 크기: 20 (int가 4바이트라 가정)

    printSize(arr); // 함수 내에서 ptr의 크기: 8 (64비트 머신에서 포인터 크기는 8바이트)

    // 2. `std::decay`
    // `std::decay`는 주어진 타입의 가장 적절한 decayed 버전을 반환합니다.
    // 주로 템플릿 메타프로그래밍에서 사용됩니다.

    bool isSame = is_same<decltype(arr), decay<decltype(arr)>::type>::value;
    cout << "배열 타입이 decay 후에 동일한가요? " << (isSame ? "네" : "아니요") << endl;  // 아니요

    // 주의사항:
    // 배열이 포인터로 decay되면 원래 배열의 크기 정보를 잃게 됩니다.
    // 따라서 decay된 포인터만 가지고는 원래 배열의 크기를 알 수 없습니다.

    return 0;
}

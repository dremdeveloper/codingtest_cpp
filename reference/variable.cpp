//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>

using namespace std;

int main() {
    // 1. 기본 데이터 타입 변수
    int a = 10;        // 정수형 변수
    double b = 20.5;   // 실수형 변수
    char c = 'A';      // 문자형 변수
    bool d = true;     // 불리언 변수 (참/거짓)

    /* 
    변수란?
    - 변수는 메모리상에 값을 저장하는 공간을 의미합니다.
    - 변수를 선언할 때는 해당 변수의 타입을 지정해야 하며, 그 타입에 따라 저장할 수 있는 값의 종류와 크기가 결정됩니다.
    - 변수는 프로그램 내에서 데이터를 저장하고 참조하기 위해 사용됩니다.
    */

    // 2. 변수의 초기화
    int uninitialized;     // 초기화되지 않은 변수
    int initialized = 100; // 초기값을 가진 변수

    /* 
    주의사항:
    - 초기화되지 않은 변수는 그 안에 쓰레기 값이 들어있을 수 있으므로 사용하기 전에 반드시 초기화하는 것이 좋습니다.
    - C++에서는 변수를 선언하면서 동시에 초기화할 수 있습니다. 이렇게 하면 나중에 실수로 초기화를 잊어버리는 문제를 예방할 수 있습니다.
    */

    cout << "Value of a: " << a << endl;        // 출력: 10
    cout << "Value of b: " << b << endl;        // 출력: 20.5
    cout << "Value of c: " << c << endl;        // 출력: A
    cout << "Value of d: " << d << endl;        // 출력: 1 (true는 1로, false는 0으로 출력됩니다.)
}


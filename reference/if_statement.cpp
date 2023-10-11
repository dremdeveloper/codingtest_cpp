//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int b = 20;

    /* 
    if문이란?
    - 조건을 평가하여 그 결과가 true일 때 코드 블럭을 실행하는 제어문입니다.
    - 조건은 괄호 안에 작성되며, 조건 결과가 참이면 괄호 다음의 코드 블럭이 실행됩니다.
    */
    if (a < b) {
        cout << "a is less than b." << endl;  // 출력: a is less than b.
    }

    /* 
    if-else문이란?
    - 조건을 평가하여 결과가 true일 때와 false일 때 각각 다른 코드 블럭을 실행하는 제어문입니다.
    - if의 조건이 참이면 if의 코드 블럭을, 거짓이면 else의 코드 블럭을 실행합니다.
    */
    if (a > b) {
        cout << "a is greater than b." << endl;
    } else {
        cout << "a is not greater than b." << endl;  // 출력: a is not greater than b.
    }

    /* 
    if-else if-else문이란?
    - 여러 조건 중 하나를 평가하여 해당 조건에 맞는 코드 블럭을 실행하는 제어문입니다.
    - 조건은 위에서부터 차례대로 평가되며, 첫 번째로 참인 조건의 코드 블럭만 실행됩니다.
    */
    int c = 10;
    if (c > b) {
        cout << "c is greater than b." << endl;
    } else if (c == a) {
        cout << "c is equal to a." << endl;  // 출력: c is equal to a.
    } else {
        cout << "c is neither greater than b nor equal to a." << endl;
    }

    /* 
    주의사항:
    1. 조건문 내에서 변수의 값이 변경되지 않도록 주의해야 합니다.
    예:
    if (a = b) { ... }  // 이렇게 쓰면 a에 b의 값을 할당하게 되어 항상 참으로 평가됩니다.
    올바르게는 if (a == b) { ... } 와 같이 써야 합니다.

    2. 조건문을 너무 복잡하게 중첩하지 않도록 주의합니다. 
    너무 많은 중첩은 코드를 읽기 어렵게 만듭니다.

    3. 비교 연산자와 논리 연산자를 혼동하지 않도록 주의해야 합니다.
    예: if (a & b) { ... }  // 이렇게 쓰면 a와 b의 비트 연산을 수행합니다.
    올바르게는 if (a && b) { ... } 와 같이 논리 연산자를 사용해야 합니다.
    */

    return 0;
}

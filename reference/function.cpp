//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>

using namespace std;

// 함수 정의의 기본 구조
// 반환형 함수명(매개변수 목록) {
//     함수 본문
//     return 반환값;
// }

/* 
함수(Function)이란?
- 함수는 특정 작업을 수행하는 코드 블록의 모음입니다.
- 코드의 재사용성을 높이고, 프로그램의 구조를 체계적으로 만들어 주며, 디버깅을 용이하게 합니다.
- 함수는 반환형, 함수명, 매개변수 목록, 함수 본문으로 구성됩니다.
*/

// 반환형이 void인 경우, 함수는 값을 반환하지 않습니다.
void sayHello() {
    cout << "Hello, World!" << endl;
}

// 매개변수로 값을 받아서 처리할 수 있습니다.
void displayNumber(int num) {
    cout << "Number: " << num << endl;
}

// 함수는 값을 반환할 수 있습니다.
int add(int a, int b) {
    return a + b;
}

// 함수의 오버로딩: 같은 이름을 가진 함수를 여러 개 정의하는 것. 매개변수의 타입이나 개수가 달라야 합니다.
void show(double d) {
    cout << "Double: " << d << endl;
}

void show(int i) {
    cout << "Int: " << i << endl;
}

/* 
주의사항:
1. 함수의 선언(프로토타입)과 정의는 다릅니다. 선언은 함수의 원형만을 나타내며, 정의는 함수의 실제 동작을 구현합니다.
2. 함수를 호출하기 전에 함수가 선언되어 있어야 합니다.
3. 값을 전달받는 매개변수는 함수 내에서 값이 변경되더라도 원래 변수에는 영향을 미치지 않습니다.
*/

int main() {
    sayHello();  // 출력: Hello, World!

    displayNumber(5);  // 출력: Number: 5

    int result = add(3, 4);
    cout << "Sum: " << result << endl;  // 출력: Sum: 7

    show(5);     // 출력: Int: 5
    show(3.14);  // 출력: Double: 3.14

    return 0;
}

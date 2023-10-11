#include <iostream>

using namespace std;

/* 
콜백함수 (Callback Function):
- 다른 함수의 인자로 전달되는 함수를 의미합니다.
- 주로 어떤 이벤트가 발생했을 때 호출될 함수를 등록해두거나, 특정 알고리즘에서 사용자 정의 연산을 제공할 때 활용됩니다.
*/

// 콜백함수로 사용될 함수 예시
void myCallbackFunction(int data) {
    cout << "Callback function called with value: " << data << endl;
}

// 콜백함수를 인자로 받는 함수
//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
void process(int value, void (*callbackFunc)(int)) {
    // 어떤 처리를 한 후에
    // 콜백함수를 호출한다.
    callbackFunc(value);
}

int main() {
    cout << "Starting program..." << endl;

    // process 함수 호출 시, myCallbackFunction를 콜백 함수로 전달
    process(5, myCallbackFunction);

    cout << "Ending program..." << endl;

    return 0;
}

/* 
주의사항:
1. 콜백함수는 함수 포인터 형태로 전달되므로, 함수 포인터의 문법과 관련된 오류에 주의해야 합니다.
2. 콜백함수 내에서 전역 상태나 외부 변수를 변경할 때는 사이드 이펙트를 주의해야 합니다.
3. 잦은 호출이 필요한 경우에는 콜백의 오버헤드로 인한 성능 저하가 발생할 수 있습니다.
*/


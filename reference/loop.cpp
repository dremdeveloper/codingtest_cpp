//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>

using namespace std;

int main() {
    // 1. for 문: 초기식, 조건식, 증감식을 가지는 반복문.
    // 초기식을 실행한 후, 조건식이 참일 경우 반복문 내의 코드를 실행하고, 증감식을 실행한다.
    // 조건식이 거짓이 될 때까지 이 과정을 반복한다.
    for (int i = 0; i < 5; ++i) {
        cout << "For loop, iteration " << i + 1 << endl;
    }
    cout << endl;

    // 2. while 문: 조건식만을 가지는 반복문.
    // 조건식이 참일 경우 반복문 내의 코드를 실행한다.
    // 조건식이 거짓이 될 때까지 이 과정을 반복한다.
    int j = 0;
    while (j < 3) {
        cout << "While loop, iteration " << j + 1 << endl;
        j++;
    }
    cout << endl;

    // 3. do-while 문: 조건식을 루프의 끝에서 평가하는 반복문.
    // 루프 내의 코드를 최소한 한 번은 실행한다. 이후에 조건식을 평가한다.
    int k = 0;
    do {
        cout << "Do-while loop, iteration " << k + 1 << endl;
        k++;
    } while (k < 2);
    cout << endl;

    // 주의사항:
    // 1. 무한 루프에 빠질 위험이 있으므로 조건식을 잘 설정해야 합니다.
    // 예: for(;;) 또는 while(true)
    
    // 2. 반복문 내에서 조건변수의 값을 바꾸면 예기치 않은 결과가 발생할 수 있습니다.
    for (int l = 0; l < 5; ++l) {
        if (l == 3) {
            l = 0;  // 주의: 이렇게 하면 무한 루프에 빠진다.
        }
        cout << "Potentially infinite loop, iteration " << l + 1 << endl;
    }

    return 0;
}

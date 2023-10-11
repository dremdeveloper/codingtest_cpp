//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>

using namespace std;

// 전역변수: 프로그램의 어디서든 접근 가능한 변수. 프로그램 시작 시 초기화되며, 프로그램 종료 시 메모리에서 해제됩니다.
int globalVariable = 10;

/* 
변수의 범위(Variable Scope):
- 변수는 선언된 위치에 따라 그 접근 범위가 결정됩니다.
- 전역변수, 지역변수, static 변수 등 다양한 범위의 변수가 있습니다.
*/

void exampleFunction() {
    // 지역변수: 함수 내에서만 접근 가능한 변수. 함수가 호출될 때 메모리에 할당되고, 함수 종료 시 메모리에서 해제됩니다.
    int localVariable = 5;
    cout << "Local Variable inside exampleFunction: " << localVariable << endl;

    // static 변수: 함수 내에서만 접근 가능하지만, 프로그램 종료 시까지 메모리에 남아있습니다.
    // 함수가 여러 번 호출되어도 값이 유지됩니다.
    static int staticVariable = 0;
    staticVariable++;
    cout << "Static Variable inside exampleFunction: " << staticVariable << endl;
}

int main() {
    cout << "Global Variable: " << globalVariable << endl;

    // main 함수 내의 지역변수
    int localInMain = 20;
    cout << "Local Variable inside main: " << localInMain << endl;

    exampleFunction();  // 출력: Local Variable inside exampleFunction: 5
                        // 출력: Static Variable inside exampleFunction: 1
    exampleFunction();  // 출력: Local Variable inside exampleFunction: 5
                        // 출력: Static Variable inside exampleFunction: 2

    // 다음 코드는 오류를 발생시킵니다. 왜냐하면 localVariable은 exampleFunction 내의 지역변수이기 때문입니다.
    // cout << localVariable << endl;

    return 0;
}

/* 
주의사항:
1. 전역변수의 남발은 코드의 가독성과 유지보수성을 저하시킬 수 있습니다. 
2. 같은 이름의 전역변수와 지역변수가 있다면, 지역변수가 우선순위를 가집니다.
3. static 변수는 특정 함수의 실행 사이에서 값을 유지해야 할 때 유용하게 사용됩니다. 하지만 과도한 사용은 피해야 합니다.
*/


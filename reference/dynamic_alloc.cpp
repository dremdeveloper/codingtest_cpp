//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>

using namespace std;

int main() {

    /* 
    동적 할당(Dynamic Allocation)이란?
    - 동적 할당은 프로그램 실행 중에 메모리를 동적으로 할당(요청)하거나 해제하는 방법입니다.
    - C++에서는 'new'와 'delete' 연산자를 사용하여 동적 할당 및 메모리 해제를 수행합니다.
    - 동적으로 할당된 메모리는 힙(Heap) 영역에 저장됩니다.
    - 동적 할당은 배열의 크기나 객체의 수가 실행 시간에 결정되어야 할 때 유용합니다.
    */

    int *ptr = new int;  // 정수를 저장할 수 있는 메모리 동적 할당
    *ptr = 10;  // 동적으로 할당된 메모리에 값 저장

    cout << "Value: " << *ptr << endl;  // 출력: Value: 10

    delete ptr;  // 동적으로 할당된 메모리 해제

    /* 
    주의사항:
    1. 동적으로 할당된 메모리는 프로그래머의 책임으로 해제되어야 합니다. 그렇지 않으면 메모리 누수(memory leak)가 발생합니다.
    */
    int *leakPtr = new int;
    // 메모리 해제 코드 없음. 메모리 누수 발생

    /* 
    2. 이미 해제된 메모리에 다시 접근하거나 해제하려고 시도하면 정의되지 않은 동작(Undefined Behavior)이 발생합니다.
    */
    int *doubleDeletePtr = new int;
    delete doubleDeletePtr;
    // delete doubleDeletePtr;  // 오류: 이미 해제된 메모리 다시 해제 시도

    /* 
    3. 동적 할당을 사용할 때는 항상 포인터를 초기화하고, 메모리 할당이 성공적으로 이루어졌는지 확인하는 것이 좋습니다.
    */
    int *initPtr = nullptr;  // 포인터 초기화
    initPtr = new (nothrow) int;  // 메모리 할당 실패 시 nullptr 반환
    if (initPtr) {  // 메모리 할당 확인
        *initPtr = 20;
        cout << "Value: " << *initPtr << endl;  // 출력: Value: 20
        delete initPtr;
    }

    /* 
    4. 동적으로 할당된 배열을 해제할 때는 'delete[]'를 사용해야 합니다.
    */
    int* arrPtr = new int[5];
    delete[] arrPtr;  // 배열 메모리 해제

    return 0;
}

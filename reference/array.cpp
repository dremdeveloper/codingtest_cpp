//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>

using namespace std;

int main() {

    /* 
    배열(Array)이란?
    - 배열은 동일한 타입의 여러 데이터를 연속적인 메모리 공간에 저장할 수 있는 데이터 구조입니다.
    - 배열의 각 요소는 인덱스를 통해 접근할 수 있습니다.
    - 배열의 크기는 선언 시에 지정되며, 이후 크기 변경이 불가능합니다.
    - 배열은 스택 메모리에 할당됩니다(동적으로 힙 메모리에 할당하려면 동적 배열을 사용해야 합니다).
    */

    int arr[5] = {1, 2, 3, 4, 5};  // 크기가 5인 int 타입의 배열 선언 및 초기화

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";  // 배열의 요소 접근 및 출력
    }
    cout << endl;  // 출력: 1 2 3 4 5

    /* 
    주의사항:
    1. 배열의 범위를 벗어나는 인덱스에 접근하면 정의되지 않은 동작(Undefined Behavior)가 발생합니다.
    */
    // arr[10] = 50;  // 오류: 배열의 범위를 벗어난 인덱스에 접근

    /* 
    2. 배열의 크기를 동적으로 할당하려면 new와 delete 연산자를 사용해야 합니다.
    */
    int* dynamicArray = new int[10];  // 크기가 10인 동적 배열 생성
    for (int i = 0; i < 10; i++) {
        dynamicArray[i] = i;
    }
    delete[] dynamicArray;  // 동적 배열 메모리 해제

    /* 
    3. 배열의 크기는 컴파일 시에 결정되어야 하므로, 실행 시간에 크기를 지정할 수 없습니다.
    이런 경우 동적 배열을 사용해야 합니다.
    */
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int* arraySizeDynamic = new int[size];
    delete[] arraySizeDynamic; 

    /* 
    4. 배열은 할당된 크기 변경이 불가능합니다. 크기 변경이 필요한 경우, 새로운 크기의 배열을 만들고 데이터를 복사해야 합니다.
    */

    return 0;
}

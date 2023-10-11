//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>

using namespace std;

int main() {

    /* 
    형변환이란?
    - 변수나 리터럴의 데이터 타입을 다른 데이터 타입으로 변환하는 것을 의미합니다.
    - C++에서는 명시적 형변환과 암시적 형변환의 두 가지 방법이 있습니다.
    */

    // 1. 암시적 형변환 (Implicit Type Conversion)
    double d = 3.14;
    int i = d;  // double에서 int로 암시적 형변환. 소수 부분이 손실됨.
    cout << "i: " << i << endl; // 출력: i: 3

    // 2. 명시적 형변환 (Explicit Type Conversion)
    double e = 5.67;
    int j = static_cast<int>(e);  // double에서 int로 명시적 형변환. 소수 부분이 손실됨.
    cout << "j: " << j << endl;  // 출력: j: 5

    /* 
    주의사항:
    1. 형변환으로 인해 데이터의 손실이 발생할 수 있습니다.
    예: double에서 int로 형변환 시, 소수 부분이 손실됩니다.
    
    2. 음수와 unsigned 데이터 타입의 비교는 주의가 필요합니다. 
    unsigned 데이터 타입은 항상 양수이기 때문에 음수를 unsigned 타입으로 형변환하면 큰 양수값이 됩니다.
    */
    int negative = -3;
    unsigned int u = 2;

    if (negative < u) {  // true로 예상되지만, 음수가 큰 양수값으로 변환되므로 false입니다.
        cout << "negative is less than u." << endl;
    } else {
        cout << "negative is NOT less than u." << endl;  // 출력: negative is NOT less than u.
    }

    /* 
    3. sizeof 연산자를 사용할 때 주의가 필요합니다. 
    sizeof는 변수나 타입의 크기를 반환하며, 반환값은 size_t 타입입니다. 
    size_t는 일반적으로 unsigned int나 unsigned long과 같은 양수만을 가질 수 있는 타입입니다.
    따라서 음수와 비교 시, 의도하지 않은 결과가 발생할 수 있습니다.
    */
    int arr[10];
    int n = -5;

    if (n < sizeof(arr)) {  // true로 예상되지만, 음수가 큰 양수값으로 변환되므로 false입니다.
        cout << "n is less than size of arr." << endl;  // 출력: n is less than size of arr.
    } else {
        cout << "n is NOT less than size of arr." << endl;
    }

    return 0;
}

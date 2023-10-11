//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>

using namespace std;

// Call by Value: 이 함수는 벡터를 값으로 받습니다.
// 큰 데이터 구조를 값으로 받게 되면 복사가 발생하기 때문에 성능상의 오버헤드가 발생할 수 있습니다.
// 메모리 사용량이 증가하고, CPU도 더 많은 작업을 해야하기 때문에 프로그램의 성능에 부정적인 영향을 줄 수 있습니다.
void callByValue(vector<int> v) {
    v[0] = 999;  // 복사된 벡터에만 영향을 줍니다.
    cout << "Inside callByValue: " << v[0] << endl;  // 출력: 999
}

// Call by Reference: 이 함수는 벡터를 참조로 받습니다.
// 데이터를 복사하지 않기 때문에 메모리 사용량이 증가하지 않고, CPU도 더 적은 작업만을 수행하면 됩니다.
// 큰 데이터 구조를 다룰 때는 참조를 사용하여 성능상의 이점을 얻을 수 있습니다.
void callByReference(vector<int>& v) {
    v[0] = 888;  // 원본 벡터에 직접 영향을 줍니다.
    cout << "Inside callByReference: " << v[0] << endl;  // 출력: 888
}

int main() {
    vector<int> vec = {1, 2, 3};

    callByValue(vec);
    cout << "After callByValue: " << vec[0] << endl;  // 출력: 1 (원본은 변경되지 않음)

    callByReference(vec);
    cout << "After callByReference: " << vec[0] << endl;  // 출력: 888 (원본이 변경됨)

    return 0;
}


//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>

using namespace std;

// 템플릿은 C++에서 타입에 대해 일반화된 코드를 작성할 수 있게 해주는 기능입니다.
// 이를 통해 다양한 데이터 타입에 대해 동작하는 함수나 클래스를 정의할 수 있습니다.
// 템플릿은 "template" 키워드로 시작하며, 타입은 <> 안에 정의됩니다.

// 1. 기본 템플릿 함수
template <typename T>  // 여기서 T는 임의의 타입을 의미합니다.
T add(T a, T b) {
    return a + b;
}

// 2. 템플릿 클래스
template <typename T>
class MyVector {
private:
    T* arr;
    int size;
public:
    MyVector(int s) : size(s) {
        arr = new T[size];
    }

    T& operator[](int index) {
        return arr[index];
    }
    
    ~MyVector() {
        delete[] arr;
    }
};

// 3. STL에서의 템플릿 사용
// STL(Standard Template Library)은 C++의 표준 라이브러리로써, 다양한 컨테이너와 알고리즘을 제공합니다.
// 대부분의 STL 컨테이너와 알고리즘은 템플릿으로 구현되어 있습니다.
template <typename T>
void printVector(const vector<T>& v) {
    for (const T& element : v) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    // 기본 템플릿 함수 사용
    cout << add<int>(3, 4) << endl;         // 출력: 7
    cout << add<double>(3.5, 4.2) << endl; // 출력: 7.7
    
    // 사용자 정의 템플릿 클래스 사용
    MyVector<int> myVec(5);
    myVec[0] = 1;
    myVec[1] = 2;
    cout << myVec[0] << " " << myVec[1] << endl;  // 출력: 1 2

    // STL에서의 템플릿 사용 예
    vector<string> names = {"Alice", "Bob", "Charlie"};
    printVector(names);  // 출력: Alice Bob Charlie 

    
    return 0;
}


//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. 기본적인 문자열 생성 및 출력
    string str1 = "Hello, World!";  // 문자열 초기화
    cout << str1 << endl;           // 출력: Hello, World!

    /* 
    문자열(string)이란?
    - C++의 STL에서 제공하는 문자열 클래스입니다.
    - 문자의 연속으로 구성되며, '\0' 문자로 종료되지 않습니다 (C 스타일 문자열과 차이점).
    - + 연산자를 통해 문자열을 연결할 수 있습니다.
    - 내부적으로는 동적 배열로 구현되어 있어 크기를 동적으로 변경할 수 있습니다.
    */

    // 2. 문자열 연결
    string str2 = "Hello";
    string str3 = "World";
    string str4 = str2 + ", " + str3 + "!";  // 문자열 연결
    cout << str4 << endl;                    // 출력: Hello, World!

    // 3. 문자열 길이와 접근
    cout << "Length of str1: " << str1.length() << endl;  // 출력: 13
    cout << "First character of str1: " << str1[0] << endl;  // 출력: H

    /* 
    주의사항:
    - 문자열 인덱스를 사용하여 문자에 접근할 때 인덱스 범위를 초과하지 않도록 주의해야 합니다. 초과할 경우 undefined behavior가 발생합니다.
    - C++의 string은 변경 가능합니다. 하지만, C 스타일 문자열(char 배열)은 직접 변경할 때 주의가 필요합니다.
    */

    // 4. 문자열의 부분 문자열 및 찾기
    string str5 = str1.substr(7, 5);  // 7번째 인덱스부터 5개의 문자를 가져옴
    cout << "Substring: " << str5 << endl;  // 출력: World

    size_t pos = str1.find("World");  // "World"의 시작 위치를 찾습니다.
    if (pos != string::npos) {
        cout << "\"World\" starts at index " << pos << endl;  // 출력: "World" starts at index 7
    } else {
        cout << "\"World\" not found!" << endl;
    }

    return 0;
}

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
    // 인덱스:  | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|
    // 값    :  | H| e| l| l| o| ,|  | W| o| r| l| d| !|

    // 여러가지 문자열의 초기화 방법
    string str2("Hello");           
    cout << str2 << endl;           // 출력: Hello
    // 인덱스:  | 0| 1| 2| 3| 4|
    // 값    :  | H| e| l| l| o|

    string str3 = "World";          
    cout << str3 << endl;           // 출력: World
    // 인덱스:  | 0| 1| 2| 3| 4|
    // 값    :  | W| o| r| l| d|

    string str4(str2 + ", " + str3 + "!"); 
    cout << str4 << endl;           // 출력: Hello, World!
    // 인덱스:  | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|
    // 값    :  | H| e| l| l| o| ,|  | W| o| r| l| d| !|

    string str5 = str1;             
    cout << str5 << endl;           // 출력: Hello, World!
    // 인덱스:  | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|
    // 값    :  | H| e| l| l| o| ,|  | W| o| r| l| d| !|

    string str6(5, 'A');            
    cout << str6 << endl;           // 출력: AAAAA
    // 인덱스:  | 0| 1| 2| 3| 4|
    // 값    :  | A| A| A| A| A|

    /* 
    문자열(string)이란?
    - C++의 STL에서 제공하는 문자열 클래스입니다.
    - 문자의 연속으로 구성되며, '\0' 문자로 종료되지 않습니다 (C 스타일 문자열과 차이점).
    - + 연산자를 통해 문자열을 연결할 수 있습니다.
    - 내부적으로는 동적 배열로 구현되어 있어 크기를 동적으로 변경할 수 있습니다.
    */

    // 2. 문자열 연결
    string str7 = "Hello";           
    cout << str7 << endl;           // 출력: Hello
    // 인덱스:  | 0| 1| 2| 3| 4|
    // 값    :  | H| e| l| l| o|

    string str8 = "World";           
    cout << str8 << endl;           // 출력: World
    // 인덱스:  | 0| 1| 2| 3| 4|
    // 값    :  | W| o| r| l| d|

    string str9 = str7 + ", " + str8 + "!";  
    cout << str9 << endl;           // 출력: Hello, World!
    // 인덱스:  | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|
    // 값    :  | H| e| l| l| o| ,|  | W| o| r| l| d| !|

    // 3. 문자열 길이와 접근
    cout << "Length of str1: " << str1.length() << endl;  // 출력: 13
    // str1의 길이: 13 (H e l l o ,   W o r l d !)

    cout << "First character of str1: " << str1[0] << endl;  // 출력: H
    // str1의 첫 번째 문자: H (H e l l o ,   W o r l d !)

    /* 
    주의사항:
    - 문자열 인덱스를 사용하여 문자에 접근할 때 인덱스 범위를 초과하지 않도록 주의해야 합니다. 초과할 경우 undefined behavior가 발생합니다.
    */

    // 4. 문자열의 부분 문자열 및 찾기
    string str10 = str1.substr(7, 5);  
    cout << "Substring: " << str10 << endl;  // 출력: World
    // 인덱스:  | 0| 1| 2| 3| 4|
    // 값    :  | W| o| r| l| d|

    size_t pos = str1.find("World");  
    if (pos != string::npos) {
        cout << "\"World\" starts at index " << pos << endl;  // 출력: "World" starts at index 7
    } else {
        cout << "\"World\" not found!" << endl;
    }
    // str1:   | H| e| l| l| o| ,|  | W| o| r| l| d| !|
    // 인덱스: | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|

    // 5. 문자열 대체
    string str11 = "I like cats";     
    cout << str11 << endl;            // 출력: I like cats
    // 인덱스:  | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|
    // 값    :  | I|  | l| i| k| e|  | c| a| t| s|

    str11.replace(7, 4, "dogs");  
    cout << str11 << endl;  // 출력: I like dogs
    // str11:  | I|  | l| i| k| e|  | d| o| g| s|
    // 인덱스: | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|

    return 0;
}


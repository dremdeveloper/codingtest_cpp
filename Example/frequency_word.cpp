#include <iostream>
//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // 문자열 내 각 문자의 빈도를 저장할 unordered_map 선언
    unordered_map<char, int> frequency;

    // 분석할 문자열
    string str = "hello world";

    // 문자열의 각 문자를 순회하면서 빈도를 계산
    for (char ch : str) {
        frequency[ch]++;
    }

    // 각 문자의 빈도 출력
    for (const auto& pair : frequency) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // 출력값:
    // h: 1
    // e: 1
    // l: 3
    // o: 2
    //  : 1
    // w: 1
    // r: 1
    // d: 1

    return 0;
}

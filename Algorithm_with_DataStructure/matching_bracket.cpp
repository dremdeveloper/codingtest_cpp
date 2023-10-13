//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
/*
괄호 짝 검사 알고리즘:
- 시간 복잡도: O(n)
- 용도: 괄호가 올바르게 짝을 이루고 있는지 검사하는 데 사용합니다.
- 동작 과정:
  1. 문자열의 각 문자를 차례대로 확인합니다.
  2. 여는 괄호('(')를 만나면 스택에 푸시합니다.
  3. 닫는 괄호(')')를 만나면 스택이 비어있는지 확인하고, 비어있지 않다면 스택의 탑을 팝합니다.
  4. 문자열의 모든 문자를 처리한 후 스택이 비어있으면 짝이 맞는 것으로, 비어있지 않다면 짝이 맞지 않는 것으로 판단합니다.

도식화 예:
입력: "(()(())())"
스택: [ "(" ]
-> 첫 번째 ')'를 만날 때: 스택에서 "(" 팝
스택: [ "(" ]
-> 두 번째 ')'를 만날 때: 스택에서 "(" 팝
스택: [ "(", "(", "(" ]
-> 세 번째 ')'를 만날 때: 스택에서 "(" 팝
... (계속)
스택: [ ]
-> 모든 문자를 처리하고, 스택이 비어있으므로 괄호 짝이 맞습니다.
*/

#include <iostream>
#include <stack>
using namespace std;

bool areParenthesesBalanced(const string& expr) {
    stack<char> s; // 스택 생성
    for (char ch : expr) {
        if (ch == '(') { // 여는 괄호를 만나면 스택에 푸시
            s.push(ch);
        } else if (ch == ')') { // 닫는 괄호를 만나면
            if (s.empty()) { // 스택이 비어있으면 괄호 짝이 맞지 않습니다.
                return false;
            }
            s.pop(); // 스택의 탑 원소를 팝
        }
    }
    // 문자열의 모든 문자를 처리한 후 스택이 비어있으면 괄호 짝이 맞습니다.
    return s.empty();
}

int main() {
    string expr = "(()(())())";
    if (areParenthesesBalanced(expr)) {
        cout << "The parentheses are balanced.\n";
    } else {
        cout << "The parentheses are NOT balanced.\n";
    }
    return 0;
}

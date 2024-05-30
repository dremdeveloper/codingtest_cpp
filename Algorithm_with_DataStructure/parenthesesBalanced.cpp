#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 두 문자가 짝이 맞는 괄호인지 확인하는 함수
bool isMatchingPair(char first, char second) {
    // 각 괄호 쌍을 비교하여 일치하면 true 반환
    if (first == '(' && second == ')') return true;
    else if (first == '{' && second == '}') return true;
    else if (first == '[' && second == ']') return true;
    // 일치하지 않으면 false 반환
    return false;
    // 시간 복잡도: O(1)
}

// 주어진 괄호 문자열이 올바르게 짝이 맞는지 확인하는 함수
bool areParenthesesBalanced(string expression) {
    stack<char> stack; // 여는 괄호를 저장할 스택
    
    // 문자열의 각 문자를 순회
    for (int i = 0; i < expression.length(); i++) {
        // 여는 괄호는 스택에 푸시
        if (expression[i] == '{' || expression[i] == '(' || expression[i] == '[') {
            stack.push(expression[i]);
        }
        
        // 닫는 괄호가 나왔을 때
        if (expression[i] == '}' || expression[i] == ')' || expression[i] == ']') {
            // 스택이 비어있으면 짝이 맞지 않음
            if (stack.empty()) {
                return false;
            }
            // 스택의 top과 현재 닫는 괄호가 짝이 맞는지 확인
            else if (!isMatchingPair(stack.top(), expression[i])) {
                return false;
            }
            // 짝이 맞으면 스택에서 여는 괄호를 팝
            else {
                stack.pop();
            }
        }
    }
    
    // 스택이 비어있으면 모든 괄호가 짝이 맞음, 아니면 짝이 맞지 않음
    return stack.empty();
    // 시간 복잡도: O(n), n은 입력 문자열의 길이
}

// 주어진 괄호 문자열을 테스트하는 함수
void do_test(string expression) {
    if (areParenthesesBalanced(expression))
        std::cout << "괄호가 올바르게 짝이 맞습니다." << std::endl;
    else
        std::cout << "괄호가 올바르게 짝이 맞지 않습니다." << std::endl;
}

int main() {
    // 테스트 케이스 실행
    do_test("{}({})");   // 올바르게 짝이 맞는 경우
    do_test("{{({})");   // 여는 괄호가 더 많은 경우
    do_test("{}({))");   // 닫는 괄호가 더 많은 경우
    
    return 0;
    // 시간 복잡도: O(n) 각 테스트 케이스에 대해
}

#include <stack>
using namespace std;

// 'solution' 함수는 문자열 's'가 올바른 괄호 구조를 가지고 있는지 확인합니다.
// '(' 괄호가 나오면 스택에 푸시하고, ')' 괄호가 나오면 스택에서 팝합니다.
// 모든 문자를 확인한 후 스택이 비어있다면 괄호가 올바르게 닫힌 것입니다.
bool solution(string s) {
    stack<char> stack;

    for (char c : s) {
       //❶ '(' 괄호를 스택에 푸시합니다.
        if (c == '(') { 
            stack.push(c);
        } 
       else if (c == ')') {
       // ❷  ')' 괄호가 나오면 스택이 비어있는지 확인            
            if (stack.empty()) {
              //❸  스택이 비어있다면 괄호 짝이 맞지 않으므로 false반환
                return false;
            } else {
               //❹ 비어있지 않다면 팝 연산(짝을 찾으므로 여는괄호 스택에서 제거)
                stack.pop();
            }
        }
    }

    //❺ 스택이 비어있다면 괄호가 올바르게 닫힌 것이므로 true 반환, 아니라면 false 반환
     return stack.empty();
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>
int main()
{
    //(true를 출력하면 1 이고, false를 출력하면 0입니다.
    
    cout << solution("(())()") << endl;  // 1
    cout << solution("((())()") << endl; // 0 

    return 0;
}

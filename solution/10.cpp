#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// ❶ 닫힌 괄호의 짝을 바로 확인할 수 있도록 맵 선언 
unordered_map<char, char> bracketPair = {
        {')', '('},
        {']', '['},
        {'}', '{'}
};

//❷현자 인자로 받은 문자열 기준 괄호짝이 맞는지 확인
bool isValid(string& s, int start) {
    stack<char> stk;
    unsigned int  sz = s.size();
    
//❸ 문자열을 순회하면서
    for(int i = 0 ; i < sz ; i++) {
      char ch = s[(start + i) % sz];
      //❹ ch가 닫힌 괄호 인경우
        if(bracketPair.count(ch)) {
           // ❺ 스택이 비었거나 top 원소가 ch와 짝이 맞는 열린괄호가 아닌 경우 false 반환
            if(stk.empty() || stk.top() != bracketPair[ch]) return false;
           //❻ ch와 짝이 맞는 열린괄호일경우 해당 열린괄호를 제거
            stk.pop();
        } else {
           //❼ 열린 괄호일경우 스택이 푸시
            stk.push(ch);
        }
    }
   //❽스택이 비었으면 true를 반환(비었다는것은 괄호 짝이 맞다는 것을 의미)
    return stk.empty();
}

int solution(string s) {
    int answer = 0;
    int n = s.size();
    
   //❾ 문자열을 rotation하면서 괄호짝이 맞으면 answer를 1증가 시킴
    for(int i = 0; i < n; i++) {
        answer += isValid(s,i);
    }
    return answer;
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>
int main()
{
    cout << solution("[](){}") << endl; // 3
    cout << solution("}]()[{") << endl; // 2 
    cout << solution("[)(]") << endl;   // 0 
    cout << solution("}}}") << endl;    // 0   
    return 0;
}
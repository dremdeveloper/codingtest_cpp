#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
     stack<char> st;

    for(int i=0;i<s.length();i++){
       //❶스택이 비었거나 현재문자와같은 문자가 아닌 경우 푸시
        if(st.empty() || st.top() != s[i]) st.push(s[i]);
      //❷ 현재문자와 스택의 가장 최근 문자가 같은 경우 팝
        else st.pop();
    }
   

   //❸ 현재 스택이 비었거나, 문자열의 짝이 맞다는 의미이므로 true반환, 아니면 false 반환
    return st.empty();
}



//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
    cout << solution("baabaa") << endl; // 1
    cout << solution("cdcd") << endl;   // 0 
    return 0;
}
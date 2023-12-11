#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> c1, c2, g;
    
   // ❶cards와 goal을 queue로 나타냄 
    for (const string& s : cards1) c1.push(s);    
    for (const string& s : cards2) c2.push(s);
    for (const string& s : goal) g.push(s);
        
    //❷ 단어 배열을 앞에서 부터 순회 
    while (!g.empty()) {
       //❸ c1의 현재 문자열과 g의 현재 문자열이 일치하는 경우
        if (!c1.empty() && c1.front() == g.front()) {
            c1.pop();
            g.pop();
        }
       //❹ c2의 현재문자열과  g의 현재 문자열이 일치하는 경우 
       else if (!c2.empty() && c2.front() == g.front()) {
            c2.pop();
            g.pop(); 
        }
       //❺ 일치하는 카드뭉치가 없는 경우 반복문을 빠져나감 
       else {
            break;
        }
    }
   //❻ 원하는 문자열을 카드뭉치에서 만들었으면 Yes 아니면 No 반환
    return g.empty() ? "Yes" : "No";
}





//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
    cout<< solution({"i", "drink", "water"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << endl; // "Yes"
    cout<< solution({"i", "water", "drink"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << endl; // "No"
    return 0;

}

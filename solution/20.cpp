#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
   //❶ participant를 나타낼 해시테이블 
    unordered_map<string, int> ph;

   //❷ 각 참가자들을 해시 테이블에 추가( 키 : 이름, 값 : 해당 이름의 명 수)
    for (int i = 0; i < participant.size(); i++)
        ph[participant[i]]++;

 
    //❸ 참가자 정보가 저장된 해시 테이블에서, 완주한 선수들을 제외
    for (int i = 0; i < completion.size(); i++)
    {
        ph[completion[i]]--;
        //❹ 해시테이블에서 특정 이름의 인원이 0명이면, 해시 테이블에서 삭제
        if (ph[completion[i]] == 0)
            ph.erase(ph.find(completion[i]));
    }
   //❺ 마지막 남은 한 선수의 이름을 반환 
    return ph.begin()->first;
}



//아래 코드는 테스트 코드 입니다.

#include <iostream>

int main()
{
    cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"}) << endl; // "leo"
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << endl; // "vinko"
    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << endl; // "mislav"
    return 0;

}

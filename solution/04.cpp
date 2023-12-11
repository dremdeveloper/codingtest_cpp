#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ❶ 각 수포자가 찍는 패턴을 정의
vector<int> firstPattern  = {1,2,3,4,5};
vector<int> secondPattern = {2,1,2,3,2,4,2,5};
vector<int> thirdPattern  = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
   // ❷ 최종적으로 가장 많이 문제를 맞힌 사람이 저장될 벡터
    vector<int> answer;
    
   // ❸ 각 수포자들의 패턴대로 답안을 작성할때 문제를 맞힌 갯수가 저장될 벡터
    vector<int> matchCnt(3);

    // ❹ 실제 정답과 각 수포자들의 패턴을 비교해서 맞춘 갯수
      for(int i=0; i<answers.size(); i++) {
        if(answers[i] == firstPattern[i % firstPattern.size()]) matchCnt[0]++;
        if(answers[i] == secondPattern[i % secondPattern.size()]) matchCnt[1]++;
        if(answers[i] == thirdPattern[i % thirdPattern.size()]) matchCnt[2]++;
    }
    // ❺ 가장 많이 맞춘 수포자가 얻은 점수
    int max_score = *max_element(matchCnt.begin(),matchCnt.end());
    
    // ❻ 가장 많이 맞춘 수포자의 번호를 저장
    for(int i = 0; i< 3; i++) {
        if(matchCnt[i] == max_score) answer.push_back(i+1);
    }
    
    return answer;
}




//아래 코드는 테스트 코드 입니다.

#include <iterator>
#include <iostream>
void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({1, 2, 3, 4, 5}));     // 1 
    print(solution({1, 3, 2, 4, 2}));     // 1 2 3 
    
    return 0;
}

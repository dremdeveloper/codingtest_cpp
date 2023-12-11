#include <vector>
#include <algorithm>

using namespace std;

// ❶ 문제에서 요구하는 조건대로 실패율을 정렬하는 함수 
bool compare(pair<int, float>& a, pair<int, float>& b) {
    if (a.second == b.second) 
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {

    vector<int> answer; // ❷ answer는 최종 답 
    vector<float> challenger(N + 2, 0.0);  // ❸ challenger는 각 스테이지에 도달한 적이 있는 도전자의 수  
    vector<float> fail(N + 2, 0.0); // ❹ fail는 특정 스테이지에 실패한 도전자의 수

 // ❺ 각 스테이지의 인원을 기준으로 특정 스테이지에서 실패한 인원수와, 각 스테이지에 도전한 적이 있는 인원수를 구함 
    for (int i = 0; i < stages.size(); i++) {
        for (int j = 1; j <= stages[i]; j++)
            challenger[j]++;

        fail[stages[i]]++;
    }
  // ❻ failRatio는 실패율을 저장, first는 stage정보이고 second는 실패율 
    vector<pair<int, float>> failRatio(N);

 // ❼ 스테이지 정보 및 실패율을 저장  
  for (int i = 0; i < N; i++) {
        failRatio[i].first = i + 1;

        if (challenger[i + 1] == 0)
            failRatio[i].second = 0;
        else
            failRatio[i].second = fail[i + 1] / challenger[i + 1];
    }

// ➑ 계산한 실패율을 문제에서 제시한 조건에 맞게 정렬
    sort(failRatio.begin(), failRatio.end(), compare);

// ❾ 최종 답을 반환하기 위해 실패율을 저장
    for (int i = 0; i < N; i++) {
        answer.push_back(failRatio[i].first);
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
    print(solution(5, {2, 1, 2, 6, 2, 4, 3, 3})); // 3 4 2 1 5
    print(solution(4, {4, 4, 4, 4, 4}));          // 4 1 2 3 

    return 0;
}

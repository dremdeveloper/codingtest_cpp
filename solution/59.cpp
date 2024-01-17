#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//❶ 문자열로 바뀐 두 수를 조합해서 크기를 비교
bool compare(const string& lhs, const string& rhs) {
  return (lhs + rhs) > (rhs + lhs);
}

string solution(vector<int> numbers) {
  string answer = "";
  vector<string> strings;

  for (auto elem : numbers) {
    //❷ numbers의 원소를 문자열로 변형해서 푸시
    strings.push_back(to_string(elem));
  }
  //❸ 정렬함수를 기준으로 정렬 
  sort(strings.begin(), strings.end(), compare);

  //❹ 정렬된 문자열을 앞에서 부터 추가
  for (auto elem : strings) {
    answer += elem;
  }

    //❺ 최종 숫자가 0이면 0을 반환하고 그렇지 않으면 answer 반환
    return answer[0] == '0' ? "0" : answer;
}




//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution({6, 10, 2}) << endl; // 출력값 : 6210
  cout << solution({3, 30, 34, 5, 9}) << endl; // 출력값 : 9534330
  return 0;
}

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int counts[100001] = {};

void updateCounts(const string& s) {
  string numStr;
  //❶ 인자로 받은 문자열을 순회
  for (char ch : s) {
    //❷ 현재 문자가 숫자인 경우
    if (isdigit(ch)) {
      numStr += ch;
    //❸ 현재 문자가 숫자가 아닌 경우
    } else {
      if (!numStr.empty()) {
        //❹ 계수정렬을 하기 위해 각 숫자의 개수를 저장 
        counts[stoi(numStr)]++;
        numStr.clear();
      }
    }
  }
}

vector<int> solution(string s) {
  vector<int> answer;
  //❺ 집합이 담긴 문자열의 각 원소를 계수정렬
  updateCounts(s);

  vector<pair<int, int>> freqPairs;
  for (int i = 1; i <= 100000; i++) {
    //❻ 집합에 있는 원소인 경우 (개수, 값) 형식으로 푸시
    if (counts[i] > 0) {
      freqPairs.push_back({counts[i], i});
    }
  }

  //❼ 각 원소의 개수를 기준으로 내림차순 정렬
  sort(freqPairs.rbegin(), freqPairs.rend());

  //➑ 원소의 개수로 내림차순 정렬된 벡터를 순회하며 원소를 푸시
  for (const auto& p : freqPairs) {
    answer.push_back(p.second);
  }

  return answer;
}


//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>

using namespace std;

void init()
{
  for(int i = 0 ; i <= 100000; i++)
    counts[i] = 0;    
}

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}


int main()
{
  print(solution("{{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}}")); // 출력값 : 2 1 3 4
  init();
  print(solution("{{1, 2, 3}, {2, 1}, {1, 2, 4, 3}, {2}}")); // 출력값 : 2 1 3 4
  init();
  print(solution("{{20, 111}, {111}}")); // 출력값 : 111 20
  init();
  print(solution("{{123}}")); // 출력값 : 123
  init();
  print(solution("{{4, 2, 3}, {3}, {2, 3, 4, 1}, {2, 3}}")); // 출력값 : 3 2 4 1 
  
  return 0;
}

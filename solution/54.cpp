#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  //❶ 알파벳 개수(26개)만큼 빈도수 배열 생성
  vector<int> counts(26, 0); 

  //❷ 문자열의 각 문자에 대한 빈도수를 빈도수 배열에 저장
  for (char c : s) {
    counts[c - 'a']++;
  }

  //❸ 빈도수 배열을 순회하면서 정렬된 문자열을 생성
  string sorted_str = "";
  for (int i = 0; i < 26; i++) {
    sorted_str += string(counts[i], i + 'a');
  }

  return sorted_str;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution("hello") << endl; // 출력값 : ehllo
  cout << solution("algorithm") << endl; // 출력값 : aghilmort
  
  return 0;
}

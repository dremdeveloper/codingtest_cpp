#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx;

//❶ 비교 함수
bool compare (string a, string b) {
  return a[idx] == b[idx] ? a < b : a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {
  idx = n;
    
  //❷ 각 문자열의 idx번째 문자를 기준으로 정렬 
  sort (strings.begin(), strings.end(), compare);
  return strings;
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>

using namespace std;

void print(vector<string> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution({"sun", "bed", "car"}, 1)); //출력값 : car bed sun
  print(solution({"abce", "abcd", "cdx"}, 2));  // 출력값 : abcd abce cdx

  return 0;
}

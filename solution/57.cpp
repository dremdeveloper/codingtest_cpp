#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
  //❶ 숫자를 문자열로 변환
  string str = to_string(n);

  //❷ 역순으로 정렬
  sort(str.rbegin(), str.rend());
  return stoll(str);
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution(118372) << endl; // 출력값 : 873211

  return 0;
}

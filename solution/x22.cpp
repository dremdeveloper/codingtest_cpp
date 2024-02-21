#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phoneBook) {
  //❶ 전화번호 목록을 오름차순으로 정렬
  sort(phoneBook.begin(), phoneBook.end());

  //❷ 모든 전화번호를 순회하면서 다음 번호와 비교
  for (int i = 0; i < phoneBook.size() - 1; ++i) {
    //❸ 현재 번호가 다음 번호의 접두어인 경우 false 반환
    if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size())) {
      return false;
    }
  }

  //❹ 어떤 번호도 다른 번호의 접두어가 아닌 경우 true 반환
  return true;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  //bool 반환할 때 true는 1, false는 0 입니다.
  cout << solution({"119", "97674223", "1195524421"}) << endl; //출력값 : 0
  cout << solution({"123", "456", "789"}) << endl; //출력값 : 1
  cout << solution({"12", "123", "1235", "567", "88"}) << endl; //출력값 : 0
  
  return 0;
}

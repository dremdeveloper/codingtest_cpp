#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
  //❶ 점화식에 필요한 변수를 초기화
  int n = money.size();
  vector<int> dp1(n, 0);
  vector<int> dp2(n, 0);

  //❷ 첫 번째 집을 터는 경우
  dp1[0] = money[0];
  dp1[1] = money[0];
  for (int i = 2; i < n - 1; ++i) {
    dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
  }

  //❸ 첫 번째 집을 털지 않는 경우
  dp2[1] = money[1];
  for (int i = 2; i < n; ++i) {
    dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
  }

  //❹ 두 경우 중, 최대값 찾기
  int answer = max(dp1[n - 2], dp2[n - 1]);
  return answer;
}



//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution({1, 2, 3, 1}) << endl; //출력값 : 4
  
  return 0;
}

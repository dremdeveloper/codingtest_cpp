#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
  sort(d.begin(), d.end()); //❶ 벡터 d를 오름차순으로 정렬
  int count = 0; //❷ 지원할 수 있는 부서의 개수를 세는 변수

  for (int amount : d) {
    if (budget < amount) {
      break; //❸ 남은 예산이 신청한 금액보다 작으면 더 이상 지원할 수 없으므로 종료
    }
    budget -= amount; //❹ 예산에서 신청한 금액을 차감
    count += 1;
  }

  return count;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
  cout << solution({1, 3, 2, 5, 4}, 9) << endl; //출력값 : 3
  cout << solution({2, 2, 3, 3}, 10) << endl; //출력값 : 4
  
  return 0;
}

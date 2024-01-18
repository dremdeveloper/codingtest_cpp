#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int amount) {
  vector<int> denominations = {1, 10, 50, 100};
  sort(denominations.rbegin(), denominations.rend()); //❶ 화폐 단위를 큰 순서대로 정렬

  vector<int> change; //❷ 거스름돈을 담을 벡터
  for (int coin : denominations) {
    while (amount >= coin) { //❸ 해당 화폐 단위로 거스름돈을 계속 나눠줌
      change.push_back(coin); //❹ 거스름돈 벡터 업데이트
      amount -= coin; //❺ 정산이 완료된 거스름돈 뺌
    }
  }
  return change; //❻ 거스름돈 반환
}



//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>

using namespace std;

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}


int main()
{
  print(solution(123)); //출력값 : 100 10 10 1 1 1
  print(solution(350)); //출력값 : 100 100 100 50
  
  return 0;
}

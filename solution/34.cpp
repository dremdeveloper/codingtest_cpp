#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums) {
  //❶ s는 nums의 중복값을 제거한 집합
  unordered_set<int> s(nums.begin(), nums.end());

  //❷ 중복을 제거한 개수와 nums의 개수중 작은 값을 반환
  return min(nums.size() / 2, s.size());
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution({3, 1, 2 ,3}) << endl; //출력값 : 2
  cout << solution({3, 3, 3, 2, 2, 4}) << endl; //출력값 : 3
  cout << solution({3, 3, 3, 2, 2, 2}) << endl; //출력값 : 2
  
  return 0;
}

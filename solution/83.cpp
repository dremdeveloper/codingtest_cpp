#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
  sort(people.begin(), people.end());  //❶ 몸무게를 오름차순으로 정렬
  int count = 0;  //❷ 필요한 보트 개수
  int i = 0;  //❸ 가장 가벼운 사람을 가리키는 인덱스
  int j = people.size() - 1;  //❹ 가장 무거운 사람을 가리키는 인덱스

  while (i <= j) {
    //❺ 가장 무거운 사람과 가장 가벼운 사람을 같이 태울 수 있으면 두 사람 모두 보트에 태움
    if (people[j] + people[i] <= limit) {
      i++;
    }
    //❻ 무거운 사람만 태울 수 있으면 무거운 사람만 보트에 태움
    j--;
    count++;
  }

  return count;
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
  cout << solution({70, 50, 80, 50}, 100) << endl; //출력값 : 3
  cout << solution({70, 80, 50}, 100) << endl; //출력값 : 3
  
  return 0;
}

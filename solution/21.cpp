#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
  int answer = 0;
  
  unordered_map<string, int> wantMap;
  //❶ want를 키로  number를 값으로 해서 wantMap을 선언
  for (int i = 0; i < want.size(); i++) 
    wantMap[want[i]] = number[i];


  for (int i = 0; i < discount.size() - 9; i++) {
    // ❷ i일 회원가입 시, 할인받을 수 있는 품목을 키로, 개수를 값으로 해서  discount_10d 선언
    unordered_map<string, int> discount_10d;

    // ❸  각 할인하는 품목을 키로  개수를 저장
    for (int j = i; j < 10 + i; j++)
      discount_10d[discount[j]]++;

   // ❹ 할인하는 상품의 품목및 개수가 원하는 상품의 품목 및 개수와 일치하면 카운트 증가
    if (wantMap == discount_10d) answer++;
  }

  return answer;
}

//여기는 테스트 코드 입니다.
#include <iostream>

int main()
{
    cout << solution( {"banana", "apple", "rice", "pork", "pot"}, 
                      {3, 2, 2, 2, 1}, 
                      {"chicken", "apple", "apple", "banana", "rice","apple", "pork", "banana", "pork", "rice", "pot","banana", "apple", "banana"}) << endl; // 3
                      
    cout << solution( {"apple"}, 
                      {10}, 
                      {"banana", "banana", "banana", "banana","banana", "banana", "banana", "banana", "banana","banana"}) << endl; // 0
    return 0;
}

#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> combi; // 주문의 조합 - 조합의 빈도

// 실제 주문의 조합을 구하는 함수
void combination(string src, string dst, int depth) {
  if (dst.size() == depth) combi[dst]++;

  else for (int i = 0; i < src.size(); i++)
    combination(src.substr(i+1), dst+src[i], depth);
}

vector<string> solution(vector<string> orders, vector<int> course) {
  vector<string> answer;
  // ❶ 각 주문들을 오름차순으로 정렬
  for (string &order : orders)
    sort(order.begin(), order.end());
  
  for (int len : course) {
    for (string order : orders)
      // ❷ course의 길이에 해당되는 조합 생성
      combination(order, "", len);

    // ❸ 각 주문의 빈도수를 순회하면서 가장 많은 빈도수를 maxOrder에 저장
    int maxOrder = 0;
    for (auto it : combi)
      maxOrder = max(maxOrder, it.second);

    // ❹ 주문 횟수가 2회 이상이면서, 가장 많이 주문된 주문의 구성은 answer에 추가
    for (auto it : combi)
      if (maxOrder >= 2 && it.second == maxOrder)
        answer.push_back(it.first);
    
    combi.clear();
  }
  // ❺ 반환 전, 문제의 조건에 따라 주문의 구성들을 오름차순 정렬해서 반환 
  sort(answer.begin(), answer.end());
  return answer;
}


//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>
void print(vector<string> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2, 3, 4})); //출력값 :  AC ACDE BCFG CDE
    print(solution({"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}, {2, 3, 5})); //출력값 : ACD AD ADE CD XYZ
    print(solution({"XYZ", "XWY", "WXA"}, {2, 3, 4})); //출력값 : WX XY 

    return 0;
}

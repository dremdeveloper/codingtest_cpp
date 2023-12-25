#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
  unordered_map<string, string> parent;

  //❶ parent는 판매원 - 판매원을 참여시킨 추천인으로 구성 
  for (size_t i = 0; i < enroll.size(); ++i) {
    parent[enroll[i]] = referral[i];
  }

  unordered_map<string, int> total;
  //❷ total은 판매원 - 판매원의 수익으로 구성되고 수익을 0으로 초기화
  for (const auto& name : enroll) {
    total[name] = 0;
  }

  for (size_t i = 0; i < seller.size(); ++i) {
    //❸ cur_name은 실제 물건을 판 사람이고, money 현재 판매원의 수익금
    int money = amount[i] * 100;
    string cur_name = seller[i];

    while (money > 0 && cur_name != "-") {
      //❹ 실제 물건을 판 사람을 기준으로  추천인을 계속 추적하며 남은 수익의 10%를 분배
      int to_distribute = money / 10;
      total[cur_name] += money - to_distribute;
      //❺ 현재 이름의 추천인이있으면, 현재이름은 추천인으로 변경, 그렇지 않으면 종료 
      if (parent.find(cur_name) != parent.end()) {
        cur_name = parent[cur_name];
      } else {
        break;
      }
      //❻  현재 판매원이 추천인으로 변경되었으므로, 수익금도 이에 맞춰서 업데이트
      money = to_distribute;
    }
  }

 //❼ 수익금을 answer에 업데이트 해서 반환
  vector<int> result;
  result.reserve(enroll.size());
  for (const auto& name : enroll) {
    result.push_back(total[name]);
  }

  return result;
}

//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>
void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}, 
                   {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
                   {"young", "john", "tod", "emily", "mary"},
                   {12, 4, 2, 5, 10}
                  )); //출력값 : 360 958 108 0 450 18 180 1080
                  
        print(solution({"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}, 
                       {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
                       {"sam", "emily", "jaimie", "edward"},
                        {2, 3, 5, 4}
                      )); //출력값 : 0 110 378 180 270 450 0 0 
    return 0;
}

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  unordered_map<string, unordered_set<string>> reported_user; // 신고당한 유저 - 신고 유저 집합
  unordered_map<string, int> count; // 처리 결과 메일을 받은 유저 - 받은 횟수

  // 신고 기록 순회
  for (string& r : report) {
    // ❶ 각 report에서 user_id와 report_id를 분리하고 reported_user에 추가 
    stringstream ss(r);
    string user_id, reported_id;
    ss >> user_id >> reported_id;
    reported_user[reported_id].insert(user_id);
  }

  for (auto& [reported_id, user_id_lst] : reported_user) {
    //❷ k명 이상에게 신고당했는지 확인
    if (user_id_lst.size() >= k) {
      //❸ 각 uid가 신고 결과를 받은 횟수를 기록
      for (const string& uid : user_id_lst) {
        count[uid]++;
      }
    }
  }

  vector<int> answer;
  //❹ 각 아이디별 메일을 받은 횟수를 id_list 순서대로 answer에 추가
  for (string& id : id_list) {
    answer.push_back(count[id]);
  }

  return answer;
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
    print(solution({"muzi", "frodo","apeach", "neo"}, {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}, 2)); //출력값 : 2 1 1 0
    print(solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 3)); //출력값 : 0 0 

    return 0;
}

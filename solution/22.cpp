#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
  vector<string> answer;
  unordered_map<string, string> uid;

  for (const auto& line : record) {
    //❶ 각 record에 대해서,  cmd에는 명령어를 저장하고  id에는 닉네임을 저장
    stringstream ss(line);
    string cmd, id, nickname;
    ss >> cmd >> id;
    //❷ 명령어가 Enter 혹은 Change일 경우 nickname에 닉네임을 저장
    if (cmd != "Leave") {
      ss >> nickname;
      uid[id] = nickname;
    }
  }

  for (const auto& line : record) {
    stringstream ss(line);
    string cmd, id;
    ss >> cmd >> id;
    //❸ Enter 및 Change 명령어의 경우 최종 닉네임과 정해진 문자열을 answer에 추가
    if (cmd == "Enter") {
      answer.push_back(uid[id] + "님이 들어왔습니다.");
    } else if (cmd == "Leave") {
      answer.push_back(uid[id] + "님이 나갔습니다.");
    }
    // "Change"는 메시지 생성에 영향을 주지 않으므로 무시
  }

  return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>
void print(vector<string> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution( {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234", "Enter uid1234 Prodo","Change uid4567 Ryan"} ));
  // Prodo님이 들어왔습니다. Ryan님이 들어왔습니다. Prodo님이 나갔습니다. Prodo님이 들어왔습니다.    

  return 0;
}

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
  vector<int> answer(2, 0);
  unordered_set<string> usedWords;
    
  usedWords.insert(words[0]);

  //❶ 두 번째 단어부터 끝까지 반복
  for (int i = 1; i < words.size(); ++i) {
    //❷ 단어가 이미 사용되었거나, 끝말잇기 규칙에 맞지 않는 경우
    if (!usedWords.insert(words[i]).second || words[i].front() != words[i - 1].back()) {
      //❸ 플레이어 번호와 턴 번호 저장 후 바로 반환
      answer[0] = i % n + 1;
      answer[1] = i / n + 1;
      return answer;
    }
  }

  //❹ 중간에 탈락하는 플레이어가 없으면 [0, 0] 반환
  return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>

using namespace std;

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"})); // 결과값 : 3 3
  print(solution(5, {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"})); // 결과값 : 0 0
  print(solution(2, {"hello", "one", "even", "never", "now", "world", "draw"})); // 결과값 : 1 3
  
  return 0;
}

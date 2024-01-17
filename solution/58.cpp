#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;
  vector<int> subArray;

  for (const auto& cmd : commands) {
    //❶ array에서 각 cmd에 해당되는 영역만 subArray로 복사후 정렬
    subArray.assign(array.begin() + (cmd[0] - 1), array.begin() + cmd[1]);
    sort(subArray.begin(), subArray.end());
      
    //❷ subArray에서 k번 째 answer에 추가
    answer.push_back(subArray[cmd[2] - 1]);     
  }

  return answer;
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
  print(solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}})); // 출력값 : 5 6 3

  return 0;
}

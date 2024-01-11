#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxDepth = 0;
bool visited[8] = {false, };

//❶ 최대방문 던전수를 갱신하면서 깊이우선탐색으로 던전을 탐험
void exploreDungeon(int depth, int power, vector<vector<int>>& dungeons) {
  if(maxDepth < depth)
    maxDepth = depth;

  for(int i = 0; i < dungeons.size(); i++) {
    //❷ 이미 방문한 던전이거나,  최소 필요 피로도가 현재 남은 피로도 보다 많은 경우 
    if(visited[i] || dungeons[i][0] > power)
      continue;
  
    //❸ 방문이 가능한 가능한 모든 경우를 확인
    visited[i] = true;
    exploreDungeon(depth + 1, power - dungeons[i][1], dungeons);
    visited[i] = false;
  }
}

int solution(int initialPower,vector<vector<int>> dungeons) {
  //❹ 던전탐색 시작
  exploreDungeon(0, initialPower, dungeons);

  return maxDepth;
}




//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution(80, {{80, 20}, {50, 40}, {30, 10}}) << endl; // 출력값 : 3
  return 0;
}

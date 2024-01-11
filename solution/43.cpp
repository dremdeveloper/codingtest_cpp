#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

//❶ 깊이 우선 탐색(DFS)을 수행하는 함수
void dfs(const vector<vector<int>>& network, int node) {
  visited[node] = true;

  for (int i = 0; i < network[node].size(); i++) {
    if (network[node][i] && !visited[i]) { 
      dfs(network, i);
    }
  }
}

int solution(int n, vector<vector<int>> computers) {
  visited = vector<bool>(computers.size(), false);

  int networkCount = 0; 

 //❷ 네트워크의 수를 확인
  for (int i = 0; i < computers.size(); i++) {
    if (!visited[i]) { 
      dfs(computers, i);
      networkCount++;
    }
  }

  return networkCount;
}



//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

void init()
{
  visited.clear();
}
int main()
{
  
  cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << endl; //출력값 : 2
  init();
  cout << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl; //출력값 : 1

  return 0;
}

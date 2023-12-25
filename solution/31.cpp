#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> visited, comp;
int n, answer = 0;

// 깊이 우선 탐색 (DFS)를 수행하는 함수
void dfs(vector<int> cur) {
  int sheep = 0, wolf = 0;
  //❶ 현재 방문한 경로를 기준으로 양과늑대의 개수를 셈
  for (int c : cur) {
    if (comp[c] == 1) wolf++;
    else sheep++;
  }

  //❷ 늑대의 수가 양보다 많거나 같으면 종료  
  if (sheep <= wolf) return; 

  //❸ 최대 양의 수 갱신
  answer = max(answer, sheep);

  for (int i = 0; i < cur.size(); i++) {
    int node = cur[i];
    //❹ 현재 노드와 인접한 노드를 순회
    for (int g : tree[node]) {
        
      //❺ 이미 방문한 노드는 재방문하지 않음
      if (visited[g]) continue;
      //❻ 현재노드를 방문한 경우, 하지 않은 경우 모두 확인
      visited[g] = true;
      cur.push_back(g);
      dfs(cur);
      cur.pop_back();
      visited[g] = false;
    }
  }
}

int solution(vector<int> info, vector<vector<int>> edges) {
  n = info.size();
  tree.resize(n);
  visited.resize(n, false);
  comp = info;

  //❼ 입력값으로 부터 트리 생성
  for (auto e : edges) {
    tree[e[0]].push_back(e[1]);
  }
  
  visited[0] = true;
 //❽ 방문여부를 체크하고, 시작 노드부터 탐색을 시작합니다.
  dfs({0});
  return answer;
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>
using namespace std;

void init()
{
    tree.clear();
    visited.clear();
    comp.clear();
    n = 0;
    answer = 0;
    
}

int main()
{
  cout << solution({0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}, 
                   {{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}}
                  ) << endl; //출력값 : 5

  init(); // 전역변수를 초기화 해야함
  
  cout << solution({0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0}, 
                   {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 7}, {4, 8}, {6, 9}, {9, 10}}
                  ) << endl; //출력값 : 5
    return 0;
}

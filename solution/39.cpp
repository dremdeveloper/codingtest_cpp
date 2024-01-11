#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> adjList;
vector<int> result;

void bfs(int start) {
  unordered_set<int> visited;
  queue<int> q;

  // ❶ 시작 노드 방문
  q.push(start);
  visited.insert(start);
  result.push_back(start);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    // ❷ 현재 노드와 인접한 노드 중 아직 방문하지 않는 노드 방문
    for (int neighbor : adjList[node]) {
      if (visited.find(neighbor) == visited.end()) {
        q.push(neighbor);
        visited.insert(neighbor);
        result.push_back(neighbor);
      }
    }
  }
}

vector<int> solution(vector<pair<int, int>> graph, int start) {
  // ❸ 인접 리스트 생성
  for (auto &edge : graph) {
    int u = edge.first;
    int v = edge.second;
    adjList[u].push_back(v);
  }

  // ❹ 시작 노드부터 너비 우선 탐색 시작
  bfs(start);

  return result;
}

//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>

using namespace std;


void init()
{
  adjList.clear();
  result.clear();
 
}
void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
    
}

int main()
{
  
  print(solution({{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 8}, {5, 8}, {6, 9}, {7, 9}}, 1)); //출력값 : 1 2 3 4 5 6 7 8 9
  init();
  print(solution({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}}, 1)); //출력값 : 1 2 3 4 5 0
  return 0;
}

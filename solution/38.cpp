#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<char, vector<char>> adjList;
vector<char> result;
unordered_set<char> visited;

void dfs(char node) {
  //❶ 현재 node를 방문한 목록 및 방문한 경로 추가
  visited.insert(node);
  result.push_back(node);

  //❷ 현재 node와 인접한 노드 중, 방문하지 않은 node들에 대해 깊이우선탐색을 계속 진행
  for (char neighbor : adjList[node]) {
    if (visited.find(neighbor) == visited.end()) {
      dfs(neighbor);
    }
  }
}

vector<char> solution(vector<pair<char, char>> graph, char start) {
  //❸ 인접 리스트 생성
  for (auto& edge : graph) {
    char u = edge.first;
    char v = edge.second;
    adjList[u].push_back(v);
  }

  //❹ 시작 노드부터 깊이우선탐색 시작
  dfs(start);
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
  visited.clear();
}
void print(vector<char> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<char>(cout, " "));
  cout << endl;
    
}

int main()
{
  //bool 반환할 때 true는 1, false는 0 입니다.
  print(solution({{'A', 'B'}, {'B', 'C'}, {'C', 'D'}, {'D', 'E'}}, 'A')); //출력값 : A B C D E
  init();
  print(solution({{'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'E', 'F'}}, 'A')); //출력값 : A B D E F C

  return 0;
}

#include <vector>
#include <tuple>

using namespace std;

const int INF = 99999;
const int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

vector<int> solution(int start, int numNodes, const vector<tuple<int, int, int>> edges) {
  //❶ 그래프 및 방문 여부 초기화
  for (int i = 0; i < MAX_NODES; ++i) {
    fill_n(graph[i], MAX_NODES, INF);
    visited[i] = false;
  }
  
  //❷ 입력받은 간선 정보를 그래프로 표현
  for (const auto& [from, to, weight] : edges) {
    graph[from][to] = weight;
  }

  //❸ 시작 노드를 제외한 모든 노드의 최소 비용을 INF로 초기화
  vector<int> distances(numNodes, INF);
  distances[start] = 0;

  for (int i = 0; i < numNodes - 1; ++i) {
    int minDistance = INF;
    int closestNode = -1;

    //❹ 최소 거리 노드 찾기
    for (int j = 0; j < numNodes; ++j) {
      if (!visited[j] && distances[j] < minDistance) {
        minDistance = distances[j];
        closestNode = j;
      }
    }

    //❺ 찾은 노드를 방문 처리
    visited[closestNode] = true;

    //❻ 인접 노드에 대한 거리 업데이트
    for (int j = 0; j < numNodes; ++j) {
      int newDistance = distances[closestNode] + graph[closestNode][j];
      if (!visited[j] && graph[closestNode][j] != INF && newDistance < distances[j]) {
        distances[j] = newDistance;
      }
    }
  }

  return distances;
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
  
  print(solution(0, 3, {{0, 1, 9},{0, 2, 3},{1, 0, 5},{2, 1, 1}})); //출력값 : 0 4 3
  print(solution(0, 4, {{0, 1, 1}, {1, 2, 5}, {2, 3, 1}})); //출력값 : 0 1 6 7
  return 0;
}

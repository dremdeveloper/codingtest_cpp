#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 상호베타적 집합 정의
class DisjointSet {
private:
  vector<int> parent, rank;

public:
  DisjointSet(int size) : parent(size, -1), rank(size, 0) {}

  int find(int node) {
    if (parent[node] == -1) 
      return node;
      
    //❶ 경로 압축을 하면서 루트노드 찾기  
    return parent[node] = find(parent[node]); 
  }

  void merge(int node1, int node2) {
    int root1 = find(node1);
    int root2 = find(node2);

    if (root1 != root2) {
        
      //❷ 랭크 기반으로 합치기
      if (rank[root1] > rank[root2]) {
        parent[root2] = root1;
      } else if (rank[root1] < rank[root2]) {
        parent[root1] = root2;
      } else {
        parent[root2] = root1;
        rank[root1]++;
      }
    }
  }

  //❸ 같은 집합에 있는지 확인  
  bool isCycle(int node1, int node2) {
    return find(node1) == find(node2); 
  }
};

int solution(int n, vector<vector<int>> costs) {
    
  //❹ 비용을 기준으로 간선 정렬
  sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
  });

  DisjointSet disjointSet(n);
  int totalCost = 0;

  for (const auto& edge : costs) {
    int cost = edge[2];
    int node1 = edge[0];
    int node2 = edge[1];

    //❺ 사이클 확인 후 없을 경우 합병
    if (!disjointSet.isCycle(node1, node2)) {
      disjointSet.merge(node1, node2);
      totalCost += cost;
    }
  }

  return totalCost;
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  //bool 반환할 때 true는 1, false는 0 입니다.
  cout << solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}}) << endl; //출력값 : 4

  return 0;
}

#include <vector>

using namespace std;

vector<int> parents; 
vector<int> rankData;

// 문자를 숫자로 변환
int charToInt(char c) {
  return c - '0';
}

int find(int x) {
  // x의 부모가 자신인 경우 루트노드를 찾았으므로 반환    
  if (parents[x] == x) {
    return x; 
  }
  
  // 파인드 연산 시, 경로압축 사용
  parents[x] = find(parents[x]);
  
  return parents[x];
}

void unionSet(int x, int y) {
  int root1 = find(x);
  int root2 = find(y);

  // 루트 노드가 같을 경우 유니온 연산을 할 필요가 없음
  if (root1 != root2) {
    // 랭크기반 알고리즘으로 유니온 연산 수행  
    if (rankData[root1] < rankData[root2]) {
      parents[root1] = root2;
    } 
    else if (rankData[root1] > rankData[root2]) {
      parents[root2] = root1;
    } 
    else {
      parents[root2] = root1;
      rankData[root1]++;
    }
  }
}

vector<bool> solution(int k, vector<vector<char>> operations) {
  parents.resize(k);
  rankData.resize(k, 0);
  
  // 초기에 각 노드는 자신을 부모로 설정
  for (int i = 0; i < k; ++i) {
    parents[i] = i;
  }

  vector<bool> results;
  for (const auto& op : operations) {
    if (op[0] == 'u') {
      int x = charToInt(op[1]);
      int y = charToInt(op[2]);
      unionSet(x, y);
    } 
    else if (op[0] == 'f') {
      int x = charToInt(op[1]);
      int y = charToInt(op[2]);
      // 파인드 연산을 통화 x,y의 루트노드가 같은지 확인해서 결과 저장
      results.push_back(find(x) == find(y));
    }
  }

  return results;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>

using namespace std;

void init()
{
    parents.clear();
    rankData.clear();
}
void print(vector<bool> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<bool>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution(3, {{'u', '0', '1'}, {'u', '1', '2'}, {'f', '0', '2'}})); // 결과값 : 1
  init();
  print(solution(4, {{'u', '0', '1'}, {'u', '2', '3'}, {'f', '0', '1'}, {'f', '0', '2'}})); // 결과값 : 1 0
  
  return 0;
}

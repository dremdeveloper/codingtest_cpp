#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land) {
  // ➊ 각 행마다 이전 행에서의 최대 점수를 더해가며 최대 점수 누적
  for (int i = 1; i < land.size(); ++i) {
    for (int j = 0; j < 4; ++j) {
      // ➋ 이전 행에서 현재 열의 값을 제외한 나머지 열들 중에서 가장 큰 값을 더함
      int maxVal = 0;
      for (int k = 0; k < 4; ++k) {
        if (k != j) {
          maxVal = max(maxVal, land[i - 1][k]);
        }
      }
      land[i][j] += maxVal;
    }
  }
  // ➌ 마지막 행에서 얻을 수 있는 최대 점수를 반환
  return *max_element(land.back().begin(), land.back().end());
}



//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution({{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}}) << endl; //출력값 : 16
  
  return 0;
}

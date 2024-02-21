#include <vector>

using namespace std;

int solution(int N, vector<int> stations, int W) {
  int answer = 0;
  int location = 1; // ❶ 현재 탐색하는 아파트의 위치
  int idx = 0; // ❷ 설치된 기지국의 인덱스

  while (location <= N) {
    // ❸ 기지국이 설치된 위치에 도달한 경우
    if (idx < stations.size() && location >= stations[idx] - W) {
      location = stations[idx] + W + 1;
      idx++;
    }
    // ❹ 기지국이 설치되지 않은 위치인 경우
    else {
      // ➎ 기지국을 설치하고 해당 범위를 넘어감
      location += 2 * W + 1;
      answer++;
    }
  }

  return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
    cout << solution(11, {4, 11}, 1) << endl; // 3
    cout << solution(16, {9}, 1) << endl;   // 5
    return 0;
}

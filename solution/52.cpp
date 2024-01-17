#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
  int length = weak.size();
  //❶  weak 리스트 확장
  for (int i = 0; i < length; ++i) {
    weak.push_back(weak[i] + n);
  }

  //❷ 초기화
  int answer = dist.size() + 1;

  //❸ 시작점 설정 및 친구 순열 생성
  for (int start = 0; start < length; ++start) {
    do {
      //❹ 친구 배치 및 수 계산
      int cnt = 1;
      int position = weak[start] + dist[cnt - 1];
      
      //❺ 다음 weak 지점 확인
      for (int index = start; index < start + length; ++index) {
        if (position < weak[index]) {
          cnt += 1;
          //❻ 친구 수 초과 확인
          if (cnt > dist.size()) break; 
          position = weak[index] + dist[cnt - 1];
        }
      }
      
      //❼ 최소 친구 수 업데이트
      answer = min(answer, cnt);
    } while (next_permutation(dist.begin(), dist.end())); // 순열 생성
  }

  //❽ 결과 반환
  return answer > dist.size() ? -1 : answer;
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
   cout << solution(12, {1, 5, 6, 10},{1, 2, 3, 4}) << endl; //출력값 : 2
   cout << solution(12, {1, 3, 4, 9, 10},{3, 5, 7}) << endl; //출력값 : 1   
   
   return 0;
}

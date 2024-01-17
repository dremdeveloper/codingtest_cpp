#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int blue, int white) {
  // ❶ 격자의 총 개수 (파란색 격자 + 흰색 격자)
  int total_size = blue + white;
  // ❷ 세로 길이의 범위는 3부터 (파란색 격자 + 흰색 격자)의 제곱근
  for (int vertical = 3; vertical <= sqrt(total_size); ++vertical) {
    // ❸ 사각형 구성이 되는지 확인
    if (total_size % vertical == 0) {
      int horizontal = total_size / vertical; // ❹ 사각형의 가로 길이
      // ❺ 카펫 형태로 만들 수 있는지 확인
      if (blue == (horizontal + vertical - 2) * 2) {
        return {horizontal, vertical}; // ❻ {가로 길이, 세로 길이}
      }
    }
  }
  return {}; // ❼ 만약 답을 찾지 못했다면 빈 벡터를 반환
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
  print(solution(10, 2)); //출력값 : 4 3
  print(solution(8, 1)); //출력값 : 3 3
  print(solution(24, 24)); //출력값 : 8 6
  
  return 0;
}

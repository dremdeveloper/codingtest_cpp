#include <bitset>

using namespace std;

int solution(int N) {
  return bitset<32>(N).count(); // 2진수로 변환한 N의 1의 개수를 반환
}




//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution(5) << endl; //출력값 : 2
  cout << solution(6) << endl; //출력값 : 2 
  cout << solution(5000) << endl; //출력값 : 5
  
  return 0;
}

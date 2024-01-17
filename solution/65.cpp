#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
  int transforms = 0;
  int removedZeros = 0;
  //❶  s가 “1”이 될때까지 계속 반복
  while (s != "1") {
    transforms++;

    //❷ '0' 개수를 세어 removedZeros에 누적
    removedZeros += count(s.begin(), s.end(), '0');

    //❸ '1' 개수를 세고, 이를 이진수로 변환
    int onesCount = count(s.begin(), s.end(), '1');
    s = bitset<32>(onesCount).to_string();
    s = s.substr(s.find('1'));
  }

  return {transforms, removedZeros};
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
  print(solution("110010101001")); //출력값 : 3 8
  print(solution("01110")); //출력값 : 3 3
  print(solution("1111111")); //출력값 : 4 1
  
  return 0;
}

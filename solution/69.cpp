#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board)
{
    //❶ 현재 위치를 나타 내는 크기가 2이고 값이 모두 0인 벡터 선언
    vector<int> v(2,0);
    
    //❷ 키 입력순으로 캐릭터 이동
    for(string s : keyinput)
    {
        if     (s=="up"    && v[1]<+board[1]/2) v[1]++;
        else if(s=="down"  && v[1]>-board[1]/2) v[1]--;
        else if(s=="left"  && v[0]>-board[0]/2) v[0]--;
        else if(s=="right" && v[0]<+board[0]/2) v[0]++;
    }

    return v;
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
  print(solution({"left", "right", "up", "right", "right"}, {11, 11})); //출력값 : 2 1 
  print(solution({"down", "down", "down", "down", "down"}, {7, 9})); //출력값 : 0 -4  
  
  return 0;
}

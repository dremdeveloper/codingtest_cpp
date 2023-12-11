#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  //❶ 보드판의 열의 크기만큼 스택을 생성 
  stack<int> lanes[board[0].size()];
  //❷ 보드의 가장 밑의 행부터 위로 올라가먼서 순회 
  for(int i = board.size()-1 ; i >= 0; --i) {
    for(int j = 0; j<board[0].size(); ++j) {
     //❸ 블럭이 있는 경우 해당 열에 해당되는 스택에 푸시 
      if(board[i][j]) {
        lanes[j].push(board[i][j]);
      }
    }
  }

 // 보드판에서 꺼낸 인형을 담을 bucket과 사라진 인형의 개수를 저장할 answer 선언
  stack<int> bucket;
  int answer = 0;

  for(int m : moves) {
   //❹ 해당 lane에 블럭이 있으면
    if(lanes[m-1].size()){
      int doll = lanes[m-1].top();
      lanes[m-1].pop();
     //❺ 버킷에 블럭이 있고, 가장 최근에 들어간 블럭과 현재 블럭이 같은지 확인
      if (bucket.size() && bucket.top() == doll) {
        bucket.pop();
        answer += 2;
      } else {
        bucket.push(doll);
      }
    }
  }

  return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
    
    cout << solution( { {0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} }, {1, 5, 3, 5, 1, 2, 1, 4} ) << endl; // 4
    return 0;
}
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
   
   //❶삭제 된 행의 인덱스를 저장 
    stack<int> deleted;
   //❷ 각 행의 위아래에 있는 행의 인덱스를 저장 
    vector<int> up;
    vector<int> down;

    for (int i = 0; i < n + 2; i++) {
        up.push_back(i - 1);
        down.push_back(i + 1);
    }
  //❸ 임시공간을 고려한 현재위치 
  k++;

  //❹ 주어진 명령어를 순회  
  for (int i = 0; i < cmd.size(); i++) {
        //❺ 현재 위치를 삭제하고 그 다음 위치로 이동
        if (cmd[i][0] == 'C') {
            deleted.push(k);
            down[up[k]] = down[k];
            up[down[k]] = up[k];

            if (down[k] == n + 1) k = up[k];
            else k = down[k];
        }

        //❻ 가장 최근에 삭제한 행을 복원
        else if (cmd[i][0] == 'Z') {
            int r = deleted.top();
            down[up[r]] = r;
            up[down[r]] = r;
            deleted.pop();
        } 

        //❼  현재 행을 주어진 값 만큼 위혹은 아래로 이동
        else { 
            int sz = stoi(cmd[i].substr(2));
            
            if (cmd[i][0] == 'U') {
                for (int j = 0; j < sz; j++) {
                    k = up[k];
                }
            }
                  
            else if (cmd[i][0] == 'D') {
                for (int j = 0; j < sz; j++) {
                    k = down[k];
                }
            }
        }
        
    }

    string answer;
   
    //❽ 삭제된 행의 위치에 “X”, 그렇지 않은 행의 위치에 “X” 로 표시한 문자열 반환
    answer.append(n, 'O');
    while (!deleted.empty()) {
        answer[deleted.top() - 1] = 'X';
        deleted.pop();
    }

    return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
    
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << endl;              //OOOOXOOO
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"}) << endl;  //OOXOXOOO
    return 0;
}

#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {

  //❶ N*N 2차원 벡터를 선언하고 초깃값을 0으로 함
  vector<vector<int>> snail_array(n, vector<int>(n, 0));
  int num = 1;
  // 행과 열의 시작과 끝 인덱스를 설정
  int start_row = 0, end_row = n - 1;
  int start_col = 0, end_col = n - 1;

  //❷ 제일 외각부터 달팽이 수열 규칙대로 채움
  while (start_row <= end_row && start_col <= end_col) {
    // 가장 왼쪽 윗부분 에서 가장 아래 바로 직전 까지  채우기
    for (int i = start_col; i <= end_col; ++i) {
      snail_array[start_row][i] = num++;
    }
    ++start_row;

    // 가장 왼쪽  아래부분 에서 가장 오른쪽 바로 직전 까지 채우기
    for (int i = start_row; i <= end_row; ++i) {
      snail_array[i][end_col] = num++;
    }
    --end_col;

    // 가장 오른쪽 아래부분 에서 가장 위 바로 직전 까지 채우기
    if (start_row <= end_row) {
      for (int i = end_col; i >= start_col; --i) {
        snail_array[end_row][i] = num++;
      }
      --end_row;
    }

    // 가장 윗부분 에서 가장 왼쪽 바로 직전 까지 채우기
    if (start_col <= end_col) {
      for (int i = end_row; i >= start_row; --i) {
        snail_array[i][start_col] = num++;
      }
      ++start_col;
    }
  }

  return snail_array;
}



//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>

using namespace std;

void print(vector<vector<int>> vec)
{
  for(int i = 0 ; i < vec.size(); i++){
    copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
  }
  
}

int main()
{
    print(solution(3));
    /*
    출력값 :
    1 2 3 
    8 9 4 
    7 6 5
    */
                    
    print(solution(4));
    /*
    출력값: 
    1 2 3 4 
    12 13 14 5 
    11 16 15 6 
    10 9 8 7
    */
  return 0;
}

#include <vector>

using namespace std;

vector<vector<int>> multiply(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
  //❶ 결과값을 저장할 벡터를  0으로 초기화
  vector<vector<int>> result(3, vector<int>(3, 0));

  //❷ 행렬 곱셈을 수행합니다.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  return result;
}

vector<vector<int>> transpose(vector<vector<int>> matrix) {
  //❸ 결과 행렬을 0으로 초기화합니다.
  vector<vector<int>> result(3, vector<int>(3, 0));

  //❹ 전치 행렬을 계산합니다.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      result[j][i] = matrix[i][j];
    }
  }

  return result;
}

vector<vector<int>> solution(vector<vector<int>> matrix1, vector<vector<int>>matrix2) {
  //❺ 주어진 두 행렬을 곱합니다.
  vector<vector<int>> multiplied = multiply(matrix1, matrix2);

  //❻ 곱셈 결과의 전치 행렬을 계산합니다.
  vector<vector<int>> transposed = transpose(multiplied);
  return transposed;
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
    print(solution( {
                     {1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9},
                    },
                    {
                     {9, 8, 7},
                     {6, 5, 4},
                     {3, 2, 1},
                    }
                    ));
    /*
    출력값 :
    30 84 138 
    24 69 114 
    18 54 90 
    */
                    
    print(solution( {
                     {2, 4 ,6},
                     {1, 3, 5},
                     {7, 8, 9},
                    },
                    {
                     {9, 1, 2},
                     {4, 5, 6},
                     {7, 3, 8},
                    }
                    ));
    /*
    출력값: 
    76 56 158 
    40 31 74 
    76 60 134 
    */
  return 0;
}

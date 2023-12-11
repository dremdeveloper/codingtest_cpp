#include <string>
#include <vector>

using namespace std;

vector<vector<int> > solution(vector<vector<int> >arr1, vector<vector<int> >arr2)
{
  // ❶ 최종 행렬곱의 결과를 저장할 벡터 선언
    vector<vector<int> >answer;
    
   // ❷ arr1과 arr2의 행렬곱을 수행했을때 최종적인 행렬의 크기만큼 공간을 할당
   answer.assign(arr1.size(), vector<int>(arr2[1].size(), 0));

// ❸ arr1의 각 행과 arr2의 각 열에 대해 반복문 수행
  for(int i = 0;i < arr1.size(); i++) 
     for(int j = 0;j < arr2[1].size(); j++)      
         for(int k = 0;k < arr2.size(); k++)
           // ❹ 두 행렬을 곱을 수행 
            answer[i][j] += arr1[i][k] * arr2[k][j];

    return answer;
}


//아래 코드는 테스트 코드 입니다.

#include <iterator>
#include <iostream>
void print2D(vector<vector<int>> vec)
{
    for(const auto& innerVec : vec){
        copy(innerVec.begin(), innerVec.end(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    
    cout << endl;
}

int main()
{
    print2D(solution({{1, 4}, {3, 2}, {4, 1}} ,{{3, 3}, {3,3}}));
    /*
      15 15
      15 15
      15 15
    */
    print2D(solution({{2, 3, 2}, {4, 2, 4}, {3, 1,4}}, {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}} ));     // 1 2 3 
    /*
      22 22 11
      36 28 18
      29 20 14
    */
    
    return 0;
}

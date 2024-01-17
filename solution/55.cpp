#include <vector>

using namespace std;

vector<int> solution(vector<int> arr1, vector<int> arr2) {
  //❶ 두 배열을 정렬된 상태로 병합하는 배열
  vector<int> merged;
  int i = 0, j = 0;  

  //❷ 두 배열을 순회하면서 정렬된 배열을 생성
  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] <= arr2[j]) {
      merged.push_back(arr1[i]);
      i++;
    } else {
      merged.push_back(arr2[j]);
      j++;
    }
  }

  //❸ arr1이나 arr2 중 남아있는 원소들을 정렬된 배열 뒤에 추가
  while (i < arr1.size()) {
    merged.push_back(arr1[i]);
    i++;
  }
  while (j < arr2.size()) {
    merged.push_back(arr2[j]);
    j++;
  }

  return merged;
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
  print(solution({1, 3, 5}, {2, 4, 6})); // 출력값 : 1 2 3 4 5 6
  print(solution({1, 3, 5}, {4, 5, 6})); // 출력값 : 1 2 3 4 5 6
  
  return 0;
}


#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    //❶ 각 크기에 따른 귤의 개수는 세는 counter
    unordered_map<int, int> counter;

    //❷ 크기별로 귤의 개수를 셈
    for (int i = 0; i < tangerine.size(); ++i) {
        counter[tangerine[i]]++;
    }

    //❸ 각 귤의 개수만 저장 후, 이를 내림차순 정렬
    vector<int> sorted_counts;
    for (const auto& kv : counter) {
        sorted_counts.push_back(kv.second);
    }
    sort(sorted_counts.rbegin(), sorted_counts.rend());

    
    int num_types = 0; // 현재까지 고른 귤의 종류
    int count_sum = 0; // 현재까지 귤 개수의 총 합

   //❹ 가장 많은 귤의 개수부터 순회
    for (int count : sorted_counts) {
        count_sum += count;
        num_types++;
   
        //❺ 귤의 개수 합이 k 이상 되는 순간 종료
        if (count_sum >= k) {
            break;
        }
    }

    return num_types;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution(6, {1, 3, 2, 5, 4, 5, 2, 3}) << endl; //출력값 : 3
  cout << solution(4, {1, 3, 2, 5, 4, 5, 2, 3}) << endl; //출력값 : 2
  cout << solution(2, {1, 1, 1, 1, 2, 2, 2, 3}) << endl; //출력값 : 1
  
  return 0;
}

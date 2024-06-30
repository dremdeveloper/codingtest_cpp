//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

#include <iostream>
#include <vector>

using namespace std;

// 사용할 숫자들
vector<int> nums = {1, 2, 3, 4}; 
// 목표 합
int target = 5; 
// 현재 조합
vector<int> current; 

void findCombinations(int index) {
    int sum = 0;
    for (int num : current) {
        sum += num;
    }

    // 조건 1: 현재 조합으로 합이 target이 되면 결과를 출력하고 더 탐색하지 않음
    if (sum == target) {
        for (int num : current) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // 조건 2: 합이 target을 초과하면 더 탐색하지 않음
    if (sum > target) {
        return;
    }

    // 유망한 경우에만 다음 숫자를 추가하여 탐색을 계속함
    for (int i = index; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        findCombinations(i + 1);
        current.pop_back(); // 현재 숫자를 조합에서 제외하여 다음 경우를 탐색
    }
}

int main() {
    findCombinations(0);
    return 0;
}

/*
출력값:
1 4 
2 3 
*/


/*
Call trace: findCombinations({ 1 }, 1, 1)
  Call trace: findCombinations({ 1 2 }, 2, 2)
    Call trace: findCombinations({ 1 2 3 }, 3, 3)
      Pruned branch: sum(6) > target(5) // Pruned branch: 현재 합이 목표 값보다 크므로 더 이상 탐색 하지 않음.
    Call trace: findCombinations({ 1 2 4 }, 4, 3)
      Pruned branch: sum(7) > target(5) // Pruned branch: 현재 합이 목표 값보다 크므로 더 이상 탐색하지 않음.
  Call trace: findCombinations({ 1 3 }, 3, 2)
    Call trace: findCombinations({ 1 3 4 }, 4, 3)
      Pruned branch: sum(8) > target(5) // Pruned branch: 현재 합이 목표 값보다 크므로 더 이상 탐색하지 않음.
  Call trace: findCombinations({ 1 4 }, 4, 2)
    Found combination: { 1 4 } // Found combination: 현재 합이 목표 값과 일치하므로 조합을 출력하고 백트래킹함.
Call trace: findCombinations({ 2 }, 2, 1)
  Call trace: findCombinations({ 2 3 }, 3, 2)
    Found combination: { 2 3 } // Found combination: 현재 합이 목표 값과 일치하므로 이 조합을 출력하고 백트래킹함.
  Call trace: findCombinations({ 2 4 }, 4, 2)
    Pruned branch: sum(6) > target(5) // Pruned branch: 현재 합이 목표 값보다 크므로 더 이상 탐색하지 않음.
Call trace: findCombinations({ 3 }, 3, 1)
  Call trace: findCombinations({ 3 4 }, 4, 2)
    Pruned branch: sum(7) > target(5) // Pruned branch: 현재 합이 목표 값보다 크므로 더 이상 탐색하지 않음.
Call trace: findCombinations({ 4 }, 4, 1)

*/

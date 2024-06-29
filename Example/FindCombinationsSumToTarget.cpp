//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

#include <iostream>
#include <vector>

using namespace std;

// 백트래킹의 개념: 가능한 모든 경우의 수를 탐색하기 위해서, 후보군을 점차적으로 만들어가면서 유망하지 않은 후보군은 배제하고 유망한 후보군만을 선택하여 탐색을 진행하는 방법이다.
// 유망함수의 개념: 현재까지의 조합이 문제의 조건을 만족하는지, 더 탐색해도 될지 여부를 판단하여 탐색의 가지를 치는 함수이다. 유망하지 않으면 가지를 더 탐색하지 않는다.

/*
문제 정의
 - 현재 조합으로 합의 5가 되면 더이상 탐색할 필요가 없음
 - 해당 숫자를 조합하여 합이 K 이상이 되면 탐색할 필요가 없음
*/

vector<int> nums = {1, 2, 3, 4}; // 사용할 숫자들
int target = 5; // 목표 합
vector<int> current; // 현재 조합

void findCombinations(int index, int level) {
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
        findCombinations(i + 1, level + 1);
        current.pop_back(); // 현재 숫자를 조합에서 제외하여 다음 경우를 탐색
    }
}

int main() {
    findCombinations(0, 0);
    return 0;
}

/*
출력값:
Found combination: { 1 4 } // Found combination: 현재 합이 목표 값과 일치하므로 이 조합을 출력하고 백트래킹함.
Found combination: { 2 3 } // Found combination: 현재 합이 목표 값과 일치하므로 이 조합을 출력하고 백트래킹함.
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

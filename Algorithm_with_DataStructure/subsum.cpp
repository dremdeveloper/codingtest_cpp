//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
/*
백트래킹으로 부분합 찾기 알고리즘:
- 시간 복잡도: 최악의 경우 O(2^n) (n: 배열의 크기)
- 용도: 주어진 배열에서 특정 합을 가지는 부분 배열을 찾는 데 사용됩니다.
- 동작 과정:
  1. 현재 인덱스와 현재까지의 합을 기록하면서 재귀를 수행합니다.
  2. 목표 합을 초과하면 바로 이전 단계로 돌아갑니다(백트래킹).
  3. 목표 합을 달성하면 해당 부분 배열을 출력합니다.

도식화 :
findSubarrayWithSum(arr, 5, 0, 0, path=[])
    |--> (i=0) findSubarrayWithSum(arr, 5, 3, 1, path=[3]) 
            |--> (i=1) findSubarrayWithSum(arr, 5, 4, 2, path=[3, 1]) 
                    |--> (i=2) findSubarrayWithSum(arr, 5, 8, 3, path=[3, 1, 4])
                    |--> (i=3) findSubarrayWithSum(arr, 5, 6, 4, path=[3, 1, 2])
                    |--> (i=4) findSubarrayWithSum(arr, 5, 6, 5, path=[3, 1, 2])
            |--> (i=2) findSubarrayWithSum(arr, 5, 7, 3, path=[3, 4])
                    |--> (i=3) findSubarrayWithSum(arr, 5, 9, 4, path=[3, 4, 2])
                    |--> (i=4) findSubarrayWithSum(arr, 5, 9, 5, path=[3, 4, 2])
            |--> (i=3) findSubarrayWithSum(arr, 5, 5, 4, path=[3, 2]) *Hit
                    |--> (i=4) findSubarrayWithSum(arr, 5, 7, 5, path=[3, 2, 2])
            |--> (i=4) findSubarrayWithSum(arr, 5, 5, 5, path=[3, 2]) *Hit

    |--> (i=1) findSubarrayWithSum(arr, 5, 1, 2, path=[1])
            |--> (i=2) findSubarrayWithSum(arr, 5, 5, 3, path=[1, 4]) *Hit
                    |--> (i=3) findSubarrayWithSum(arr, 5, 7, 4, path=[1, 4, 2])
                    |--> (i=4) findSubarrayWithSum(arr, 5, 7, 5, path=[1, 4, 2])
            |--> (i=3) findSubarrayWithSum(arr, 5, 3, 4, path=[1, 2])
                    |--> (i=4) findSubarrayWithSum(arr, 5, 5, 5, path=[1, 2, 2]) *Hit
            |--> (i=4) findSubarrayWithSum(arr, 5, 3, 5, path=[1, 2])

    |--> (i=2) findSubarrayWithSum(arr, 5, 4, 3, path=[4])
            |--> (i=3) findSubarrayWithSum(arr, 5, 6, 4, path=[4, 2])
            |--> (i=4) findSubarrayWithSum(arr, 5, 6, 5, path=[4, 2])

    |--> (i=3) findSubarrayWithSum(arr, 5, 2, 4, path=[2])
            |--> (i=4) findSubarrayWithSum(arr, 5, 4, 5, path=[2, 2])

    |--> (i=4) findSubarrayWithSum(arr, 5, 2, 5, path=[2])
*/


#include <iostream>
#include <vector>
using namespace std;


void findSubarrayWithSum(vector<int>& arr, int target, int sum, int idx, vector<int>& path) {
    if (sum > target) // 목표 합 초과: 백트래킹
        return;
    if (sum == target) { // 목표 합 도달: 출력
        for (int n : path) cout << n << " ";
        cout << "\n";
        return;
    }
    for (int i = idx; i < arr.size(); i++) {
        path.push_back(arr[i]); // 현재 값을 경로에 추가
        findSubarrayWithSum(arr, target, sum + arr[i], i + 1, path); // 재귀 호출
        path.pop_back(); // 경로에서 현재 값을 제거 (백트래킹)
    }
}

int main() {
    vector<int> arr = {3, 1, 4, 2, 2};
    int targetSum = 5;
    vector<int> path;

    cout << "Subarrays with sum " << targetSum << ":\n";
    findSubarrayWithSum(arr, targetSum, 0, 0, path);
    return 0;
}

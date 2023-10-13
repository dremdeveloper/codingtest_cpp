//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
/*
선택 정렬 알고리즘:
- 시간 복잡도: O(n^2)
- 용도: 작은 리스트에서 활용 가능하며 메모리가 제한적인 경우에 유리합니다.
- 동작 과정:
  1. 주어진 리스트 중에서 최소값을 찾습니다.
  2. 그 값을 맨 앞에 위치한 값과 교체합니다.
  3. 맨 처음 위치를 제외한 나머지 리스트를 같은 방법으로 교체합니다.

도식화 예:
[9, 1, 6, 8, 4, 3, 2, 7]
-> 첫 번째 순회: 1(최소값)을 9와 교체
[1, 9, 6, 8, 4, 3, 2, 7]
-> 두 번째 순회: 2(최소값)를 9와 교체
[1, 2, 6, 8, 4, 3, 9, 7]
-> 세 번째 순회: 3(최소값)을 6과 교체
[1, 2, 3, 8, 4, 6, 9, 7]
...
*/


#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i; // 최소값의 인덱스를 저장
        for (int j = i+1; j < n; j++) {
            // 현재 선택된 최소값보다 작은 값이 있는 경우, 인덱스 갱신
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // 최소값과 현재 정렬되지 않은 부분의 첫 번째 원소를 교체
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    vector<int> arr = {9, 1, 6, 8, 4, 3, 2, 7};
    cout << "Original array: ";
    for (int a : arr) cout << a << " ";
    
    selectionSort(arr);
    
    cout << "\nSorted array: ";
    for (int a : arr) cout << a << " ";
    return 0;
}

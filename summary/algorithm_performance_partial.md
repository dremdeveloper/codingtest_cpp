
## 문제 요구 성능 파악 예시

예를 들어, 입력값으로 주어진 배열의 길이가 100만 이상일 때 O(n^2) 시간 복잡도의 알고리즘은 현실적으로 실행 시간이 너무 오래 걸릴 수 있습니다. 이 경우 O(n) 또는 O(n log n) 시간 복잡도의 알고리즘을 찾아야 합니다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // sort 함수 포함
using namespace std;

bool hasDuplicate(const vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end()); // O(n log n)
    for (size_t i = 1; i < sortedArr.size(); ++i) {
        if (sortedArr[i] == sortedArr[i - 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << (hasDuplicate(arr) ? "Duplicates found" : "No duplicates") << endl;
    return 0;
}
```

### STL 컨테이너 및 알고리즘의 시간복잡도

| 자료구조/알고리즘    | 접근      | 탐색      | 삽입      | 삭제      | 설명                                  |
|---------------------|----------|----------|----------|----------|-------------------------------------|
| 벡터(vector)        | O(1)     | O(n)     | O(n)     | O(n)     | 동적 배열, 크기 조절 가능               |
| 스택(stack)         | O(n)     | O(n)     | O(1)     | O(1)     | LIFO 구조                           |
| 큐(queue)           | O(n)     | O(n)     | O(1)     | O(1)     | FIFO 구조                           |
| 해시맵(unordered_map) | -        | O(1)     | O(1)     | O(1)     | 키-값 쌍, 순서 보장 안 함               |
| 해시셋(unordered_set) | -        | O(1)     | O(1)     | O(1)     | 고유한 값의 집합, 순서 보장 안 함         |
| 맵(map)             | O(log n) | O(log n) | O(log n) | O(log n) | 키-값 쌍, 키 순서대로 정렬               |
| 셋(set)             | -        | O(log n) | O(log n) | O(log n) | 고유한 값의 집합, 값 순서대로 정렬         |
| 우선순위 큐(priority_queue) | -  | -        | O(log n) | O(log n) | 힙 기반, 우선순위가 높은 요소 먼저 처리    |
| `find`              | O(n)     | -        | -        | -        | 범위 내 특정 값 찾기                    |
| `erase`             | O(n)     | -        | -        | O(n)     | 범위 내 요소 삭제                      |
| `next_permutation`  | O(n)     | -        | -        | -        | 다음 순열 생성                         |
| `max_element`       | O(n)     | -        | -        | -        | 범위 내 최대값 찾기                    |
| `min_element`       | O(n)     | -        | -        | -        | 범위 내 최소값 찾기                    |

### 예시: 의사코드 작성 과정 (초보자용)

문제: 주어진 배열에서 중복된 요소를 제거하고, 고유한 요소들로만 구성된 배열을 반환하세요

1. 입력 배열을 하나의 집합 자료구조에 삽입합니다.
2. 집합 자료구조는 중복된 요소를 허용하지 않으므로, 자동으로 중복 요소가 제거됩니다.
3. 집합을 다시 배열로 변환하여 반환합니다.

```pseudocode
function removeDuplicates(arr):
    set s = new set
    for element in arr:
        add element to set s
    return list of elements in set s
```

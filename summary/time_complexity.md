
# 알고리즘 성능 측정 및 공간 복잡도 고려

## 시간 복잡도(Time Complexity)

알고리즘의 성능을 측정하는 데 있어 중요한 척도는 시간 복잡도입니다. 시간 복잡도는 알고리즘이 실행되는 데 걸리는 시간을 입력값의 크기와 관련지어 표현한 것입니다. 입력값이 커질수록 알고리즘의 실행 시간이 어떻게 변하는지를 나타내며, 이를 통해 알고리즘의 효율성을 평가할 수 있습니다.

### 시간 복잡도 예시

간단한 예시로, 배열의 모든 요소를 더하는 함수의 시간 복잡도를 살펴보겠습니다.

```cpp
int sumArray(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}
```

위 함수의 시간 복잡도는 O(n)입니다. 배열의 길이가 n일 때, 모든 요소를 한 번씩 방문하여 더하기 때문입니다.

## 문제 요구 성능 파악

문제에서 요구하는 성능을 파악하기 위해서는 주어진 입력값을 통해 시간 복잡도를 구하고 이를 기준으로 성능을 분석해야 합니다. 이는 주어진 문제를 해결하는 데 있어 적합한 알고리즘을 선택하는 데 중요한 역할을 합니다.
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
## 재귀 함수와 공간 복잡도

재귀 함수를 사용할 때는 시간 복잡도뿐만 아니라 공간 복잡도도 고려해야 합니다. 재귀 함수는 호출될 때마다 함수 코드 영역, 함수에서 사용하는 변수 영역, 매개변수 영역이 메모리에 할당됩니다. 예를 들어, 10!을 구할 때는 메모리에 10개의 함수 호출이 쌓이게 됩니다.

### 예시: 재귀 함수의 메모리 사용
```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);  // 각 호출마다 메모리에 함수 정보가 쌓임
}

int main() {
    int result = factorial(10);  // 10!을 계산
    cout << "10! = " << result << endl;
    return 0;
}
```
위 예시에서 `factorial` 함수는 재귀 호출될 때마다 스택에 함수 호출 정보가 쌓입니다. 이는 메모리를 많이 사용할 수 있다는 점에서 주의해야 합니다.

## 자료구조와 시간 복잡도

각 언어에서 제공하는 자료구조의 메서드의 시간 복잡도를 이해하고 정리하는 것은 중요합니다. 단순히 GitHub에서 제공하는 코드를 복사해서 사용하는 것이 아니라, 직접 구현해보고 성능 차이를 이해해야 합니다. 이를 통해 문제 분석 후 요구하는 성능에 맞는 구현 전략을 세울 수 있습니다.

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


## 코드 개선과 시간 복잡도

시간 제한 초과(TLE) 문제를 해결하기 위해서는 시간 복잡도를 고려하여 연산 횟수가 많은 부분을 찾아 개선해야 합니다. 전체 코드에서 시간이 많이 소요되는 부분을 찾아 효율적인 알고리즘으로 대체함으로써 성능을 개선할 수 있습니다.

### 예시: 코드 개선
아래는 배열에서 중복된 요소를 제거하는 코드의 예시입니다.

**개선 전:**
```cpp
#include <vector>
using namespace std;

vector<int> removeDuplicates(const vector<int>& arr) {
    vector<int> result;
    for (int i : arr) {
        if (find(result.begin(), result.end(), i) == result.end()) {
            result.push_back(i);
        }
    }
    return result;
}
```
위 코드는 중복 검사를 위해 `find` 함수를 사용하므로 시간 복잡도는 O(n^2)입니다. `find` 함수는 벡터에서 특정 값을 찾는 데 O(n)의 시간이 걸리고, 이를 모든 요소에 대해 반복하기 때문에 O(n^2)의 시간 복잡도가 됩니다.

**개선 후:**
```cpp
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> removeDuplicates(const vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end());  // O(n)
    return vector<int>(s.begin(), s.end());        // O(n)
}
```
`unordered_set` 자료형을 사용하면 시간 복잡도가 O(n)으로 개선됩니다. `unordered_set`은 해시 기반의 자료구조로, 삽입과 검색이 평균적으로 O(1)의 시간 복잡도를 가지기 때문입니다. 따라서 전체 중복 제거 과정은 O(n)의 시간 복잡도를 갖습니다.

## 의사코드(Pseudocode)

의사코드는 구현하기 전 데이터의 흐름을 정리하고, 로직을 명확히 하는 데 사용됩니다. 이는 문제 해결 과정에서 중요한 단계로, 전체 시간의 60~70%를 할애할 가치가 있습니다. 
구현 단계는 3 ~ 40% 정도로 시간 배분을 하면 좋습니다.

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
---

## 결론

- 시간 복잡도는 알고리즘 성능 측정의 중요한 척도입니다.
- 재귀 함수를 사용할 때는 공간 복잡도도 고려해야 합니다.
- 자료구조의 각 메서드의 시간 복잡도를 이해하고 정리하는 것이 중요합니다.
- 코드 개선 시 시간 복잡도를 고려하여 주요 연산 부분을 최적화해야 합니다.
- 의사코드를 통해 데이터 흐름을 정리하고 구현 전 로직을 명확히 해야 합니다.

학습 과정에서 복사 붙여넣기가 아니라 직접 구현하고 성능 차이를 이해하는 것이 중요합니다. 이를 통해 문제 분석 후 적절한 구현 전략을 세울 수 있는 능력을 키워야 합니다.

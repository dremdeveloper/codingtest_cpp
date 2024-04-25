//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

/*
삽입 정렬 알고리즘:
- 시간 복잡도: 최악의 경우 O(n^2), 최선의 경우 O(n)
- 용도: 작은 데이터 셋에서 효율적이며, 이미 부분적으로 정렬된 배열에서 높은 성능을 보입니다.
- 동작 과정:
  1. 첫 번째 원소를 정렬된 부분으로 간주합니다.
  2. 다음 원소를 정렬된 부분과 비교하여, 올바른 위치에 삽입합니다.
  3. 모든 원소가 정렬된 부분에 삽입될 때까지 2의 과정을 반복합니다.

도식화 예:
입력 배열: [5, 2, 9, 1, 5, 6]
첫 번째 패스: [5| 2, 9, 1, 5, 6]  => |의 왼쪽은 정렬된 부분
두 번째 패스: [2, 5| 9, 1, 5, 6]  => 2를 정렬된 부분의 올바른 위치에 삽입
세 번째 패스: [2, 5, 9| 1, 5, 6]  => 9는 이미 올바른 위치에 있음
네 번째 패스: [2, 5, 9| 1, 5, 6]  => 1을 정렬된 부분의 올바른 위치, 즉 배열의 맨 앞에 삽입
다섯 번째 패스: [1, 2, 5, 9| 5, 6] => 5를 정렬된 부분의 올바른 위치, 즉 5 바로 앞에 삽입
여섯 번째 패스: [1, 2, 5, 5, 9| 6] => 6을 정렬된 부분의 올바른 위치, 즉 9 바로 앞에 삽입
완료된 정렬: [1, 2, 5, 5, 6, 9]
*/


#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;

        // 정렬된 부분에서 key를 삽입할 위치를 찾는다.
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    insertionSort(arr);

    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
힙 정렬 알고리즘:
- 시간 복잡도: O(n log n)
- 용도: 데이터를 오름차순 또는 내림차순으로 정렬할 때 사용.

도식화 예:
입력 배열: [3, 1, 4, 1, 5, 9, 2, 6]

1단계: 힙 만들기
[9, 5, 4, 1, 3, 1, 2, 6]
가상의 트리 구조로 나타낼 때:
        9
       / \
      5   4
     /|   |\
    1 3   1 2
   / \
  6   [empty]

2단계: 정렬 과정 시작 - 루트(현재 최대값)와 마지막 노드 교환
[6, 5, 4, 1, 3, 1, 2, 9]
        6
       / \
      5   4
     /|   |\
    1 3   1 2
   / \
  9   [empty]

3단계: 힙 복원
[6, 5, 4, 1, 3, 1, 2, 9]
        6
       / \
      5   4
     /|   |\
    1 3   1 2
   / \
  9   [empty]

(동일한 힙 구조이므로 그림은 생략)

4단계: 다시 루트와 마지막 노드(현재 힙의 마지막) 교환
[2, 5, 4, 1, 3, 1, 6, 9]
        2
       / \
      5   4
     /|   |\
    1 3   1 6
   / \
  9   [empty]

5단계: 힙 복원
[5, 3, 4, 1, 2, 1, 6, 9]
        5
       / \
      3   4
     /|   |\
    1 2   1 6
   / \
  9   [empty]

... 이런 식으로 계속 과정이 진행됩니다.

완료된 정렬:
[1, 1, 2, 3, 4, 5, 6, 9]
*/

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    
    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Extract elements from heap
    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};

    heapSort(arr);

    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
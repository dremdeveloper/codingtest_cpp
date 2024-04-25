//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

/*
머지 정렬(Merge Sort)은 분할 정복 알고리즘의 한 예입니다.
- 시간 복잡도: O(n log n)
- 용도: 대규모 데이터 정렬에 유용 (안정 정렬)
- 동작 과정:
    1. 리스트를 두 부분으로 나눕니다.
    2. 각 부분을 재귀적으로 정렬합니다.
    3. 두 부분을 병합하여 결과를 얻습니다.

도식화 예:
Original: [38, 27, 43, 3, 9, 82, 10]
1. Divide: [38, 27, 43, 3], [9, 82, 10]
2. Divide: [38, 27], [43, 3], [9, 82], [10]
3. Merge: [27, 38], [3, 43], [9, 82], [10]
4. Merge: [3, 27, 38, 43], [9, 10, 82]
5. Merge: [3, 9, 10, 27, 38, 43, 82]
*/

#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    // Step 1: Divide the array into two halves
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    // Step 2: Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Step 3: Merge the temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Step 4: Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Step 5: Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r)
        return; // returns recursively

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m); // Sort first half
    mergeSort(arr, m + 1, r); // Sort second half
    merge(arr, l, m, r); // Merge the sorted halves
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = arr.size();

    cout << "Given array is \n";
    for(auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array is \n";
    for(auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

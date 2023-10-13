//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
/*
머지 정렬(Merge Sort)은 분할 정복 알고리즘의 한 예입니다.
- 시간 복잡도: O(n log n)
- 용도: 대규모 데이터 정렬에 효과적임 (안정 정렬)
- 동작 과정:
    1. 리스트를 두 부분으로 나눕니다.
    2. 각 부분을 재귀적으로 정렬합니다.
    3. 두 부분을 병합하여 결과를 얻습니다.

도식화 예:
원본: [38, 27, 43, 3, 9, 82, 10]
1. 분할: [38, 27, 43, 3], [9, 82, 10]
2. 분할: [38, 27], [43, 3], [9, 82], [10]
3. 병합: [27, 38], [3, 43], [9, 82], [10]
4. 병합: [3, 27, 38, 43], [9, 10, 82]
5. 병합: [3, 9, 10, 27, 38, 43, 82]
*/

#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    // 단계 1: 배열을 두 개의 하위 배열로 나눕니다.
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    // 단계 2: 임시 배열 L[]과 R[]에 데이터를 복사합니다.
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // 단계 3: 임시 배열들을 arr[l..r]로 병합합니다.
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

    // 단계 4: 남은 L[]의 요소를 복사, 있다면
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 단계 5: 남은 R[]의 요소를 복사, 있다면
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r)
        return; // 재귀적으로 반환합니다.

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m); // 첫 번째 절반 정렬
    mergeSort(arr, m + 1, r); // 두 번째 절반 정렬
    merge(arr, l, m, r); // 정렬된 절반 병합
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = arr.size();

    cout << "주어진 배열은 \n";
    for(auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "정렬된 배열은 \n";
    for(auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

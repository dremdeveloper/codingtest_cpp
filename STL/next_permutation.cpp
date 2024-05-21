//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm> // for std::next_permutation and std::sort
using namespace std;

// 벡터의 모든 순열을 출력하는 함수
void print_permutations(vector<int> v) {
    do {
        // 현재 순열 출력
        for (int num : v) {
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}

int main() {
    // 예시 벡터 생성
    vector<int> v = {3, 2, 1};

    // 정렬되지 않은 경우
    cout << "정렬되지 않은 경우:\n";
    vector<int> v_unsorted = v;
    print_permutations(v_unsorted);

    // 벡터를 정렬된 상태로 만들기
    sort(v.begin(), v.end());

    // 정렬된 경우
    cout << "\n정렬된 경우:\n";
    vector<int> v_sorted = v;
    print_permutations(v_sorted);

    return 0;
}

/*
출력값:

정렬되지 않은 경우:
3 2 1

정렬된 경우:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/

// next_permutation에 대한 설명
/*
std::next_permutation 함수는 주어진 범위에서 사전식 순서로 다음 순열을 생성합니다.
이 함수는 내부적으로 요소의 순서를 비교하여 다음 순열을 만듭니다.

주의해야 할 점:
1. 정렬된 상태에서 사용: next_permutation 함수는 범위가 정렬된 상태에서 시작할 때 모든 순열을
   올바르게 생성할 수 있습니다. 정렬되지 않은 상태에서 시작하면 모든 순열을 생성하지 못합니다.
2. 반환값: 다음 순열이 존재하면 true를 반환하고, 더 이상 다음 순열이 없으면 false를 반환하여
   주어진 범위를 처음 순열(가장 작은 순열)로 재설정합니다.
3. 시간 복잡도: 함수 자체의 시간 복잡도는 O(N)입니다. 모든 순열을 생성하기 위해 반복적으로
   호출하면 총 시간 복잡도는 O(N * N!)이 됩니다. 여기서 N은 요소의 수입니다.
*/

// next_permutation 사용 예:
/*
벡터가 {1, 2, 3}로 주어졌을 때,
next_permutation(v.begin(), v.end())를 호출하면,
벡터는 {1, 3, 2}로 변환됩니다.

벡터가 {3, 2, 1}로 주어졌을 때,
next_permutation(v.begin(), v.end())를 호출하면,
벡터는 다시 {1, 2, 3}로 재설정됩니다.
*/


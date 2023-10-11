//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 순열은 가능한 모든 원소의 조합을 의미합니다.
// - STL의 next_permutation은 주어진 범위의 원소를 재배치하여 사전 순으로 다음 순열을 생성합니다.
// 좋은 사용 시기:
// - 가능한 모든 원소의 조합을 순차적으로 생성하고 싶을 때. 예를 들면, 완전 탐색 알고리즘에서 사용될 수 있습니다.
// 성능 이슈:
// - next_permutation은 원소의 수에 따라 많은 수의 순열을 생성할 수 있습니다. 원소의 수가 많아지면 가능한 모든 순열을 생성하는 데 많은 시간이 걸릴 수 있습니다.

int main() {

    vector<int> v = {1, 2, 3};

    // next_permutation: 주어진 범위의 원소를 재배치하여 다음 순열을 생성, O(n)
    do {
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    // 출력:
    // 1 2 3 
    // 1 3 2 
    // 2 1 3 
    // 2 3 1 
    // 3 1 2 
    // 3 2 1 

    return 0;
}


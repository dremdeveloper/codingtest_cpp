//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
/*
에라토스테네스의 체 알고리즘
- 시간 복잡도: O(n log(log n))
- 용도: 주어진 범위 내의 모든 소수를 찾음
- 동작 과정:
    1. 2부터 n까지의 숫자를 적습니다.
    2. 2를 남기고 2의 배수를 모두 지웁니다.
    3. 다음 소수(3)를 남기고, 3의 배수를 모두 지웁니다.
    4. 이 과정을 n의 제곱근까지 반복합니다.

도식화 예:
n = 30 일 때,
[2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]
-> 2의 배수 제거
[2, 3, _, 5, _, 7, _, 9, _, 11, _, 13, _, 15, _, 17, _, 19, _, 21, _, 23, _, 25, _, 27, _, 29, _]
-> 3의 배수 제거
[2, 3, _, 5, _, 7, _, _, _, 11, _, 13, _, _, _, 17, _, 19, _, _, _, 23, _, 25, _, _, _, 29, _]
-> 그 다음 소수(5)의 배수 제거
...
*/

#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> prime(n+1, true); // 모든 요소를 true로 초기화된 크기가 n+1인 벡터를 생성
    prime[0] = prime[1] = false; // 0과 1은 소수가 아니므로 false로 설정
    
    for (int i = 2; i*i <= n; i++) { 
        if (prime[i]) { // i가 소수인 경우
            //i*i 미만의 수들은 이미 이전의 다른 소수들에 의해 체크됩니다. 따라서 i*i부터 시작합니다.
            for (int j = i*i; j <= n; j += i) { 
                prime[j] = false; // i의 배수를 모두 false로 설정
            }
        }
    }

    // 소수 출력
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main() {
    int n = 30; // 30 이하의 소수를 찾습니다.
    cout << "The prime numbers less than or equal to " << n << " are: \n";
    sieveOfEratosthenes(n);
    return 0;
}

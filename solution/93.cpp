
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

// 주어진 숫자가 소수인지 판별하는 함수
bool isPrime(long long num) {
    if (num == 1) return false; // 1은 소수가 아님
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false; // 나누어 떨어지면 소수가 아님
    }
    return true;
}

// n을 k진수로 변환했을 때, 조건을 만족하는 소수의 개수를 반환하는 함수
int solution(int n, int k) {
    int answer = 0; // 조건을 만족하는 소수의 개수
    long long currentNum = 0; // 현재 확인 중인 숫자
    long long multiplier = 1; // k진수에서의 자릿수를 계산하기 위한 배수

    // n을 k진수로 변환하면서 소수를 확인
    while (n) {
        if (n % k == 0) { // k로 나누어떨어지면, 현재까지의 숫자를 소수 판별
            if (currentNum && isPrime(currentNum)) {
                answer++;
            }
            multiplier = 1; // 배수와 현재 숫자를 초기화
            currentNum = 0;
        } else { // k로 나누어떨어지지 않으면, 숫자를 생성
            currentNum += (n % k) * multiplier;
            multiplier *= 10;
        }
        n /= k; // 다음 자리 숫자로
    }
    
    // 마지막으로 남은 숫자에 대한 소수 판별
    if (currentNum && isPrime(currentNum)) {
        answer++;
    }

    return answer;
}

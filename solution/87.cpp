#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// v 벡터에서 dx 용량만큼 제거하는 함수
void RemoveCargo(vector<int> &cargo, int capacity) {
    while (!cargo.empty() && capacity) {
        // 현재 용량이 마지막 화물의 무게보다 크거나 같으면 화물을 제거
        if (cargo.back() <= capacity) {
            capacity -= cargo.back();
            cargo.pop_back();
        } else {
            // 현재 용량으로 화물의 무게를 감소시키고, 용량을 0으로 설정
            cargo.back() -= capacity;
            capacity = 0;
        }
    }
}

// 항구에서 화물을 옮기는 데 필요한 최소 시간을 계산하는 함수
long long solution(int cap, int n, vector<int> A, vector<int> B) {
    long long int answer = 0;
    while (!A.empty() || !B.empty()) {
        // A, B에서 무게가 0인 화물 제거
        while (!A.empty() && A.back() == 0) A.pop_back();
        while (!B.empty() && B.back() == 0) B.pop_back();
        
        // A와 B 중 더 긴 벡터의 길이를 dx로 설정
        int trips = max(A.size(), B.size());
        // 왕복 횟수를 계산하여 정답에 추가
        answer += trips * 2;
        
        // A, B에서 cap 용량만큼 화물 제거
        RemoveCargo(A, cap);
        RemoveCargo(B, cap);
    }

    return answer;
}

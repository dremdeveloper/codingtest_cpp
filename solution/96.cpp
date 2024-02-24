#include <string>
#include <vector>
#include <numeric>

using namespace std;

// 두 큐의 합을 같게 만들기 위해 필요한 최소 이동 횟수를 반환합니다.
int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL); // 첫 번째 큐의 합
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL); // 두 번째 큐의 합
    int idx1 = 0, idx2 = 0; // 각 큐에서의 현재 인덱스
    int totalMoves = 0; // 총 이동 횟수

    int qSize = queue1.size(); // 큐의 크기 (두 큐의 크기는 같습니다)
    int limit = qSize * 3; // 탐색할 최대 이동 횟수 (두 큐의 합을 맞추기 위한 이론적 최대 이동 횟수)

    while (totalMoves <= limit) {
        if (sum1 == sum2) return totalMoves; // 두 큐의 합이 같은 경우, 현재까지의 이동 횟수 반환
        if (sum1 < sum2) {
            long long elem = idx2 < qSize ? queue2[idx2] : queue1[idx2 - qSize]; // 다음에 이동할 원소
            sum1 += elem; // 첫 번째 큐의 합을 증가
            sum2 -= elem; // 두 번째 큐의 합을 감소
            idx2++; // 두 번째 큐의 인덱스 증가
        } else {
            long long elem = idx1 < qSize ? queue1[idx1] : queue2[idx1 - qSize]; // 다음에 이동할 원소
            sum1 -= elem; // 첫 번째 큐의 합을 감소
            sum2 += elem; // 두 번째 큐의 합을 증가
            idx1++; // 첫 번째 큐의 인덱스 증가
        }
        totalMoves++; // 총 이동 횟수 증가
    }

    return -1; // 두 큐의 합을 같게 만들 수 없는 경우 -1 반환
}

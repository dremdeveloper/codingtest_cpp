#include <string>
#include <vector>

using namespace std;

// 0부터 9까지의 수 중에서 입력된 배열에 없는 수의 합을 반환합니다.
int solution(vector<int> numbers) {
    // 0부터 9까지의 합은 45이므로 기본값을 45로 설정합니다.
    int answer = 45;

    // 입력된 numbers 배열의 각 요소를 answer에서 차감합니다.
    for (int number : numbers) {
        answer -= number;
    }

    // numbers 배열에 없는 수의 총합을 반환합니다.
    return answer;
}

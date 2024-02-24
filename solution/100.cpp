#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 로또의 최고 순위와 최저 순위를 찾는 함수
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    // 로또 순위를 정의 (0개 맞춤부터 6개 맞춤까지의 순위)
    int rank[7] = {6, 6, 5, 4, 3, 2, 1};
    unordered_map<int, int> winMap; // 당첨 번호를 저장하는 해시맵

    // 당첨 번호를 해시맵에 저장
    for (int win_num : win_nums) {
        winMap[win_num]++;
    }

    vector<int> answer(2, 0); // 최저 순위와 최고 순위를 저장할 벡터
    // 로또 번호를 확인하여 최고 순위와 최저 순위 계산
    for (int lotto : lottos) {
        // 0인 경우 미지의 번호로 최고 순위에만 영향을 줌
        if (lotto == 0) {
            answer[0]++;
            continue;
        }
        // 당첨 번호인 경우 최고 순위와 최저 순위에 모두 영향을 줌
        if (winMap.find(lotto) != winMap.end()) {
            answer[0]++;
            answer[1]++;
        }
    }

    // 최종 순위를 순위 테이블을 이용하여 업데이트
    answer[0] = rank[answer[0]];
    answer[1] = rank[answer[1]];

    return answer; // 최고 순위와 최저 순위 반환
}

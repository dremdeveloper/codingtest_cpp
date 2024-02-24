#include <string>
#include <vector>
#include <map>

using namespace std;

// 보석 쇼핑을 위해 선택해야 하는 구간을 찾는 함수
vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0); // 정답을 저장할 벡터, 시작 위치와 끝 위치를 저장
    map<string, int> gemTypes; // 모든 보석 종류와 개수
    map<string, int> possession; // 현재 구간에 있는 보석의 종류와 개수
    int start = 0, end = 0; // 탐색할 구간의 시작과 끝
    int minLen = gems.size() + 1; // 최소 구간 길이를 최대로 설정

    // 모든 보석 종류 파악
    for (const auto& gem : gems) {
        gemTypes[gem]++;
    }

    while (end < gems.size()) {
        possession[gems[end]]++; // 현재 보석 추가
        end++; // 구간의 끝을 확장

        // 현재 구간에 모든 종류의 보석이 포함되지 않은 경우
        if (possession.size() < gemTypes.size()) {
            continue;
        }

        // 시작점을 최대한 앞으로
        while (possession[gems[start]] > 1) {
            possession[gems[start]]--;
            start++;
        }

        // 최소 구간 길이보다 현재 구간이 더 작은 경우 결과 갱신
        if (end - start < minLen) {
            minLen = end - start;
            answer[0] = start + 1; // 시작점 조정 (1부터 시작)
            answer[1] = end; // 끝점
        }
    }

    return answer;
}

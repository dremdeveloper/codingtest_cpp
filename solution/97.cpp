#include <vector>
#include <algorithm>

using namespace std;

// A 팀이 이길 수 있는 최대 경기 수를 계산하는 함수
int solution(vector<int> A, vector<int> B) {
    // A와 B를 오름차순으로 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int AwinCount = 0; // A가 이길 수 있는 경기 수
    int Ai = 0; // A 팀의 현재 비교할 선수 인덱스
    int Bi = 0; // B 팀의 현재 비교할 선수 인덱스
    
    // A와 B의 모든 선수를 비교
    while (Bi < B.size()) {
        // A 팀의 선수가 B 팀의 선수보다 능력치가 낮은 경우, A 팀 승리
        if (A[Ai] < B[Bi]) {
            AwinCount++;
            Ai++;
        }
        Bi++; // B 팀의 다음 선수로 이동
    }
    
    return AwinCount; // A 팀이 이길 수 있는 최대 경기 수 반환
}

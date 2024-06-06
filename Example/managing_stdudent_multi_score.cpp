//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <numeric> // std::accumulate를 사용하기 위해 필요

using namespace std;

// 특정 학생의 점수를 출력하는 함수
void print_scores(const unordered_map<string, vector<int>>& student_scores, const string& name) {
    // 학생이 존재하는지 확인
    auto it = student_scores.find(name);
    if (it != student_scores.end()) {
        cout << name << "의 점수: ";
        // 학생의 모든 점수를 출력
        for (int score : it->second) {
            cout << score << " ";
        }
        cout << endl;
    } else {
        // 학생이 존재하지 않을 경우 메시지 출력
        cout << name << "의 점수를 찾을 수 없습니다." << endl;
    }
}

// 특정 학생의 평균 점수를 계산하고 출력하는 함수
void print_average_score(const unordered_map<string, vector<int>>& student_scores, const string& name) {
    // 학생이 존재하는지 확인
    auto it = student_scores.find(name);
    if (it != student_scores.end()) {
        const vector<int>& scores = it->second; // 학생의 점수 목록을 참조
        
        // 평균 점수 계산
        // accumulate 함수는 주어진 범위의 요소를 모두 더하는 함수입니다.
        // 첫 번째 인자는 시작 반복자, 두 번째 인자는 끝 반복자, 세 번째 인자는 초기값입니다.
        // 이 경우 scores 벡터의 모든 요소를 더하고 초기값 0.0에서 시작하여 결과를 double로 반환합니다.
        // accumulate 함수의 시간 복잡도는 O(n)입니다. 여기서 n은 벡터의 요소 개수입니다.
        double average = accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
        cout << name << "의 평균 점수: " << average << endl;
    } else {
        // 학생이 존재하지 않을 경우 메시지 출력
        cout << name << "의 점수를 찾을 수 없습니다." << endl;
    }
}

int main() {
    // 학생 이름을 키로 하고, 그 학생의 점수 목록을 벡터로 저장하는 unordered_map 선언
    unordered_map<string, vector<int>> student_scores;
    
    // 학생들의 점수를 추가합니다.
    student_scores["Alice"].push_back(90); // Alice의 점수 목록에 90 추가
    student_scores["Alice"].push_back(85); // Alice의 점수 목록에 85 추가
    student_scores["Bob"].push_back(78);   // Bob의 점수 목록에 78 추가
    student_scores["Bob"].push_back(82);   // Bob의 점수 목록에 82 추가
    student_scores["Bob"].push_back(88);   // Bob의 점수 목록에 88 추가
    
    // Alice의 점수를 출력
    print_scores(student_scores, "Alice");
    // Alice의 평균 점수를 출력
    print_average_score(student_scores, "Alice");
    
    // Bob의 점수를 출력
    print_scores(student_scores, "Bob");
    // Bob의 평균 점수를 출력
    print_average_score(student_scores, "Bob");
    
    // 존재하지 않는 학생 Charlie의 점수를 출력 시도
    print_scores(student_scores, "Charlie");
    // 존재하지 않는 학생 Charlie의 평균 점수를 출력 시도
    print_average_score(student_scores, "Charlie");
    
    return 0;
}

/*
출력 결과:
Alice의 점수: 90 85 
Alice의 평균 점수: 87.5
Bob의 점수: 78 82 88 
Bob의 평균 점수: 82.6667
Charlie의 점수를 찾을 수 없습니다.
Charlie의 점수를 찾을 수 없습니다.
*/

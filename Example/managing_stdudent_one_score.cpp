//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // unordered_map을 사용하여 학생 ID를 키로, 성적을 값으로 저장
    unordered_map<string, string> students;

    // 학생 정보 추가
    students["12345"] = "A";    // 학생 ID "12345"의 성적은 "A"
    students["67890"] = "B";    // 학생 ID "67890"의 성적은 "B"
    students["54321"] = "A+";   // 학생 ID "54321"의 성적은 "A+"

    // 특정 학생 정보 검색
    string student_id = "12345";  // 검색할 학생 ID 설정
    if (students.find(student_id) != students.end()) {
        // 학생 ID가 존재하면 성적을 출력
        cout << "학생 ID: " << student_id << "\n";      // 학생 ID 출력
        cout << "성적: " << students[student_id] << "\n"; // 해당 학생의 성적 출력
        // 출력값: 성적: A
    } else {
        // 학생 ID가 존재하지 않으면 에러 메시지 출력
        cout << "학생 정보를 찾을 수 없습니다.\n";
    }

    return 0;
}

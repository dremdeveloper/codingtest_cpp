#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 날짜를 연, 월, 일로 파싱하는 함수
void parseDate(const string& date, int& year, int& month, int& day) {
    year = stoi(date.substr(0, 4));
    month = stoi(date.substr(5, 2));
    day = stoi(date.substr(8, 2));
}

// 약관 기간을 매핑하는 함수
unordered_map<char, int> mapTerms(const vector<string>& terms) {
    unordered_map<char, int> termMap;
    for (const string& term : terms) {
        char type = term[0];
        int duration = stoi(term.substr(2));
        termMap[type] = duration;
    }
    return termMap;
}

// 개인정보 만료 여부를 확인하는 함수
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> expiredIndexes;
    int todayYear, todayMonth, todayDay;
    parseDate(today, todayYear, todayMonth, todayDay);

    auto termMap = mapTerms(terms);

    int index = 1; // 만료된 개인정보 인덱스를 추적
    for (const string& privacy : privacies) {
        int privacyYear, privacyMonth, privacyDay;
        parseDate(privacy, privacyYear, privacyMonth, privacyDay);

        char type = privacy[11]; // 개인정보 유형
        int durationMonths = termMap[type]; // 해당 유형의 약관 기간

        // 만료 날짜 계산
        privacyYear += (privacyMonth + durationMonths - 1) / 12;
        privacyMonth = (privacyMonth + durationMonths - 1) % 12 + 1; // 월이 0이 되는 경우 방지

        // 만료 여부 확인
        if (todayYear > privacyYear ||
            (todayYear == privacyYear && todayMonth > privacyMonth) ||
            (todayYear == privacyYear && todayMonth == privacyMonth && todayDay >= privacyDay)) {
            expiredIndexes.push_back(index);
        }
        index++;
    }

    return expiredIndexes;
}

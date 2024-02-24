#include <string>
#include <vector>

using namespace std;

// 문자열에서 마지막 '0'의 위치를 찾는 함수
int findLastZero(const string& str) {
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == '0') return i;
    }
    return -1;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (const string& originalStr : s) {
        string processedStr = ""; // 처리된 문자열을 저장할 변수
        int count110 = 0; // "110"이 나타난 횟수

        // 주어진 문자열에서 "110"을 찾아 제거하고 개수를 센다
        for (char ch : originalStr) {
            processedStr += ch;
            if (processedStr.length() >= 3 && processedStr.substr(processedStr.length() - 3) == "110") {
                processedStr.erase(processedStr.length() - 3);
                count110++;
            }
        }

        int lastZeroIndex = findLastZero(processedStr); // 마지막 '0'의 위치 찾기

        string result; // 최종 문자열을 저장할 변수
        if (lastZeroIndex == -1) {
            // '0'이 없는 경우, "110"을 모두 앞에 추가
            while (count110--) result += "110";
            result += processedStr;
        } else {
            // '0'이 있는 경우, 마지막 '0' 뒤에 "110"을 모두 추가
            for (int j = 0; j < processedStr.length(); j++) {
                if (j == lastZeroIndex) {
                    result += processedStr[j];
                    while (count110--) result += "110";
                } else {
                    result += processedStr[j];
                }
            }
        }
        answer.push_back(result);
    }

    return answer;
}


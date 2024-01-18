#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <limits>

using namespace std;

int solution(vector<string> strs, string t) {
    int INF = numeric_limits<int>::max();
    int n = t.length();  //❶ 타겟 문자열 t의 길이
    vector<long long> dp(n + 1, INF);  //❷ 각 위치에서 필요한 최소 조각수를 저장할 벡터(초깃값은 INF)
    dp[0] = 0;  //❸ 빈 문자열을 얻기 위한 최소 조각수는 0
    
    unordered_set<int> sizes;  //❹ strs 조각들의 길이를 저장한 집합
    for (const auto& s : strs) {
        sizes.insert(s.length());
    }
    
    unordered_set<string> strsSet(strs.begin(), strs.end());  //❺ strs의 원소를 저장한 집합

    

    for (int i = 1; i <= n; ++i) {
        for (int size : sizes) {  //❻ 각 str 조각의 문자열 길이에 대하여
            //❼ 이미 구한 해와 str 조각을 추가해서 문자열을 만들 수 있다면
            if (i >= size && strsSet.count(t.substr(i - size, size))) {
                dp[i] = min(dp[i], dp[i - size] + 1);  //❽ 해당 위치의 최소 조각수를 갱신
            }
        }
    }
    return dp[n] != INF ? dp[n] : -1;  //➒ 최소 조각수를 반환(만들 수 없으면 -1)
}





//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution({"ba", "na", "n", "a"}, "banana") << endl; //출력값 : 3
  cout << solution({"app", "ap", "p", "l", "e", "ple", "pp"}, "apple") << endl; //출력값 : 2  
  cout << solution({"ba", "an", "nan", "ban", "n"}, "banana") << endl; //출력값 : -1 
  
  return 0;
}

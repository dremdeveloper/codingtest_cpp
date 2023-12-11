#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// ❶ 다항 해시 함수 구현
long long polynomial_hash(const string& str) {
    const int p = 31;  // 소수
    const long long m = 1000000007;  // 버킷 크기
    long long hash_value = 0;
    
    for (char c : str) {
        hash_value = (hash_value * p + c) % m;
    }
    
    return hash_value;
}

vector<bool> solution(vector<string> string_list, vector<string> query_list) {
    unordered_set<long long> hash_set;
    
    //❷ string_list의 각 문자열에 대해 다항 해시값을 계산하고 저장
    for (const string& str : string_list) {
        long long hash = polynomial_hash(str);
        hash_set.insert(hash);
    }
    
    vector<bool> result;
    
    //❸  query_list의 각 문자열이 string_list에 있는지 확인하고 result에 추가
    for (const string& query : query_list) {
        long long query_hash = polynomial_hash(query);
        bool found = (hash_set.find(query_hash) != hash_set.end());
        result.push_back(found);
    }
    //❹  quer_list들이 hash에 있는지에 대한 값이 있는지에 대한 결과가 저장된 result를 반환
    return result;
}


//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>
void print(vector<bool> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<bool>(cout, " "));
    cout << endl;
}

int main()
{
    //true를 출력하면 1이되고 false를 출력하면 0
    print(solution({"apple", "banana", "cherry"}, {"banana", "kiwi", "melon", "apple"})); // 1 0 0 1
    return 0;

}

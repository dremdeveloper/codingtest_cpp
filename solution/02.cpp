#include <vector>
#include <algorithm> // sort, unique를 위해 선언

using namespace std;

bool compare(int a, int b) { // ❶ 정렬 기준 정의
    return a > b; 
}

vector<int> solution(vector<int> lst) {
    sort(lst.begin(), lst.end(), compare); // ❷ 내림차순으로 정렬
    lst.erase(unique(lst.begin(), lst.end()), lst.end()); // ❸ 중복값 제거

    return lst;
}



//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>
void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({4, 2, 2, 1, 1, 3, 4})); // 4 3 2 1  
    print(solution({2, 1, 1, 3, 2, 5, 4})); // 5 4 3 2 1
    
    return 0;
}

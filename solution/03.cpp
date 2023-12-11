#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) { 
    set<int> sum; // ❶ 두 수의 합을 저장할 저장공간 선언

    for(int i = 0;i<numbers.size();++i)  // ❷ 반복문을 수행하면서 두 수의 합을 저장
        for(int j = i+1 ; j< numbers.size();++j)
           sum.insert(numbers[i] + numbers[j]); 

    vector<int> answer(sum.begin(), sum.end()); // ❸ 반환타입을 맞추기 위헤 벡터로 변환
    return answer; 
}



//아래 코드는 테스트 코드 입니다.

#include <iterator>
#include <iostream>
void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({2, 1, 3, 4, 1}));     // 2 3 4 5 6 7 
    print(solution({5, 0, 2, 7}));        // 2 5 7 9 12 
    
    return 0;
}

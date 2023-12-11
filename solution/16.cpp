#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    vector<int> days_left(n); 

    //❶ 각 작업에 대한 완료까지 남은 일수 계산
    for (int i = 0; i < n; ++i) {
        days_left[i] = ceil((100.0 - progresses[i]) / speeds[i]);
    }

   int count = 0; //❷ 배포 될 작업의 수
    int max_day = days_left[0]; // ❸ 현재 배포될 작업 중 가장 늦게 배포될 작업의 가능일
    

    for (int i = 0; i < n; ++i) {
        if (days_left[i] <= max_day) { //❹ 배포 가능일이 가장 늦은 배포일보다 빠르면
            count++;
        } else { //❺ 배포 예정일이 기준 배포일보다 느리면
            answer.push_back(count);
            count = 1;
            max_day = days_left[i];
        }
    }

    answer.push_back(count); //❻ 마지막으로 카운트된 작업들을 함께 배포
    return answer;
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
    
    print(solution({93, 30, 55}, {1, 30, 5})); // 2 1
    print(solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1})); // 1 3 2
    
    return 0;

}

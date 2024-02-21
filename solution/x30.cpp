int solution(int n, int a, int b)
{
    int answer = 0;

    do {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        ++answer;
    } while (a != b);

    return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
    cout << solution(8, 4, 7) << endl; //출력값 : 3
    return 0;
}

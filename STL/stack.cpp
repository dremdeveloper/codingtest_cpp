//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <stack>

using namespace std;

// std::stack은 C++ STL에 포함된 컨테이너 어댑터입니다.
// - LIFO(Last-In-First-Out) 원칙에 따라 동작하는 데이터 구조입니다.
// 좋은 사용 시기:
// - LIFO 원칙에 따라 데이터를 처리해야 할 때, 예를 들면, 재귀 알고리즘의 내부 스택, 실행 취소 기능 등.

int main() {

    stack<int> s;

    // push: 스택의 상단에 요소 추가, O(1)
    s.push(1);
    s.push(2);
    s.push(3);

    // top: 스택의 상단 요소에 접근, O(1)
    cout << "Top element: " << s.top() << endl;  // 출력: Top element: 3

    // pop: 스택의 상단 요소 제거, O(1)
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;  // 출력: Top element after pop: 2

    // empty: 스택이 비어 있는지 확인, O(1)
    if (!s.empty()) {
        cout << "Stack is not empty" << endl;  // 출력: Stack is not empty
    }

    // size: 스택의 크기 확인, O(1)
    cout << "Stack size: " << s.size() << endl;  // 출력: Stack size: 2

    // 성능 저하 예제:
    // stack은 중간 요소에 직접 접근할 수 없으므로, 중간 요소를 검색하거나 수정하는 연산이 필요한 경우 
    // stack보다는 다른 자료 구조를 사용하는 것이 좋습니다.

    return 0;
}


//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <deque>

using namespace std;

// 덱(deque)은 "double-ended queue"의 약자입니다.
// - 덱은 양쪽 끝에서 원소의 삽입과 삭제가 가능한 선형 컨테이너입니다.
// 좋은 사용 시기:
// - 양쪽 끝에서의 원소 접근, 삽입, 삭제가 빈번할 때 사용하면 좋습니다.
// 성능 이슈:
// - 덱의 중간에서의 원소 삽입 또는 삭제는 O(n)의 시간 복잡도를 가집니다. 중간 위치의 연산이 빈번하면 성능 저하가 발생할 수 있습니다.

int main() {
    deque<int> dq;

    // push_front: 덱의 앞쪽에 원소 추가, O(1)
    dq.push_front(1);
    dq.push_front(2);

    // push_back: 덱의 뒤쪽에 원소 추가, O(1)
    dq.push_back(3);
    dq.push_back(4);

    // front: 덱의 첫 번째 원소 접근, O(1)
    cout << "Front element: " << dq.front() << endl;  // 출력: Front element: 2

    // back: 덱의 마지막 원소 접근, O(1)
    cout << "Back element: " << dq.back() << endl;    // 출력: Back element: 4

    // pop_front: 덱의 앞쪽 원소 제거, O(1)
    dq.pop_front();

    // pop_back: 덱의 뒤쪽 원소 제거, O(1)
    dq.pop_back();

    // 순회 예제
    for (int num : dq) {
        cout << num << " ";  // 출력: 1 3 
    }
    cout << endl;
    
    // 성능 저하 예제:
    // 덱의 중간 위치에서 원소를 삽입하거나 삭제하는 연산은 O(n)의 시간 복잡도를 가집니다.
    // 예:
    // deque<int>::iterator it = dq.begin() + 1;
    // dq.insert(it, 5);  // 중간 위치에 5 삽입
   
    return 0;
}


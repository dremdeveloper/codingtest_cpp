//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 반복자 예시
// 반복자는 컨테이너(예: 벡터, 리스트 등)의 요소를 순회하는 데 사용됩니다.
// 반복자는 포인터와 비슷하게 동작하며, STL에서 중요한 역할을 합니다.
// 반복자를 사용하면 컨테이너의 내부 구현에 독립적으로 요소를 처리할 수 있습니다.

int main() {
    // 벡터 선언 및 초기화
    vector<int> vec = {1, 2, 3, 4, 5};
    
    // 리스트 선언 및 초기화
    list<int> lst = {10, 20, 30, 40, 50};
    
    // 순방향 반복자를 사용하여 벡터의 요소를 순회하고 출력
    cout << "Vector elements: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " "; // 반복자가 가리키는 요소를 출력
    }
    cout << endl; // 출력: Vector elements: 1 2 3 4 5

    // 순방향 반복자를 사용하여 리스트의 요소를 순회하고 출력
    cout << "List elements: ";
    for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " "; // 반복자가 가리키는 요소를 출력
    }
    cout << endl; // 출력: List elements: 10 20 30 40 50

    // 역방향 반복자를 사용하여 벡터의 요소를 순회하고 출력
    cout << "Vector elements in reverse: ";
    for (vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " "; // 역방향 반복자가 가리키는 요소를 출력
    }
    cout << endl; // 출력: Vector elements in reverse: 5 4 3 2 1

    // 역방향 반복자를 사용하여 리스트의 요소를 순회하고 출력
    cout << "List elements in reverse: ";
    for (list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit) {
        cout << *rit << " "; // 역방향 반복자가 가리키는 요소를 출력
    }
    cout << endl; // 출력: List elements in reverse: 50 40 30 20 10

    return 0;
}

/*
반복자의 목적:
- 반복자는 컨테이너의 요소를 순차적으로 접근하고 조작하는 데 사용됩니다.
- 반복자를 통해 컨테이너의 내부 구현에 독립적으로 요소를 처리할 수 있습니다.

반복자의 장점:
1. 유연성: 다양한 컨테이너에 대해 동일한 방식으로 요소를 순회할 수 있습니다.
2. 추상화: 컨테이너의 내부 구조를 몰라도 요소를 접근할 수 있습니다.
3. 범용성: 알고리즘 함수와 함께 사용하여 코드의 재사용성을 높입니다.

순방향 반복자와 역방향 반복자:
1. 순방향 반복자: 컨테이너의 처음(begin)부터 끝(end)까지 순차적으로 요소를 접근합니다.
    - 선언: vector<int>::iterator it;
    - 초기화: it = vec.begin();
    - 사용: *it를 통해 반복자가 가리키는 요소에 접근합니다.

2. 역방향 반복자: 컨테이너의 끝(rbegin)부터 처음(rend)까지 역순으로 요소를 접근합니다.
    - 선언: vector<int>::reverse_iterator rit;
    - 초기화: rit = vec.rbegin();
    - 사용: *rit를 통해 역방향 반복자가 가리키는 요소에 접근합니다.

반복자의 사용방법:
1. 반복자 선언: 컨테이너 타입에 따라 반복자를 선언합니다. 예: vector<int>::iterator.
2. 반복자 초기화: begin()과 end(), 또는 rbegin()과 rend() 함수를 사용하여 반복자를 초기화합니다.
3. 반복자 사용: 반복자를 사용하여 요소에 접근하고 조작합니다.

예시:
- 벡터 요소 순회: for (it = vec.begin(); it != vec.end(); ++it).
- 리스트 요소 순회: for (it = lst.begin(); it != lst.end(); ++it).
- 역방향 요소 순회: for (rit = vec.rbegin(); rit != vec.rend(); ++rit).
- 요소 접근: *it 또는 *rit를 사용하여 반복자가 가리키는 요소에 접근합니다.

코드 설명:
1. 벡터 선언 및 초기화: vector<int> vec = {1, 2, 3, 4, 5}; 벡터를 선언하고 초기화합니다.
2. 리스트 선언 및 초기화: list<int> lst = {10, 20, 30, 40, 50}; 리스트를 선언하고 초기화합니다.
3. 순방향 반복자 사용:
    - for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it): 순방향 반복자를 사용하여 벡터의 요소를 순회합니다.
    - for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it): 순방향 반복자를 사용하여 리스트의 요소를 순회합니다.
    - *it: 순방향 반복자가 가리키는 요소를 출력합니다.
4. 역방향 반복자 사용:
    - for (vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit): 역방향 반복자를 사용하여 벡터의 요소를 역순으로 순회합니다.
    - for (list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit): 역방향 반복자를 사용하여 리스트의 요소를 역순으로 순회합니다.
    - *rit: 역방향 반복자가 가리키는 요소를 출력합니다.
*/

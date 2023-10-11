//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 이터레이터(iterator)는 STL 컨테이너의 원소들을 순회하기 위한 포인터와 유사한 객체입니다.
// - 다양한 STL 컨테이너들은 자신만의 이터레이터 타입을 제공합니다.
// 좋은 사용 시기:
// - 컨테이너의 원소들을 순회하거나, 특정 위치의 원소에 접근하고 싶을 때.
// 성능 이슈:
// - 일반적으로 이터레이터의 연산들은 상수 시간 복잡도를 가집니다. 하지만 이터레이터의 종류(예: forward iterator, bidirectional iterator, random access iterator)에 따라 가능한 연산이 다를 수 있습니다.

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    // begin, end: 컨테이너의 시작과 끝을 가리키는 이터레이터 반환, O(1)
    vector<int>::iterator it = v.begin();
    
    // * 연산자: 이터레이터가 가리키는 원소에 접근, O(1)
    cout << "First element: " << *it << endl; // 출력: First element: 1

    // ++ 연산자: 이터레이터를 다음 원소로 이동, O(1)
    ++it;
    cout << "Second element: " << *it << endl; // 출력: Second element: 2
    
    // += 연산자: 이터레이터를 지정된 수만큼 이동 (Random Access Iterator에만 가능), O(1)
    it += 2;
    cout << "Fourth element: " << *it << endl; // 출력: Fourth element: 4

    // 이터레이터를 사용한 순회 예제
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) {
        cout << *iter << " "; // 출력: 1 2 3 4 5 
    }
    cout << endl;

    return 0;

}


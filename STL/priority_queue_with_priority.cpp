//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################

#include <iostream>
#include <queue>
#include <vector>

// 표준 라이브러리 사용을 위한 네임스페이스 선언
using namespace std;

// 좌표를 나타내는 구조체 정의
struct Point {
    int x, y;
    
    // 비교 연산자 정의 (내림차순)
    // 우선순위 큐에서 가장 큰 값을 우선 처리하기 위해 사용
    bool operator<(const Point& other) const {
        // 내림차순 정렬을 위해 x 좌표가 큰 순서대로, x 좌표가 같다면 y 좌표가 큰 순서대로 정렬
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

int main() {
    // 우선순위 큐 선언 (내림차순)
    // priority_queue<Point>:
    //   - Point: 큐에 저장될 요소의 타입 (좌표 구조체)
    // 기본적으로 가장 큰 값이 높은 우선순위를 가집니다.
    priority_queue<Point> pq;
    
    // 좌표 삽입
    // push() 함수는 우선순위 큐에 요소를 삽입합니다.
    pq.push({10, 20}); // (10, 20) 삽입
    pq.push({30, 40}); // (30, 40) 삽입
    pq.push({20, 30}); // (20, 30) 삽입
    pq.push({5, 10});  // (5, 10) 삽입
    
    // 좌표 출력 (우선순위 순)
    // while 루프는 큐가 비어있지 않을 때까지 반복됩니다.
    // top() 함수는 우선순위 큐의 가장 위에 있는 요소(우선순위가 가장 높은 요소)를 반환합니다.
    // pop() 함수는 우선순위 큐의 가장 위에 있는 요소를 제거합니다.
    while (!pq.empty()) {
        Point p = pq.top(); // 우선순위가 가장 높은 좌표를 반환
        cout << "(" << p.x << ", " << p.y << ") "; // 좌표를 출력
        pq.pop(); // 우선순위가 가장 높은 좌표를 큐에서 제거
    }
    return 0;
}

// 출력 설명:
// priority_queue는 기본적으로 최대 힙(Max-Heap) 구조로 동작하여 가장 큰 요소가 가장 높은 우선순위를 가집니다.
// 좌표 구조체(Point)의 비교 연산자(operator<)를 사용하여 x 좌표가 큰 순서대로, 
// x 좌표가 같다면 y 좌표가 큰 순서대로 정렬됩니다.
// 따라서, 위의 코드는 (30, 40), (20, 30), (10, 20), (5, 10) 순으로 좌표를 출력합니다.
// pq.push() 함수를 통해 좌표를 삽입할 때마다 내부적으로 정렬이 이루어지며,
// pq.top() 함수는 가장 큰 x 값을 가진 좌표를 반환하고, pq.pop() 함수는 반환된 좌표를 큐에서 제거합니다.
// 결과적으로, 우선순위 큐에 삽입된 좌표들은 내림차순으로 정렬되어 출력됩니다.

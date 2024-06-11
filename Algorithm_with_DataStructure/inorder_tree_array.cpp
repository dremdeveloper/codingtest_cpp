//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
using namespace std;

// 트리를 배열로 나타내기 위해서, 배열의 인덱스를 사용하는 중위 순회 함수 정의
void inorderTraversal(int tree[], int index, int size) {
    if (index >= size || tree[index] == -1) return; // 유효하지 않은 인덱스나 값이 -1이면 종료

    // Step 1: 왼쪽 자식 노드로 이동 (2*index)
    inorderTraversal(tree, 2 * index, size);

    // Step 2: 현재 노드 값 출력
    cout << tree[index] << " ";

    // Step 3: 오른쪽 자식 노드로 이동 (2*index + 1)
    inorderTraversal(tree, 2 * index + 1, size);
}

int main() {
    // 트리를 배열로 나타내기
    // -1은 해당 위치에 노드가 없음을 나타냅니다.
    int tree[] = {-1, 1, 4, 8, 3, 5, -1, 7, 2, -1, -1, -1, -1, -1, 6};
    int size = sizeof(tree) / sizeof(tree[0]);

    // 중위 순회 함수 호출
    inorderTraversal(tree, 1, size);

    return 0;
}

/*
트리 도식화 (배열 인덱스 기반):

            1 (1)
           / \
        4 (2) 8 (3)
       / \     \
    3 (4) 5 (5)  7 (7)
   /             /
 2 (8)         6 (14)

중위 순회 과정:
1. 왼쪽 자식: 4 (index 2)
   - 왼쪽 자식: 3 (index 4)
     - 왼쪽 자식: 2 (index 8)
       - 왼쪽 자식: 없음 (index 16, size 초과)
       - 현재 노드 값 출력: 2 (index 8)
       - 오른쪽 자식: 없음 (index 17, size 초과)
     - 현재 노드 값 출력: 3 (index 4)
     - 오른쪽 자식: 없음 (index 9, 값이 -1)
   - 현재 노드 값 출력: 4 (index 2)
   - 오른쪽 자식: 5 (index 5)
     - 왼쪽 자식: 없음 (index 10, 값이 -1)
     - 현재 노드 값 출력: 5 (index 5)
     - 오른쪽 자식: 없음 (index 11, 값이 -1)
2. 현재 노드 값 출력: 1 (index 1)
3. 오른쪽 자식: 8 (index 3)
   - 왼쪽 자식: 없음 (index 6, 값이 -1)
   - 현재 노드 값 출력: 8 (index 3)
   - 오른쪽 자식: 7 (index 7)
     - 왼쪽 자식: 6 (index 14)
       - 왼쪽 자식: 없음 (index 28, size 초과)
       - 현재 노드 값 출력: 6 (index 14)
       - 오른쪽 자식: 없음 (index 29, size 초과)
     - 현재 노드 값 출력: 7 (index 7)
     - 오른쪽 자식: 없음 (index 15, 값이 -1)

중위 순회 순서: 2 3 4 5 1 8 6 7
*/

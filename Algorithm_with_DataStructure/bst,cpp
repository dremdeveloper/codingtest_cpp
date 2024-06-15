//#############################################################
//# | cafe       | http://cafe.naver.com/dremdelover          |
//# | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
//# | business   | ultrasuperrok@gmail.com                    |
//#############################################################

#include <iostream>
using namespace std;

/*
이진 탐색 트리(Binary Search Tree, BST)의 개념:
이진 탐색 트리는 각 노드가 최대 두 개의 자식 노드를 가지는 이진 트리의 일종입니다.
각 노드의 왼쪽 자식은 그 노드보다 작은 값을 가지고, 오른쪽 자식은 그 노드보다 큰 값을 가집니다.
이러한 구조를 통해 효율적인 탐색, 삽입, 삭제 연산이 가능합니다.

시간 복잡도:
- 평균적으로, BST에서의 탐색, 삽입, 삭제 연산의 시간 복잡도는 O(log n)입니다.
  이는 트리가 균형잡혀 있을 때의 경우입니다.
- 최악의 경우, 즉 트리가 편향된 경우(한쪽으로 치우친 경우), 시간 복잡도는 O(n)입니다.
  이는 트리가 하나의 연속된 리스트와 같은 형태가 되었을 때입니다.

배열과의 성능 비교:
- 배열:
  - 탐색: O(n) (순차 탐색)
  - 삽입/삭제: O(n) (삽입/삭제 시 원소를 이동해야 함)
- 이진 탐색 트리:
  - 탐색: O(log n) (평균), O(n) (최악)
  - 삽입/삭제: O(log n) (평균), O(n) (최악)

BST는 정렬된 데이터를 빠르게 탐색할 수 있는 장점이 있습니다. 또한, 새로운 데이터를 삽입하거나 기존 데이터를 삭제하는 데에도 비교적 효율적입니다. 반면에, 배열은 특정 인덱스에 빠르게 접근할 수 있는 장점이 있지만, 삽입이나 삭제 시에는 많은 원소를 이동시켜야 하므로 비효율적일 수 있습니다.
*/

// 이진 트리 노드 정의
struct Node {
    int data; // 노드에 저장된 데이터
    Node* left; // 왼쪽 자식 노드
    Node* right; // 오른쪽 자식 노드

    Node(int value) : data(value), left(nullptr), right(nullptr) {} // 생성자
};

// 새로운 노드를 이진 탐색 트리에 삽입하는 함수
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data); // 루트가 없으면 새로운 노드를 반환
    }

    if (data < root->data) {
        root->left = insert(root->left, data); // 데이터가 작으면 왼쪽 서브트리에 삽입
    } else {
        root->right = insert(root->right, data); // 데이터가 크면 오른쪽 서브트리에 삽입
    }

    return root;
}

// 이진 탐색 트리에서 특정 값을 찾는 함수
Node* search(Node* root, int data) {
    if (root == nullptr || root->data == data) {
        return root; // 노드가 없거나 데이터를 찾은 경우 반환
    }

    if (data < root->data) {
        return search(root->left, data); // 데이터가 작으면 왼쪽 서브트리에서 검색
    } else {
        return search(root->right, data); // 데이터가 크면 오른쪽 서브트리에서 검색
    }
}

// 이진 탐색 트리를 중위 순회로 출력하는 함수
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr; // 초기 트리는 비어 있음

    // 노드 삽입
    root = insert(root, 3); 
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 9);

    cout << "이진 탐색 트리의 중위 순회 출력: ";
    inorder(root); // 중위 순회 호출
    cout << endl;
    // 출력: 2 3 4 8 9

    // 특정 값 검색
    int valueToSearch = 4;
    Node* result = search(root, valueToSearch);
    if (result != nullptr) {
        cout << valueToSearch << "를 찾았습니다: " << result->data << endl;
    } else {
        cout << valueToSearch << "를 찾을 수 없습니다." << endl;
    }

    valueToSearch = 5;
    result = search(root, valueToSearch);
    if (result != nullptr) {
        cout << valueToSearch << "를 찾았습니다: " << result->data << endl;
    } else {
        cout << valueToSearch << "를 찾을 수 없습니다." << endl;
    }

    return 0;
}



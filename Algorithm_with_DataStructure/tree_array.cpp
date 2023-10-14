/*
Tree 구현 알고리즘 (배열 사용):
- 시간 복잡도: O(1) (노드에 접근, 추가, 삭제 등의 기본 연산)
- 용도: 트리를 메모리에 효율적으로 저장하고 접근하는데 사용됩니다.
- 동작 과정:
  1. 부모 노드의 인덱스를 i라고 할 때, 왼쪽 자식은 2*i, 오른쪽 자식은 2*i + 1의 인덱스를 가집니다.
  2. 이를 기반으로 트리의 노드를 배열에 삽입하거나 접근합니다.

도식화 예:
            1
       /        \
      2          3
    /   \      /   \
   4     5    6     7 

위 트리는 [1, 2, 3, 4, 5, 6, 7]의 배열로 표현할 수 있습니다.
*/

#include<iostream>
using namespace std;

class Tree {
private:
    int treeArray[100]; // 크기가 100인 정적 배열을 통해 트리를 구현
    int size;           // 현재 트리의 크기

public:
    Tree() {
        size = 0;
        // 배열 초기화
        for(int i=0; i<100; i++)
            treeArray[i] = -1;
    }

    void insert(int data) {
        // 루트 노드가 비어있다면,
        if(size == 0) {
            treeArray[1] = data;
            size = 1;
        }
        // 루트 노드가 차있다면,
        else {
            treeArray[size+1] = data;
            size++;
        }
    }

    void printTree() {
        cout << "Tree: ";
        for(int i=1; i<=size; i++)
            cout << treeArray[i] << " ";
        cout << endl;
    }
};

int main() {
    Tree t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);

    t.printTree(); // 출력: Tree: 1 2 3 4 5 6 7

    return 0;
}

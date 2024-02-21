#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 전위순회
string preorder(const vector<int>& nodes, int idx) {
  if (idx < nodes.size()) {
    string ret = to_string(nodes[idx]) + " ";
    ret += preorder(nodes, idx * 2 + 1);
    ret += preorder(nodes, idx * 2 + 2);
    return ret;
  } 
  
  return "";
}

// 중위순회
string inorder(const vector<int>& nodes, int idx) {
  if (idx < nodes.size()) {
    string ret = inorder(nodes, idx * 2 + 1);
    ret += to_string(nodes[idx]) + " ";
    ret += inorder(nodes, idx * 2 + 2);
    return ret;
  } 
  
  return "";
}

// 후위순회
string postorder(const vector<int>& nodes, int idx) {
  if (idx < nodes.size()) {
    string ret = postorder(nodes, idx * 2 + 1);
    ret += postorder(nodes, idx * 2 + 2);
    ret += to_string(nodes[idx]) + " ";
    return ret;
  } 
  
  return "";
}

vector<string> solution(const vector<int>& nodes) {
  vector<string> result;
  string pre = preorder(nodes, 0);
  string in = inorder(nodes, 0);
  string post = postorder(nodes, 0);

  // 마지막 공백을 제거한 결과를 result에 추가
  pre.pop_back();
  in.pop_back();
  post.pop_back();

  result.push_back(pre);
  result.push_back(in);
  result.push_back(post);

  return result;
}

//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>
void print(vector<string> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, "\n"));
    cout << endl;
}

int main()
{
    print(solution({1, 2, 3, 4, 5, 6, 7})); 
    /** 
     출력값 
     1 2 4 5 3 6 7
     4 2 5 1 6 3 7
     4 5 2 6 7 3 1
    **/
    
    return 0;
}

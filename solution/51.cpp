#include <vector>

using namespace std;

vector<int> answer;
vector<int> ryan(11, 0);
int maxScore = -1;

//❶ 어피치와 라이언의 점수차이를 계산
int calcScoreDiff(const vector<int> &apeach) {
  int scoreApeach = 0;
  int scoreLion = 0;

  for(int i = 0; i < 11; ++i) {
    if(apeach[i] == 0 && ryan[i] == 0) continue;
    if(apeach[i] >= ryan[i]) scoreApeach += 10 - i;
    else scoreLion += 10 - i;
  }

  return scoreLion - scoreApeach;
}

void dfs(const vector<int> &apeach, int score, int arrow) {
  if(score == -1 || arrow == 0) {
    ryan[10] = arrow;
    int scoreDiff = calcScoreDiff(apeach);
    //❷ 현재 구한 점수차가 기존 최대 점수차보다 더 크고, 라이언의 점수가 더 높은 경우 갱신
    if(scoreDiff > 0 && maxScore < scoreDiff) {
      maxScore = scoreDiff;
      answer = ryan;
    }
    ryan[10] = 0;
    return;
  }

   //❸ 아직 어피치가 쏠 화살이 남은 경우
  if(arrow > apeach[score]) {
    ryan[score] = apeach[score] + 1;
    dfs(apeach, score - 1, arrow - apeach[score] - 1);
    ryan[score] = 0;
  }

  //❹ 어피치가 화살을 사용하지 않는 경우
  dfs(apeach, score - 1, arrow);
}

vector<int> solution(int n, vector<int> info) {
  //❺ 10점 과녁부터 모든 조합을 확인
  dfs(info, 10, n);

  //❻ 라이언이 이길 수 있는 경우가 없는 경우
  if(maxScore == -1) answer.push_back(-1);

  return answer;
}





//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>
using namespace std;

void init(){
  answer.clear();
  maxScore = -1;
  
  for(int i = 0 ; i < ryan.size(); i++)
    ryan[i] = 0;
}

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution(5, {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0})); //출력값 : 0 2 2 0 1 0 0 0 0 0 0 
  init();
  print(solution(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})); //출력값 : -1
  init();
  print(solution(9, {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1})); //출력값 : 1 1 2 0 1 2 2 0 0 0 0 
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxScore(vector<int> &tokens, int power){
  sort(tokens.begin(), tokens.end());
  int score = 0, maxScore = 0;
  int currP = power;
  int left = 0, right = tokens.size() -1;
  while(left <= right){
    if(currP >= tokens[left]){
      currP -= tokens[left];
      score++;
      maxScore = max(maxScore, score);
      left++;
    }
    else if(score >=1 && left < right){
      currP += tokens[right];
      score--;
      right--;
    }
    else break;
  }
  return maxScore;
}
int main(){
  int n;
  cin >> n;
  vector<int> tokens(n);
  for(int i = 0; i<n; i++) cin >> tokens[i];
  int power;
  cin >> power;
  int result = maxScore(tokens, power);
  cout << result << endl;
}
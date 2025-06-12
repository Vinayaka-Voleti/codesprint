#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> ranks(vector<int> &score){
  int n = score.size();
  vector<string> result(n);
  vector<int> indices(n);
  for(int i = 0; i<n; i++) indices[i] = i;
  sort(indices.begin(), indices.end(), [&](int x, int y){
    return score[x] > score[y];
  });
  for(int i = 0; i<n; i++){
    int idx = indices[i];
    if(i == 0) result[idx] = "Gold Medal";
    else if(i == 1) result[idx] = "Silver Medal";
    else if(i == 2) result[idx] = "Bronze Medal";
    else result[idx] = to_string(i+1);
  }
  return result;
}
int main(){
  int n;
  cin >> n;
  vector<int> score(n);
  for(int i=0; i<n; i++) cin >> score[i];
  vector<string> result = ranks(score);
  cout << "Relative Ranks: " << endl;
  for(const auto&rank : result) cout << rank << " ";
  cout << endl;
}
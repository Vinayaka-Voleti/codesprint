#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string a, string b){
  return (b+a) < (a+b);
}
int main(){
  int n;
  cin >> n;
  vector<string> nums(n);
  for(int i=0; i<n; i++) cin >> nums[i];
  sort(nums.begin(), nums.end(), compare);
  if(nums[0] == "0"){
    cout << "0" << endl;
    return 0;
  }
  string res;
  for(const string &num : nums) res +=num;
  cout << res << endl;
}






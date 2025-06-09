#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool hasThreesum(vector<int> &nums, int target){
  int n = nums.size();
  sort(nums.begin(), nums.end());
  for(int i = 0; i<n-2; i++){
    int left = 1+1, right = n-1;
    while(left<right){
      int current = nums[i] + nums[left]+nums[right];
      if(current == target) return true;
      else if (current < target) left++;
      else right--;
    }
  }
  return false;
}
int main(){
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int i=0; i<n; i++) cin >> nums[i];
  int target;
  cout << "target: ";
  cin >> target;
  hasThreesum(nums, target) ? cout << "true" << endl : cout << "false" << endl;
}










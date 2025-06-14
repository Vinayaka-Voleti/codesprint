#include <iostream>
#include <vector>
using namespace std;
vector<int> sorted(vector<int> &nums){
  int n = nums.size();
  vector<int> result(n);
  int left = 0, right = n-1, index = n-1;
  while(left <=right){
    int leftsquare = nums[left] * nums[left];
    int rightsquare = nums[right] * nums[right];
    if(leftsquare>rightsquare){
      result[index] = leftsquare;
      left++;
    }
    else{
      result[index] = rightsquare;
      right--;
    }
    index--;
  }
  return result;
}
int main(){
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int i=0; i<n; i++) cin >> nums[i];
  vector<int> result = sorted(nums);
  for(int num: result) cout << num << " ";
  cout << endl;
}
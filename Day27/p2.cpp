#include <iostream>
#include <vector>
using namespace std;
vector<int> findErrorNums(vector<int> &nums){
  int n=nums.size();
  long long sum = n*(n +1LL)/2;
  long long squaresum = n*(n+ 1LL) * (2*n+1LL)/6;
  long long actualSum = 0, actualSquaresum = 0;
  for(int num: nums){
    actualSum += num;
    actualSquaresum +=(long long) num*num;
  }
  long long diffSum = sum - actualSum;
  long long squarediff = squaresum - actualSquaresum;
  long long miss_dup_sum = squarediff/diffSum;
  int missing = (diffSum+miss_dup_sum)/2;
  int duplicate = missing - diffSum;
  return {duplicate, missing};
}
int main(){
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int i = 0; i<n; i++) cin >> nums[i];
  vector<int> result = findErrorNums(nums);
  cout << '[' << result[0] << ", " << result[1] << ']' << endl;
}
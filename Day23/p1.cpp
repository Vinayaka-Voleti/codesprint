#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int maxScore(vector<int> &nums, int target){
  int n = nums.size();
  vector<long> deque1(n);
  deque1[0] = nums[0];
  deque<int> deque2;
  deque2.push_back(0);
  for(int i = 1; i<n; i++){
    while(!deque2.empty() && deque2.front() < i-target) deque2.pop_front();
    deque1[i] = nums[i] + deque1[deque2.front()];
    while(!deque2.empty() && deque1[deque2.back()] <= deque1[i]) deque2.pop_back();
    deque2.push_back(i);
  }
  return deque1[n-1];
}
int main(){
  int n, target;
  cin >> n;
  vector<int> nums(n);
  for(int i=0; i<n; i++) cin >> nums[i];
  cout << "target: ";
  cin >> target;
  cout << maxScore(nums, target) << endl;
}
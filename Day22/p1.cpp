#include <iostream>
#include <vector>
using namespace std;
int trapRainWater(vector<int> &height){
  int n = height.size();
  int left = 0, right = n-1;
  int leftMax = 0, rightMax = 0;
  int water = 0, result = 0;
  while(left <= right){
    if(height[left] <= height[right]){
      if(height[left] >= leftMax) leftMax = height[left];
      else result += leftMax-height[left];
      left++;
    }
    else{
      if(height[right] >= rightMax) rightMax = height[right];
      else result += rightMax - height[right];
      right--;
    }
  }
  return result;
}
int main(){
  int n;
  cin >> n;
  vector<int> height(n);
  for(int i = 0; i < n; i++) cin >> height[i];
  cout << trapRainWater(height) << endl;
}
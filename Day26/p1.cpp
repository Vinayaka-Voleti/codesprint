#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
int fct(vector<int> &arr, int target){
  int n = arr.size();
  int sum = 0;
  int min = INT_MAX;
  sort(arr.begin(), arr.end());
  for(int i = 0; i<n-2; i++){
    int left = i+1, right = n-1;
    while(left<right){
      int current = arr[i]+arr[left]+arr[right];
      int diff = abs(current-target);
      if(diff<min ||(diff == min && current>sum)){
        min = diff;
        sum = current;
      }
      if(current<target) left++;
      else if(current>target) right--;
      else return current;
    }
  }
  return sum;
}
int main(){
  int n, target, result;
  cin >> n;
  vector<int> arr(n);
  for(int i=0; i<n; i++) cin >> arr[i];
  cin >> target;
  result = fct(arr, target);
  cout << result << endl;
}
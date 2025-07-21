#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isValidPartition(const vector<int> &weights, int k, int mid){
  int currWeight = 0, count = 1;
  for(int weight: weights){
    if(weight > mid) return false;
    if(currWeight + weight <= mid) currWeight += weight;
    else{
      count ++;
      currWeight = weight;
      if(count > k) return false;
    }
  }
  return true;
}
int box(const vector<int> &weights, int k){
  int high = 0, low = *max_element(weights.begin(), weights.end());
  for(int weight : weights){
    high += weight;
  }
  while(high > low){
    int mid = low + (high-low)/2;
    if(isValidPartition(weights, k, mid)) high = mid ;
    else low = mid + 1;
  }
  return low;
}
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> weights(n);
  for(int i = 0; i<n; i++) cin >> weights[i];
  cout << box(weights, k) << endl;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
long long Pairs(unordered_map<long long, long long> &freq){
  vector<long long> uni;
  for(auto &pair: freq) uni.push_back(pair.first);
  sort(uni.begin(), uni.end());
  long long result = 0, sum = 0;
  for(auto nums : uni){
    result += freq.at(nums) * sum;
    sum += freq.at(nums);
  }
  return result;
}
int main(){
  int n;
  long long result;
  cin >> n;
  unordered_map<long long, long long> freq;
  for(int i = 0; i<n; i++){
    long long nums;
    cin >> nums;
    freq[nums]++;
  }
  result = Pairs(freq);
  cout << result << endl;
}
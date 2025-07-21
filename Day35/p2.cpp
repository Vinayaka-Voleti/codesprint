#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int minPacketToSmuggle(const vector<int> &highness){
  unordered_map<int, int> freq;
  int maxFreq =0;
  for(int h: highness){
    freq[h]++;
    maxFreq = max(maxFreq, freq[h]);
  }
  return maxFreq;
}
int main(){
  int n;
  cin >> n;
  vector<int> highness(n);
  for(int i=0; i<n; i++) cin >> highness[i];
  cout << minPacketToSmuggle(highness) << endl;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
void sortedfreq(vector<int> &arr){
  unordered_map<int, int> freq;
  for(int nums: arr) freq[nums]++;
  sort(arr.begin(),arr.end(), [&](int x, int y){
    if(freq[x] == freq[y])return x<y;
    return freq[x] > freq[y];
  });
    for(int nums: arr) cout << nums << " ";
}
int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i<n; i++) cin >> arr[i];
  cout << "sorted freq: ";
  sortedfreq(arr);
}
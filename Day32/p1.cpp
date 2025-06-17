#include <iostream>
#include <vector>
using namespace std;
int missing(vector<int> &arr){
  int xor1 = 0, xor2 = 0;
  int n = arr.size();
  for(int i =0; i<n; i++){
    xor2 = xor2 ^ arr[i];
    xor1 = xor1 ^ i;
  }
  xor1 = xor1 ^ n;
  return xor1 ^ xor2;
}
int main(){
  int n;
  cin >>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++) cin >> arr[i];
  int result = missing(arr);
  cout << "Missing Number: " << result << endl;
}
#include <iostream>
#include <vector>
using namespace std;
vector<long long> compute(vector<long long> &ele){
  int n = ele.size();
  vector<long long> prefix(n, 1), suffix(n, 1), result(n);
  for(int i = 1; i<n; i++) prefix[i] = prefix[i-1] * ele[i-1];
  for(int i = n-2; i>= 0; i--) suffix[i] = suffix[i+1] * ele[i+1];
  for(int i = 0; i<n; i++) result[i]= prefix[i] * suffix[i];
  return result;
}
int main(){
  int n;
  cin >> n;
  vector<long long> ele(n);
  for(int i = 0; i<n; i++) cin >> ele[i];
  vector<long long> result = compute(ele);
  for(int i = 0; i<result.size(); i++){
    cout << result[i];
    if(i != result.size() - 1) cout << " ";
  }
  cout << endl;
}
#include <iostream>
using namespace std;
int find(int n, int k){
  int result = 0;
  while(k > 1){
    if(k % 2 == 0) result = 1 - result;
    k = (k + 1)/2;
  }
  return result;
}
int main(){
  int k, n;
  cin >> n >> k;
  cout << find(n, k) << endl;
}
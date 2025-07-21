#include <iostream>
#include <vector>
using namespace std;
unsigned long long binomial(int n, int r){
  unsigned long long result = 1;
  if(r>n-r)
    r = n-r;
  for(int i = 0; i<r; i++){
    result *= (n-i);
    result /= (i+1);
  }
  return result;
}
unsigned long long Trees(int n){
  unsigned long long c = binomial(2 *n, n);
  return c/(n+1);
}
int main(){
  int n;
  cin >> n;
  cout << Trees(n) << endl;
}
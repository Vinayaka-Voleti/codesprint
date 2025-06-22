#include <iostream>
using namespace std;
bool PowerOfTwo(int n){
  if(n == 1)
    return true;
  if(n<1 || n%2 != 0)
    return false;
  return PowerOfTwo(n/2);
}
int main(){
  int n;
  cin >> n;
  bool result = PowerOfTwo(n);
  cout << (result? "true" : "false");
}
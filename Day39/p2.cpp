#include <iostream>
using namespace std;
int count(int n, int index){
  if(index == n)
    return 1;
  if(index % 2 == 0)
    return 5* count(n, index+1);
  else
  return 4 * count(n, index+1);
}
int main(){
  int n;
  cin >> n;
  cout << count(n, 0) << endl;
}
#include <iostream>
using namespace std;
int main(){
  int target, n;
  cin >> target >> n;

  if(target<1 || target > 1e9) return 0;
  if(n<1 || n> 1e5) return 0;
  
  int sessions[100001];
  for(int i=0; i<n; i++){
    cin >> sessions[i];
    if(sessions[i]< 1 || sessions[i] > 1e4) return 0;
  }
  int minl = 1000001;
  int left = 0; int sum = 0;

  for(int ryt =0; ryt<n; ryt++){
    sum += sessions[ryt];
    while(sum >= target){
      if(ryt -left +1 < minl){
        minl = ryt- left + 1;
      }
      sum -= sessions[left];
      left++;
    }
  }
  cout << (minl == 1000001 ? 0: minl) << endl;
}
#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> appointments(n), result;
  for(int i = 0; i<n; ++i){
    cin >> appointments[i];
  }
  int start = 0; int end = n - 1;
  while ( start <=end){
    result.push_back(appointments[start++]);
    if(start <= end){
      result.push_back(appointments[end--]);
      
    }
  }
    for(int j : result) cout << j << " ";
}
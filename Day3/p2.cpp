#include <iostream>
using namespace std;
int main(){
  int n, temp;
  cin >> n;
  if(n<1 || n> 100000) return 0;
  
  int temps[n];
  int count = 1, subarray_length = 1;
  for(int i = 0; i<n ; i++){
    cin >> temps[i];
    if(temps[i]<-1000 || temps[i]>1000) return 0;
    
  }
  for(int i = 1; i < n; i++){
    if(temps[i]>temps[i-1]){
      count ++;
    }
    else{
      subarray_length = max(subarray_length, count);
      count = 1;
    }
  }
  subarray_length = max(subarray_length, count);

  cout << subarray_length;
  
}
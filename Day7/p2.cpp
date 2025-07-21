#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  int price[n];
  if(n<2 || n>100) return 0;
  for(int i=0; i<n; i++){
    cin >> price[i];
  }
  int min = price[0];
  int max = 0;
  for(int i=1; i<n; i++){
    if(price[i] < min){
      min = price[i];
    }
    else{
      int profit = price[i] - min;
      if(profit > max){
        max = profit;
      }
    }
  }
  if(max >= 2){
    cout << max << endl;
    
  } else{
    cout << 0 << endl;
  }
}
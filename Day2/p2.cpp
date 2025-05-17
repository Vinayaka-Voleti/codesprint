#include <iostream>
using namespace std;
int main(){
  int n, jam_hours = 0 ;
  cin >> n;
  
  if(n<1) return 0;
  int hours[n];
  for(int i = 0 ; i< n ; i++){
    cin >> hours[i];
    
  }

  for(int i = 1; i< n ; i++){
    if(hours[i]>=50 && hours[i]>hours[i-1]){
      jam_hours++;
    }
  }
  cout << jam_hours;
}
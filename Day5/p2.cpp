#include <iostream>
using namespace std;
int main(){
  int n, total = 0;
  cin >> n;
  if(n<1 || n>50) return 0;
  for(int i=0; i<n;i++){
    for(int j = 0; j<n;j++){
      if((i+j)%2 == 0){
        cout << 1;
        total++;
      }
      else {
        cout << 0;
      }
      if(j < n-1){
        cout << ' ';
      } 
    }
    cout << endl;
  }
  cout << "Total students seated: " << total <<endl;
}
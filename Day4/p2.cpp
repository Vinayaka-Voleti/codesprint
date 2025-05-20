#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  if(n<1 || n>20 ) return 0;
  if(n>10){
    cout << "Abhik's marathon journey intensifies! Let's see his detailed zig-zag pattern:" << endl;
  }
  int total = 0;
  int width = 4*n - 3; 
  for(int i=1; i<=n; i++) {
    int space = (width -(4*i - 3))/2;
    for(int j = 0; j < space ; j++){
      cout << ' ';
    }
    if(i%2 ==1){
      for(int j = 1; j <= i; j++){
        cout << j;
        if(j != i) cout << "   ";
        total++;
      }
    }
      else{
        for(int j = i; j >=1; j--){
          cout << j;
          if(j!=1) cout << "   ";
          total++;
        }
      }
      cout << endl;
      
    }

  cout << "Total numbers printed: " << total << endl;
}
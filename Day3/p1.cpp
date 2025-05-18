#include <iostream>
using namespace std;
int main(){
  int r, c, overstocked_warehouse = 0;
  cin >> r >> c;
  if(r<1 || r>100 ||c<1|| c>100) return 0;
  
  int stock[r][c];
  for(int i = 0; i<r; i++ ){
    for (int j = 0; j<c; j++ ){
      cin >> stock[i][j];
      if(stock[i][j]<0 || stock[i][j]>1000) return 0;
    }
  }
  for(int i = 0; i<r; i++){
    int count = 0;
    for(int j = 0; j<c; j++){
      if(stock[i][j] >= 100){
        count++;
      }
    }
    if(count >= 3){
      overstocked_warehouse++;
    }
  }
  cout << overstocked_warehouse;
  
}
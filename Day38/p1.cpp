#include <iostream>
using namespace std;
char getChar(int k){
  char result = 'a';
  while( k > 1 ){
    int length = 1;
    while( 2 * length < k ) length *= 2;
    if( k > length ) {
      k -= length;
      result = ( result == 'z' ) ? 'a' : result + 1;
     }
  }
  return result;
}
int main(){
  int k;
  cin >> k;
  cout << getChar(k) << endl;
  return 0;
}
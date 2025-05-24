#include <iostream>
#include <string>
using namespace std;
int main(){
  string n;
  cin >> n;
  if(n.length()<1 || n.length()>100 ) return 0;
  int count = 0;
  bool seg = false;
  for(int i = 0; i<n.length(); i++){
    if(n[i] == '1'){
      if(!seg){
        count++;
        seg = true;
      }
    }
    else if(n[i] == '0'){
      seg = false;
    }
    else{
      return 0;
    }
  }
  cout << count << endl;
}
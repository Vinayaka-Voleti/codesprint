#include <iostream>
#include <string>
using namespace std;

int binaryStringSort(const string &str){
  int ones = 0;
  int operations = 0;

  for(char ch: str){
    if(ch == '1' ) ones ++;
    else{
      if(ones > 0){
       operations ++;
        ones --;
      }
    }
  }
  return operations;
}
int main(){
  int n; string str;
  cin >> n >> str;
  cout << binaryStringSort(str) << endl;
}
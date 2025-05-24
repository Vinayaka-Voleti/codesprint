#include <iostream>
using namespace std;
int main(){
  string jew, stone;
  cin >> jew >> stone;
  if(jew.length()<1 || jew.length()>50) return 0;
  if(stone.length()<1 || stone.length()>50) return 0;
  int count = 0;
  for(size_t i =0; i<stone.length(); i++){
    for(size_t j =0; j<jew.length(); j++){
      if(stone[i] == jew[j]){
        count++;
        break;
      }
    }
  }
  cout << count << endl;
}
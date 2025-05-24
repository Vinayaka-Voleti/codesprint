#include <iostream>
using namespace std;
int main(){
  string speech;
  getline(cin, speech);
  string words[1000]; int count = 0;
  string currWord = "";

  for (int i = 0; i < speech.length(); i++){
    if(speech[i] == ' '){
      if(currWord != ""){
        words[count] = currWord;
        count++;
        currWord = "";
      }
    } 
    else {
      currWord += speech[i];
      
    }
  }
    if(currWord != ""){
      words[count ] = currWord;
      count++;
    }
    for(int i = count -1; i>=0; i--){
      cout << words[i];
      if(i != 0) {
        cout << " ";
      }
    }
    cout << endl;
}
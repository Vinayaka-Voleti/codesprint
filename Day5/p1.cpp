#include <iostream>
#include <string>
using namespace std;
bool isBalanced(string& s){
  int freq[26] = {0};
  for(int i =0; i<s.length(); i++){
    freq[s[i]- 'a']++;
    
  }
  int ref =0;
  for(int i =0; i< 26 ; i++){
    if(freq[i]>0){
      ref = freq[i];
      break;
    }
  }
  for(int i =0; i<26; i++){
    if (freq[i]> 0 && freq[i] != ref) return false;
  }
  return true;
  
}
int main(){
  string s;
  cin >> s;
  if(s.length() < 1 || s.length() >1000) return false;
  if(isBalanced(s)){
    cout << "Ashriya smiles: Emotionl balance found." << endl;
  }
  else{
    cout << "Ashriya wonders: These thoughts were scattered." << endl;
  }
}
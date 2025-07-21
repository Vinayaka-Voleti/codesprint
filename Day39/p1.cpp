#include <iostream>
#include <string>
using namespace std;
string helper(string &s, int &i){
  string result = "";
  int n = s.size();
  while(i < n && s[i] != ']'){
    if(isdigit(s[i])){
      int num = 0;
      while(i<n && isdigit(s[i])){
        num = num * 10 + (s[i] - '0');
        i++;
      }
      i++;
      string decode = helper(s, i);
      for(int j = 0; j< num ; j++) result += decode;
      i++;
    }
    else {
      result += s[i];
      i++;
    }
  }
  return result;
}
string decode(string &s){
  int i = 0;
  return helper(s, i);
}
int main(){
  string s;
  getline(cin, s);
  string result = decode(s);
  cout << result << endl;
}
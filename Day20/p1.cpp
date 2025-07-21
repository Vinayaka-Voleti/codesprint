#include <iostream>
#include <string>
using namespace std;
string removeOuterParentheses(string str){
  string result;
  int count = 0;
  for(int i = 0; i<str.length(); i++){
    char ch = str[i];
    if(ch=='('){
      if(count > 0) result +=ch;
      count++;
    }
    else{
      count --;
      if(count > 0) result += ch;
    }
  }
  return result;
}
int main(){
  string str, remove_parentheses;
  cin >> str;
  remove_parentheses = removeOuterParentheses(str);
  cout << remove_parentheses << endl;
}
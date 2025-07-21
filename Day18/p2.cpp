#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool operands(string &s){
  return s == "+" || s == "-" || s == "*"|| s == "/";
}
int post(string str){
  string x = "";
  stack<long> stack1;
  for(int i = 0; i<= str.length(); i++){
    if(i == str.length() || str[i] == ' '){
      if(x.empty()) continue;
      if(operands(x)){
        long y = stack1.top();
        stack1.pop();
        long z = stack1.top();
        stack1.pop();
        if(x == "+") stack1.push(z+y);
        else if(x == "-") stack1.push(z-y);
        else if(x == "*") stack1.push(z*y);
        else if(x == "/") stack1.push(z/y);
      }
      else stack1.push(stoll(x));
      x = "";
    }
    else x += str[i];
  }
  return stack1.top();
}
int main(){
  string str;
  getline(cin, str);
  int result = post(str);
  cout << result << endl;
}
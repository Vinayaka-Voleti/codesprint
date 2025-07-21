#include <iostream>
#include <stack>
using namespace std;

bool isValid(string &str){
  stack<char> stack1;
  for(int i = 0; i< str.length(); i++){
    char ch = str[i];
    if(ch == '(' || ch == '[' || ch == '{') stack1.push(ch);
    else if(ch == ')' || ch == ']'|| ch == '}'){
      if(stack1.empty()) return false;
      char top = stack1.top();
      stack1.pop();
      if(ch == ')' && top != '(') return false;
      if(ch == ']' && top != '[') return false;
      if(ch== '}' && top != '{') return false;
      
    }
  }
  return stack1.empty();
}
int main(){
  string str;
  cin >> str;
  if(isValid(str)) cout << "true" << endl;
  else cout << "false" << endl;
}
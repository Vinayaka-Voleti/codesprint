#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
  string str;
  stack<char> stack;
  cout << "Enter string: " << endl;
  getline(cin, str);
  for(int i = 0; i<str.length(); i++){
    char ch = str[i];
    stack.push(ch);
  }
  string rev;
  int pos = 0;
  while(!stack.empty()){
    char topChar = stack.top();
    rev += topChar;
    stack.pop();
    pos++;
  }
  cout << rev << endl;
}


#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool operands(char ch){
  return ch == '+' || ch == '-' || ch == '*' || ch == '/';
} 
string postfix_to_prefix(string &post){
  stack<string> str;
  for(int i = 0; i<post.length(); i++){
    char ch = post[i];
    if(operands(ch)){
      string str1, str2, str3;
      str1 = str.top();
      str.pop();
      str2 = str.top();
      str.pop();
      str3 = ch + str2 + str1 ;
      str.push(str3);
    } 
    else str.push(string(1, ch));
  }
  return str.top();
}
int main(){
  string post;
  cin >> post;
  string pre = postfix_to_prefix(post);
  cout << pre << endl;
}
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
void push(stack<string> &stack1, unordered_map<string, int> &map, unordered_map<string, int> &topmap, string &gift ){
  stack1.push(gift);
  map[gift]++;
  topmap[gift]++;
}
void pop(stack<string> &stack1, unordered_map<string, int> &topmap){
  if(!stack1.empty()){
    string topG = stack1.top();
    stack1.pop();
    topmap[topG]--;
    if(topmap[topG] == 0) topmap.erase(topG);
  }
}
void count(stack<string> &stack1, unordered_map<string, int> &topmap){
  if(stack1.empty()) cout << "Empty" << endl;
  else{
    string topG = stack1.top();
    cout << topmap[topG] << endl;
  }
}
void operations(int n){
  stack<string> stack1;
  unordered_map<string, int> freq_map;
  unordered_map<string, int> topmap;
  cout << "Enter operations: " << endl;
  for(int i = 0; i<n; i++){
    string x;
    cin >> x;
    if(x == "PUSH"){
      string value;
      cin >> value;
      push(stack1, freq_map, topmap, value);
    }
    else if(x == "POP") pop(stack1, topmap);
    else if(x == "COUNT") count(stack1, topmap);
    else cout << "Invalid!" << endl;
  }
}
int main(){
  int n;
  cout << "Enter number of operations: " << endl;
  cin >> n;
  operations(n);
}
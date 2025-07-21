#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
void PUSH(stack<long> &stack1, stack<long> &minStack, long value1){
  stack1.push(value1);
  if(minStack.empty() || value1 <= minStack.top()) minStack.push(value1);
  else minStack.push(minStack.top());
}
void POP(stack<long> &stack1, stack<long> &minStack){
  if(!stack1.empty()){
    stack1.pop();
    minStack.pop();
  }
}
string getMin(stack<long> &minStack){
  if(minStack.empty()) return "Empty";
  else return to_string(minStack.top());
}
void operations(int n){
  stack<long> stack1;
  stack<long> minStack;
  vector<string> res;
  cout << "Enter operations: " << endl;
  for(int i = 0; i<n; i++){
    string operation;
    cin >> operation;
    if(operation == "PUSH"){
      long x;
      cin >> x;
      PUSH(stack1, minStack, x);
    }
    else if(operation == "POP") POP(stack1, minStack);
    else if(operation == "MIN") res.push_back(getMin(minStack));
  }
  for(string &result : res) cout << result << endl;
}
int main(){
  int n;
  cout << "Enter number of Operations: " << endl;
  cin >> n;
  operations(n);
}

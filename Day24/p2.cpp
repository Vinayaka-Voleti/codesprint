#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void revQueue(queue<int> &queue1){
  stack<int> stack1;
  while(!queue1.empty()){
    stack1.push(queue1.front());
    queue1.pop();
  }
  while(!stack1.empty()){
    queue1.push(stack1.top());
    stack1.pop();
  }
}
int main(){
  int n;
  cin >> n;
  queue<int> queue1;
  for(int i = 0; i<n; i++){
    int val;
    cin >> val;
    queue1.push(val);
  }
  revQueue(queue1);
  cout << "Reversed Queue: ";
  while(!queue1.empty()){
    cout << queue1.front() << " ";
    queue1.pop();
  }
  cout << endl;
}
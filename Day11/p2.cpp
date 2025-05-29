#include <iostream>
using namespace std;
struct Node{
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
  
};
int main(){
  int n, pos;
  cin >> n;
  Node* head = nullptr, *tail = nullptr;
  for(int i = 0; i <n; i++){
    int val;
    cin >> val;
    Node* temp = new Node(val);
    if(!head) head = temp;
    else tail-> next = temp;
    tail = temp;
    
  }
  cin >> pos;
  if(pos > 0){
    Node* loopNode = head;
    for(int i = 1; i<pos; i++){
      loopNode = loopNode-> next;
    }
    tail->next = loopNode;
  }
  Node* slow = head, *fast = head;
  bool Cycle = false;
  while (fast && fast-> next){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
      Cycle = true;
      break;
    }
    
  }
  if(!Cycle){
    cout << "false";
    return 0;
  }
  slow = head;
  if(slow != fast){
    while(slow -> next != fast->next){
      slow = slow->next;
      fast = fast->next;
    }
    fast->next = nullptr;
    
  }
  else{
    while(fast->next != slow) fast = fast -> next;
    fast-> next = nullptr;
  }
  cout << "true";
}
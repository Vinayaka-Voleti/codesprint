#include <iostream>
using namespace std;
struct Node{
  int val;
  Node *next;
  Node(int x): val(x), next(NULL) {}
  
};
Node *insert(Node* head, int val){
  Node *newnode = new Node(val);
  if(!head) return newnode;
  Node *temp = head;
  while(temp->next) temp = temp->next;
  temp->next = newnode;
  return head;
}
void print(Node *head){
  cout << '[';
  while(head){
    cout << head->val;
    if(head->next) cout << ", ";
    head = head->next;
  }
  cout << ']';
  cout << endl;
}
Node *add(Node* x , Node *y){
  Node *dummy = new Node(0);
  Node *curr = dummy;
  int carry = 0;

  while(x || y || carry){
    int sum = carry;
    if(x){
      sum += x->val;
      x = x->next;
    }
    if(y){
      sum += y->val;
      y=y->next;
    }
    carry = sum/10;
    curr->next = new Node(sum %10);
    curr=curr->next;
    
  }
  return dummy->next;
}
int main(){
  int val, n1, n2;
  Node *x = NULL, *y = NULL;
  cin >> n1;
  for(int i = 0; i<n1;i++){
    cin >> val;
    x = insert(x, val);
  }
  cin >> n2;
  for(int i = 0; i<n2; i++){
    cin >> val;
    y= insert(y, val);
  }
  Node *sum = add(x, y);
  print (sum);
}
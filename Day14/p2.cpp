#include <iostream>
using namespace std;
struct Node{
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL){}
};
Node *rev(Node *head){
  Node *prev = NULL;
  Node *curr = head;
  while(curr){
    Node *move = curr->next;
    curr->next = prev;
    prev = curr;
    curr = move;
  }
  return prev;
}
Node *doubl(Node *head){
  head = rev(head);
  Node *curr = head;
  int temp = 0;
  while(curr){
    int sum = curr->data*2 + temp;
    curr->data = sum % 10;
    temp = sum/10;
    if(curr->next == NULL && temp > 0){
      curr->next = new Node(temp);
      temp = 0;
    }
    curr= curr->next;
  }
  return rev(head);
}
void print(Node *head){
  while(head){
    cout << head->data << " ";
    head = head-> next;
  }
  cout << endl;
}
Node * create(int n){
  if(n <=0) return NULL;
  int val;
  cin >> val;
  Node *head = new Node(val);
  Node *tail = head;
  for(int i = 1; i<n; i++){
    cin >> val;
    Node *newnode = new Node(val);
    tail-> next = newnode;
    tail = newnode;
  }
  return head;
}
int main(){
  int n;
  cin >> n;
  Node *head = create(n);
  head = doubl(head);
  print(head);
}
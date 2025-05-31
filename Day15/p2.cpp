#include <iostream>
using namespace std;
struct Node{
  int val;
  Node *prev;
  Node *next;
  Node(int x):val(x), prev(NULL), next(NULL){}
};
Node *create(Node *head, int x){
  Node *newnode = new Node(x);
  if(!head) return newnode;
  Node *temp = head;
  while(temp->next) temp = temp->next;
  temp->next = newnode;
  newnode->prev = temp;
  return head;
}
void print(Node *head){
  Node *temp = head;
  while(temp){
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}
Node *remnode(Node *head, int target){
  Node *curr = head;
  while(curr){
    if(curr->val == target){
      Node *del = curr;
      Node *x = curr->prev;
      Node *y = curr->next;
      if(x) x->next = y;
      else head = y;
      if(y) y->prev = x;
      curr = y;
      delete del;
    }
    else curr = curr->next;
  }
  return head;
}
int main(){
  Node *head = NULL;
  int elements, number_ele, target;
  cin >> number_ele;
  for(int i = 0; i<number_ele;i++){
    cin >> elements;
    head = create(head, elements);
  }
  cin >> target;
  head = remnode(head, target);
  print(head);
}
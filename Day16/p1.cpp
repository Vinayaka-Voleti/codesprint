#include <iostream>
using namespace std;
struct Node{
  int data;
  Node *next;
  Node(int x): data(x), next(NULL){}
};
void insert(Node *&head, int data){
  Node*newnode = new Node(data);
  Node *temp = head;
  if(!head){
    head = newnode;
    return;
  }
  while(temp->next) temp = temp->next;
  temp->next = newnode;
}
void print(Node *head){
  while(head){
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}
Node *mergesort(Node *l1, Node *l2){
  Node dummy(0);
  Node *curr = &dummy;

  while(l1 && l2){
    if(l1->data <= l2->data){
      curr->next = l1;
      l1 = l1->next;
    } else{
      curr->next = l2;
      l2 = l2->next;
    }
    curr = curr->next;
  }
  if(l1) curr->next = l1;
  else curr->next = l2;
  return dummy.next;
}
int main(){
  Node *l1 = NULL, *l2 = NULL;
  int n, m, data;
  cin >> n;
  cout << "List1: ";
  for(int i = 0; i<n; i++){
    cin >> data;
    insert(l1, data);
  }
  cin >> m;
  cout << "List2: ";
  for(int i = 0; i<m; i++){
    cin >> data;
    insert(l2, data);
  }
  Node *m1 = mergesort(l1,l2);
  print(m1);
}













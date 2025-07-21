#include <iostream>
using namespace std;
struct Node{
  string str;
  Node *next;
  Node(string x):str(x), next(NULL){}
};
Node *revpos(Node *head, int left, int right){
  if(!head || left == right) return head;
  Node *dummy = new Node("");
  dummy->next = head;
  Node *prev = dummy;
  for(int i = 1; i<left; i++) prev = prev->next;
  Node *curr = prev->next;
  for(int i = 0; i<right - left; i++){
    Node *temp = curr->next;
    curr->next = temp->next;
    temp->next = prev->next;
    prev->next = temp;
  }
  head = dummy->next;
  delete dummy;
  return head;
}
void insert (Node *&head, string str){
  Node *newnode = new Node(str);
  if(!head){
    head = newnode;
    return;
  }
  Node *temp = head;
  while(temp->next) temp = temp->next;
  temp->next = newnode;
}
void print(Node *head){
  for(Node*temp=head; temp!=NULL; temp=temp->next){
    cout << temp->str ;
    if(temp->next) cout << "->";
  }
  cout << endl;
}
int main(){
  Node *head = NULL;
  int left, right;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    insert(head, str);
  }
  cout << "left: ";
  cin >> left;
  cout << "right: ";
  cin >> right;
  head = revpos(head, left, right);
  print(head);
}
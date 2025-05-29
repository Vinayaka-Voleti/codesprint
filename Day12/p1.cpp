#include <iostream>
using namespace std;
struct Node{
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};
Node *sortTemps(Node *head){
  if(!head || !head->next) return head;
  Node negDummy(0), posDummy(0);
  Node *negList = NULL, *posListTail = &posDummy;
  Node *current = head;
  while(current){
    Node *nextTemp = current->next;
    current->next = NULL;
    if(current->val<0){
      current->next = negList;
      negList = current;
    }
    else{
      posListTail->next = current;
      posListTail = current;
    }
    current = nextTemp;
  }
  if(!negList) return posDummy.next;
  Node *negTail = negList;
  while(negTail->next) negTail = negTail->next;
  negTail->next = posDummy.next;
  return negList;
}
Node *buildList(int count){
  if(count <= 0) return NULL;
  int inpVal;
  cin >> inpVal;
  Node *head = new Node(inpVal);
  Node *current = head;
  for(int i = 2; i<=count; i++){
    cin >> inpVal;
    current->next = new Node(inpVal);
    current = current->next;
  }
  return head;
}
void display(Node *head){
  while(head){
    cout << head->val;
    if(head->next) cout << "->";
    head = head->next;
  }
  cout << endl;
}
int main(){
  int totalNodes;
  cout << "Enter number of nodes :" << endl;
  cin >> totalNodes;
  Node *head = buildList(totalNodes);
  head = sortTemps(head);
  cout << "Sorted List by Actual Temperature: " << endl;
  display(head);
}
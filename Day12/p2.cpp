#include <iostream>
using namespace std;
struct Node{
  int value;
  Node *next;
  Node(int x) : value(x), next(NULL) {}
  
};
Node *sort(Node *head){
  if(!head || !head->next) return head;
  Node *zeroH = new Node(0), *oneH = new Node(0), *twoH = new Node(0);
  Node *zeroT = zeroH, *oneT = oneH, *twoT = twoH;
  Node *current = head;
  while(current != NULL){
    if(current->value == 0){
      zeroT->next = current;
      zeroT = zeroT->next;
    }
    else if(current->value == 1){
      oneT->next = current;
      oneT = oneT->next;
      
    }
    else{
      twoT->next = current;
      twoT = twoT->next;
    }
    current = current->next;

  }
  zeroT->next = oneH->next ? oneH->next:twoH->next;
  oneT->next = twoH->next;
  twoT->next = NULL;
  head = zeroH->next;
  delete zeroH;
  delete oneH;
  delete twoH;
  return head;
}
void disp(Node *head){
   while(head){
     cout << head->value;
     if(head->next){
       cout << "->";
       
     }
     head=head->next;
   } 
  cout << endl;
}
Node *buildList(int count){
  if(count <= 0) return NULL;

  int inputVal;
  cin >> inputVal;
  Node *head = new Node(inputVal);
  Node *current = head;
  cout << "Enter value for node: ";
  for(int i = 2; i<=count; i++){
    cin >> inputVal;
    current->next = new Node(inputVal);
    current = current->next;
    
  }
  return head;
}
int main(){
  int totalNodes;
  cout <<"ENter nodes: ";
  cin >> totalNodes;
  Node *head = buildList(totalNodes);
  head = sort(head);
  cout << "Sorted List: " << endl;
  disp(head);
}
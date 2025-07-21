#include <iostream>
#include <vector>
using namespace std;
struct Node{
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL){}
  
};
Node *create(int n){
  if(n <=0) return NULL;
  int data;
  cin >> data;
  Node *start = new Node(data);
  Node *end = start;
  for(int i = 2; i<=n; i++){
    cin >>data;
    Node *newnode = new Node(data);
    end->next = newnode;
    end = newnode;
  }
  return start;
}
Node *middle(Node *start){
  Node *slow, *fast;
  slow = start;
  fast = start;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
void print(Node *start){
  cout << "[";
  while(start){
    cout << start->data;
    if(start->next){
      cout << ", ";
    }
    start = start->next;
  }
  cout << "]";
  cout << endl;
}
int main(){
  int n;
  cin >> n;
  Node *start = create(n);
  Node *middle_nodes = middle(start);
  print(middle_nodes);
}
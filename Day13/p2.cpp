#include <iostream>
using namespace std;
struct Node{
  int data;
  Node *left, *right;
  Node(int x) : data(x), left(NULL), right(NULL){}
  
};
Node *makeNode(int data){
  return new Node(data);
}
Node *addNode(Node* root, int data){
  if(!root){
    root = makeNode(data);
    return root;
  }
  Node * ptr = root;
  while(ptr-> right != NULL) ptr = ptr->right;
  Node *node = makeNode(data);
  ptr->right = node;
  node ->left = ptr;
  return root;
}
void insertSort(Node*& root){
  if(!root || !root->right) return;
  Node* temp = root->right;
  while(temp != NULL){
    Node* next = temp->right;
    Node* back = temp->left;
    back-> right = temp->right;
    if(temp->right) temp->right->left = back;
    while(back && back->data > temp->data) back = back->left;
    if(!back){
      temp->right = root;
      root->left = temp;
      temp-> left = NULL;
      root= temp;
    }
    else{
      temp->right = back->right;
      if(back->right) back->right->left = temp;
      back->right = temp;
      temp->left = back;
      
    }
    temp = next;
  }
}
void show(Node *root){
  while(root){
    cout << root->data;
    if(root->right) cout << "->";
    root = root->right;
    
  }
  cout << endl;
}
int main(){
  int size, value;
  cin >> size;
  Node* root = NULL;
  for(int i =0; i<size; i++){
    cin >> value;
    root = addNode(root, value);
  }
  insertSort(root);
  show(root);
  
}
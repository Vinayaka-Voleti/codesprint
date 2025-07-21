#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
struct Node{
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
  
};
Node *buildList(int arr[] , int size){
  if(size == 0)
    return NULL;
  Node * root = new Node(arr[0]);
  Node *ptr = root;
  for(int i = 1; i<size;i++){
    ptr->next = new Node(arr[i]);
    ptr = ptr ->next;
  }
  return root;
}
void disply(Node *groups[], int num){
  for(int i =0; i<num; i++){
    cout << "[";
    Node *temp = groups[i];
    while(temp){
      cout << temp->data;
      if(temp->next){
        cout << " , ";
      }
      temp = temp->next;
    }
    cout << "]";
    if(i != num-1) cout << " , ";
  }
    cout << endl;
  
}
void divide(Node *root, int num, Node *groups[]){
  int total = 0;
  for(Node *temp = root; temp != NULL; temp = temp->next) total ++;
  int minSize = total/num;
  int extra = total % num;

  Node * temp = root;
  for(int i = 0; i<num ; i++){
    groups[i] = temp;
    int currentSize = minSize + (extra > 0? 1 : 0);
    if(extra > 0){
      extra--;
    }
    for ( int j = 1 ; j<currentSize && temp; j++) temp = temp->next;
    if(temp){
      Node *nextGroup = temp->next;
      temp->next = NULL;
      temp = nextGroup;
    }
  }
}
int main(){
  int size;
  cin >> size;
  int arr[1000];
  for (int i = 0; i<size; i++){
    cin >> arr[i];
  }
  int num;
  cin >> num;
  Node *root = buildList(arr, size);
  Node **groups = new Node *[num];
  for(int i = 0 ; i<num; i++) groups[i] = NULL;
  divide(root, num, groups);
  disply(groups, num);
}
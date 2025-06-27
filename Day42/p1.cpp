#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
using namespace std;
struct Node{
  int val;
  Node *left;
  Node *right;
  Node(int x) : val(x), left(NULL), right(NULL) {}
};
int getDepth(Node *node){
  int d = 0;
  while(node){
    d++;
    node = node->left;
  }
  return d;
}
int countNodes(Node *root){
  if(!root) return 0;
  int leftD = getDepth(root->left);
  int rightD = getDepth(root->right);
  if(leftD = rightD) return (1<<leftD) + countNodes(root->right);
  else return (1 << rightD) + countNodes(root->left);
}
Node *buildTree(vector<string> &nodes){
  if(nodes.empty() || nodes[0] == "NULL") return NULL;
  Node *root = new Node(stoi(nodes[0]));
  queue <Node *> q;
  q.push(root);
  int i = 1;
  while(!q.empty() && i < nodes.size()){
    Node *curr = q.front();
    q.pop();
    if(nodes[i] != "NULL"){
      curr->left = new Node(stoi(nodes[i]));
      q.push(curr->left);
    }
    i++;
    if(i>=nodes.size()) break;
    if(nodes[i] != "NULL") {
      curr->right = new Node(stoi(nodes[i]));
      q.push(curr->right);
    }
    i++;
  }
  return root;
}
int main(){
  string str, token;
  getline(cin, str);
  istringstream iss(str);
  vector<string> nodes;
  while(iss >> token) nodes.push_back(token);
  Node *root = buildTree(nodes);
  cout << countNodes(root) << endl;
}
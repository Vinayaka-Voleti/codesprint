#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct Tree{
  int val;
  Tree *l;
  Tree *r;
  Tree(int x): val(x), l(NULL), r(NULL) {}
};
Tree *build(vector<string> &nodes){
  if(nodes.empty() || nodes[0] == "NULL") return NULL;
  Tree *root = new Tree(stoi(nodes[0]));
  queue<Tree *> q;
  q.push(root);
  int i =1;
  while(i<nodes.size()){
    Tree *curr = q.front();
    q.pop();
    if(nodes[i] != "NULL"){
      curr-> l =new Tree(stoi(nodes[i]));
      q.push(curr->l);
    }
    i++;
    if(i>= nodes.size()) break;
    if (nodes[i] != "NULL"){
      curr -> r = new Tree(stoi(nodes[i]));
      q.push(curr->r);
    }
    i++;
  }
  return root;
}
int maxDepth(Tree *root){
  if(!root) return 0;
  int lDepth = maxDepth(root->l);
  int rDepth = maxDepth(root->r);
  return max(lDepth, rDepth) + 1;
}
int main(){
  string str;
  getline(cin, str);
  istringstream iss(str);
  vector<string> nodes;
  string token;
  while(iss >> token) nodes.push_back(token);
  Tree * root = build(nodes);
  cout << maxDepth(root) << endl;
}
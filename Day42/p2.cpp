#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
struct Node{
  int val;
  Node *l;
  Node *r;
  Node(int x) : val(x), l(NULL), r(NULL) {}
};
Node *sortedArrtoBST(vector<int> &nums, int l, int r){
  if(l>r) return NULL;
  int mid = l + (r-l)/2;
  Node *root = new Node(nums[mid]);
  root->l = sortedArrtoBST(nums, l, mid-1);
  root->r = sortedArrtoBST(nums, mid+1, r);
  return root;
}
vector<string> level(Node *root){
  vector<string> res;
  if(!root) return res;
  queue<Node *> q;
  q.push(root);
  while(!q.empty()){
    Node *node = q.front();
    q.pop();
    if(node){
      res.push_back(to_string(node->val));
      q.push(node-> l);
      q.push(node-> r);
    }
    else res.push_back("NULL");
  }
  while(!res.empty() && res.back() == "NULL") res.pop_back();
  return res;
}
int main(){
  string s;
  getline(cin, s);
  istringstream iss(s);
  vector<int> nums;
  int x;
  while(iss >> x) nums.push_back(x);
  Node *root = sortedArrtoBST(nums, 0, nums.size()-1);
  vector<string> opt = level(root);
  for(string &val : opt) cout << val << " ";
  cout << endl;
}
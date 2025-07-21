#include <iostream>
#include <vector>
using namespace std;
void dfs(int n, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order){
  visited[n] = true;
  order.push_back(n);
  for(int nei : adj[n]){
    if(!visited[nei]) dfs(nei, adj, visited, order);
  }
}
vector<int> traverse(int n, vector<vector<int>> &adj){
  vector<bool> visited(n,false);
  vector<int> order;
  dfs(0, adj, visited, order);
  return order;
}
int main(){
  int n, m;
  cin >>n >>m;
  vector<vector<int>> adj(n);
  for(int i=0; i<m; i++){
    int u, v;
    cin >> u>> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> traversal = traverse(n, adj);
  cout << "Order of traversing castles: ";
  for(int castle: traversal) cout << castle <<" ";
  cout << endl;
}
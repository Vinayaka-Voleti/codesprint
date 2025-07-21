#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> kingdom(int n, vector<vector<int>> &adj){
  vector<int> v;
  vector<bool> visited(n, false);
  queue<int> q;
  visited[0] = true;
  q.push(0);
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    v.push_back(curr);
    for(int neighbor : adj[curr]){
      if(!visited[neighbor]){
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
  return v;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for(int i= 0; i<m; i++){
    int u, v;
    cin >> u>> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> order = kingdom(n, adj);
  cout << "Order of Visiting castles: ";
  for(int castle : order) cout << castle << " ";
  cout << endl;
}
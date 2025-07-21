#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int buy(vector<int> &ticket, int target){
  queue<pair<int, int>> queue1;
  for(int i = 0; i<ticket.size(); i++) queue1.push({i, ticket[i]});
  int time = 0;
  while(!queue1.empty()){
    pair<int, int> current;
    current = queue1.front();
    queue1.pop();
    current.second -= 1;
    time += 1;
    if(current.first == target && current.second == 0) break;
    if(current.second>0) queue1.push(current);
  }
  return time;
}
int main(){
  int n, m, target;
  vector<int> ticket;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> m;
    ticket.push_back(m);
  }
  cout << "target: ";
  cin >> target;
  int result = buy(ticket, target);
  cout << result << endl;
}
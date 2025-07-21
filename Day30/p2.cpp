#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n, m;
  cin >> n;
  vector<int> merlin(n);
  for(int i=0; i<n; i++) 
    cin >> merlin[i];
  cin >> m;
  vector<int> morgana(m);
  for(int i=0; i<m; i++) 
    cin >> morgana[i];
  int maxMorgana = *max_element(morgana.begin(), morgana.end());
  int cost = 0;
  for(int i=0; i<n; i++){
    if(merlin[i] <= maxMorgana) 
      cost += (maxMorgana + 1 - merlin[i]);
  }
  cout << cost << endl;
}
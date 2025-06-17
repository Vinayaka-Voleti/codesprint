#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  
  vector<int> themes(n);
  for(int i=0; i<n; i++)
    cin >> themes[i];
  
  unordered_set<int> ut;
  for(int i=0; i<n; i++)
    ut.insert(themes[i]);
  
  if(ut.size()>=k)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
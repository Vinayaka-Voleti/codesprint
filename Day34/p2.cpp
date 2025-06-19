#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int minRadius(vector<int> &house, vector<int> &heater){
  sort(heater.begin(), heater.end());
  int minRad = 0;
  for(int h:house){
    int left = 0, right = heater.size()-1;
    int dis = INT_MAX;
    while(left <= right){
      int mid = left + (right - left)/2;
      dis = min(dis, abs(heater[mid] - h));
      if(heater[mid] < h) left = mid + 1;
      else right = mid -1 ;
    }
  minRad = max(minRad, dis);
}
return minRad;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> house(n);
  cout << "Enter house position: "<< endl;
  for(int i = 0; i<n; i++) cin >> house[i];
  vector<int> heater(m);
  cout << "Enter heater position: " << endl;
  for(int i=0; i<m; i++) cin >> heater[i];
  int result = minRadius(house, heater);
  cout << result << endl;
}
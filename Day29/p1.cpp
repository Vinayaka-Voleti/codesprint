#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool treat(vector<long long> &vaccine, vector<long long> &patients, int n){
  for(int i=0; i<n; i++){
    if(vaccine[i] <= patients[i]) return false;
    return true;
  }
}
  int main(){
    int n;
    cin >> n;
    vector<long long> vaccine(n), patients(n);
    for(int i=0; i<n; i++) cin >> vaccine[i];
    for(int i=0; i<n; i++) cin >> patients[i];
    sort(vaccine.begin(), vaccine.end());
    sort(patients.begin(), patients.end());
    if(treat(vaccine, patients, n)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

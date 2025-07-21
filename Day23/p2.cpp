#include <iostream>
#include <queue>
#include <string>
using namespace std;
string predictWinningParty(string str){
  queue<int> radiant, dire;
  int n = str.size();
  for(int i = 0; i<n; i++){
    if(str[i] == 'R') radiant.push(i);
    else if(str[i] == 'D') dire.push(i);
  }
while(!radiant.empty() && !dire.empty()){
  int rIndex = radiant.front();
  int dIndex = dire.front();
  radiant.pop(); dire.pop();
  if(rIndex < dIndex) radiant.push(rIndex+n);
  else dire.push(dIndex+n);
}
return radiant.empty()? "Dire" : "Radiant";

}
int main(){
  string str;
  cin >> str;
  string result = predictWinningParty(str);
  cout << result << endl;
}
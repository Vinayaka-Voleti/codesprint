#include <iostream>
#include <set>
#include <string>
using namespace std;
int countSlips(string &str){
  int x=0, y=0;
  set<string> visit;
  visit.insert("0,0");
  int slips =0;
  for(char move : str){
    if(move == 'L') x--;
    else if (move == 'R') x++;
    else if (move == 'U') y++;
    else if (move == 'D') y--;
    string position = to_string(x) + "," + to_string(y);
    if(visit.count(position)) slips++;
    else visit.insert(position);
  }
  return slips;
}
int main(){
  string str;
  cin >> str;
  cout << countSlips(str) << endl;
}
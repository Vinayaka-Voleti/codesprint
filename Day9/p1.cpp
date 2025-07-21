#include <iostream>
#include <vector>
using namespace std;
int main(){
  string pattern, logStream;
  cin >> logStream >> pattern;

  vector<int> result;
  if(pattern.size()>logStream.size()){
    cout << endl;
    return 0;
  }
  vector<int> Pcount(26, 0), Wcount(26, 0);
  for(char c: pattern){
    Pcount[c- 'a']++;
    
  }
  int Wsize = pattern.size();
  for(int i = 0; i< logStream.size(); i++){
    Wcount[logStream[i] - 'a']++;
    if(i>= Wsize){
      Wcount[logStream[i-Wsize] -'a']--;
    }
    if(Wcount == Pcount){
      result.push_back(i - Wsize+ 1);
      
    }
  } 
  for(int j : result){
    cout << j << " ";
  }
  cout << endl;
    
}
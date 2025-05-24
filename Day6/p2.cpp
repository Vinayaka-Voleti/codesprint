#include <iostream>

using namespace std;
bool vowels(string& name){
  char c = name[0];
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
    return true;
  } else {
    return false;
  }
}
bool isDup(string res[], int n, string& name){
  for(int i =0; i<n; i++){
    if(res[i] == name){
      return true;
    }
  }
  return false;
}
int main(){
  int n;
  cin >> n;
  string res[100];
  int count = 0;
  for(int i = 0; i<n; i++){
    string name;
    cin >> name;

    if(vowels(name) && !isDup(res, count, name)){
      res[count] = name;
      count++;
    }
  }
  cout << count << endl;
  for(int i=0; i<count; i++){
    cout << res[i] << endl;
  }
}

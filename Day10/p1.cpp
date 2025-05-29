#include <iostream>
#include <vector>
using namespace std;
int main(){
  string digit;
  cin >> digit;
  vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> result;
  int n = digit.size();
  if(digit.empty() || n> 4){
    cout << "Enter between 1 to 4 digits only" << endl;
    return 0;
  }
  if(n == 1){
    string letters = keypad[digit[0] - '0'];
    for(char c : letters){
      result.push_back(string(1, c));
      
    }
  }
    else if (n == 2){
    string l1 = keypad[digit[0] - '0'];
    string l2 = keypad[digit[1] - '0'];
    for(char c1 : l1){
      for(char c2 : l2){
        result.push_back(string(1, c1) + c2);
      }
    }
    }
  
else if (n == 3){
  string l1 = keypad[digit[0] - '0'];
  string l2 = keypad[digit[1] - '0'];
  string l3 = keypad[digit[2] - '0'];
  for(char c1 : l1){
    for(char c2 : l2){
      for (char c3 : l3) {
        result.push_back(string(1, c1) + c2 + c3);
      }
    }
  }
}
else if (n == 4){
  string l1 = keypad[ digit[0] - '0'];
  string l2 = keypad[digit[1] - '0'];
  string l3 = keypad[digit[2] - '0'];
  string l4 = keypad[digit[3] - '0'];
  for(char c1 : l1){
    for(char c2 : l2){
      for(char c3 : l3){
        for(char c4 : l4){
          result.push_back(string(1, c1) + c2 + c3 + c4);
        }
      }
    }
  }
}
cout << "Letter combinations: \n";
for(const string& combo : result){
  cout << combo <<  " ";
}
cout << endl;
 }

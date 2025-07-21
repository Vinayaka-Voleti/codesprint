#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
string firstNonRepeating(string &str){
  unordered_map<char, int> freq;
  queue<char> queue1;
  string result;
  for(char ch : str){
    freq[ch]++;
    queue1.push(ch);
    while(!queue1.empty() && freq[queue1.front()] > 1) queue1.pop();
    if(queue1.empty()) result += '#';
    else result += queue1.front();
  }
  return result;
}
int main(){
  string str;
  cin >> str;
  string result = firstNonRepeating(str);
  cout << "Result: " << result << endl;
}
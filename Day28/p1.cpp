#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
string rearrange(string &str){
  unordered_map<char, int> freq;
  for(int i=0; i<str.size(); i++){
    char ch = str[i];
    if(freq.find(ch) != freq.end()) freq[ch]++;
    else freq[ch] = 1;
  }
  priority_queue<pair<int, char>> maxHeap;
  for(auto j = freq.begin(); j != freq.end(); j++){
    int count = j->second;
    char ch = j->first;
    maxHeap.push(make_pair(count, ch));
  }
  string result = "";
  pair<int, char> prev;
  prev.first = 0;
  prev.second = '#';
  while(!maxHeap.empty()){
    pair<int, char> current = maxHeap.top();
    maxHeap.pop();
    int count = current.first;
    char ch = current.second;
    result += ch;
    count --;
    if(prev.first > 0) maxHeap.push(prev);
    prev.first = count;
    prev.second = ch;
  }
  if(result.length() != str.length()) return "";
  return result;
}
int main(){
  string str, result;
  cin >> str;
  result = rearrange(str);
  if(result == "") cout << "" << endl;
  else cout << result << endl;
}
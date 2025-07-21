#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int MAXNUM = 100005;
int BIT[MAXNUM];
void update(int index, int value, int size){
  while(index <=size){
    BIT[index] += value;
    index += index & -index;
  }
}
int query(int index){
  int sum = 0;
  while(index > 0){
    sum += BIT[index];
    index -= index & -index;
  }
  return sum;
}
int main(){
  int n, size;
  cin >> n;
  vector<string> words(n);
  for(int i =0; i<n; i++) cin >> words[i];
  vector<string> word = words;
  sort(word.begin(), word.end());
  word.erase(unique(word.begin(), word.end()), word.end());
  unordered_map<string, int> wordIndex;
  for(int i = 0; i<word.size(); i++) wordIndex[word[i]] = i+1;
  size = word.size();
  for(int i = 0; i<n; i++){
    int index = wordIndex[words[i]];
    int nice = query(index - 1);
    cout << nice << endl;
    update(index, 1, size);
  }
}
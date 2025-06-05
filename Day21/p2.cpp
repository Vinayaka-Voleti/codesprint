#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> deckk(vector<int> &deck){
  sort(deck.begin(), deck.end());
  deque<int> deque1;
  for(int i = deck.size()-1; i>=0; i--){
    if(!deque1.empty()){
      deque1.push_front(deque1.back());
      deque1.pop_back();
    }
    deque1.push_front(deck[i]);
  }
  return {deque1.begin(), deque1.end()};
}
vector<int> rev(vector<int>&deck){
  deque<int> deque1(deck.begin(), deck.end());
  vector<int> reveal;
  while(!deque1.empty()){
    reveal.push_back(deque1.front());
    deque1.pop_front();
    if(!deque1.empty()){
      deque1.push_back(deque1.front());
      deque1.pop_front();
    }
  }
  return reveal;
}
int main(){
  int n;
  cin >> n;
  vector<int> deck(n), result, revealseq;
  for(int &card: deck) cin >> card;
  result = deckk(deck);
  for(int card : result) cout << card<< " ";
  cout << endl;
  revealseq = rev(result);
  for(int card : revealseq) cout << card << " ";
  cout << endl;
}
#include <iostream>
#include <string>
using namespace std;
int main(){
  string line, pattern;
  cin >> line >> pattern;

  int l = line.size(), p = pattern.size();
  const int p1 = 31, mod = 1e9 + 9;

  long pattern_hash = 0, line_hash = 0, pow = 1;
  long p_pow = 1;
  for(int i = 1; i< p; i++){
    p_pow = (p_pow * p1) % mod;
    
  }
  for(int i = 0; i<p ; i++){
    pattern_hash = (pattern_hash * p1 + (pattern[i] - 'a' + 1)) % mod;
    line_hash = (line_hash * p1 + (line[i] - 'a' + 1)) % mod;
    
  }
  if(line_hash == pattern_hash && line.substr(0, p) == pattern) cout << 0 << " ";
  for (int i = 1; i+ p <= l; i++){
    line_hash = (line_hash - (line[i-1] - 'a' + 1) * p_pow % mod + mod ) % mod;
    line_hash = (line_hash *p1 +(line[i + p -1 ] - 'a' + 1)) % mod;
    if(line_hash == pattern_hash && line.substr(i, p) == pattern)
      cout << i << " ";
  }
  cout << endl;
}
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cstdlib>
using namespace std;
long long gcd(long long a, long long b){
  return b == 0? a: gcd(b, a%b);
}
long long lcm(long long a, long long b){
  return abs(a*b)/gcd(a, b);
}
pair<long long, long long> parseFrac(const string &frac){
  int slash = frac.find('/');
  long long n = stoll(frac.substr(0, slash));
  long long den = stoll(frac.substr(slash + 1));
  return {
    n,
    den
  };
}
pair<long long, long long> evaluate(string &ex){
  long long n = 0, den = 1;
  size_t i = 0;
  while(i<ex.size()){
    int sign = 1;
    if(ex[i] == '+' || ex[i] == '-'){
      if(ex[i] == '-') sign = -1;
      i++;
    }
    size_t start = i;
    while(i<ex.size() && ex[i] != '+' && ex[i] != '-') i ++;
    pair<long long, long long> f = parseFrac(ex.substr(start, i - start));
    long long currNum = f.first *sign;
    long long currDen = f.second;
    long long comDen = lcm(den, currDen);
    n = n* (comDen/ den) + currNum *(comDen/ currDen);
    den = comDen;
    long long g = gcd(abs(n), den);
    n /= g;
    den /= g;
  }
  if(den < 0){
    n = -n;
    den = -den;
  }
  return {
    n,
    den
  };
}
int main(){
  string str;
  getline(cin, str);
  pair <long long, long long> result = evaluate(str);
  long long resNum = result.first;
  long long resDen = result.second;
  cout << resNum << '/' << resDen << endl;
}
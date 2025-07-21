#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<bool> generate(int maxNum){
  vector<bool> isprime(maxNum+1, true);
  isprime[0] = isprime[1] = false;
  for(int i=2; i*1<=maxNum; i++){
    if(isprime[i]){
      for(int j = i*i; j<=maxNum; j +=i) isprime[j] = false;
    }
  }
  return isprime;
}
vector<int> prime(vector<bool> &isprime, int n){
  vector<int> primes;
  for(int i=2; i<= n; i++){
    if(isprime[i]) primes.push_back(i);
  }
  return primes;
}
int main(){
  int n;
  cin >>n;
  vector<bool> isprime = generate(n);
  vector<int> primes = prime(isprime, n);
  int size = primes.size();
  vector<bool> primeindex = generate(size);
  for(int i = 1; i<= size; i++){
    if(primeindex[i]) cout << primes[i-1] << " ";
  }
}
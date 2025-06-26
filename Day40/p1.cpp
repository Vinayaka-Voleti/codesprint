#include <iostream>
#include <cmath>
using namespace std;
double Pow(double x, long long n){
  if(n == 0) return 1.0;
  if(n<0){
    x = 1.0/x;
    n = -n;
  }
  if(n%2 == 0){
    double half = Pow(x, n/2);
    return half*half;
  }
  else return x* Pow (x, n-1);
}
int main(){
  double x;
  int n;
  cin >> x>> n;
  cout << Pow(x, (long long)n) << endl;
}
#include <iostream>
#include <string>
using namespace std;
const string num1[] = {"", "One", "Two", "Three", "Four", "Five",
                      "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                      "Twelve", "Thirteen", "Fourteen", "Fifteen", 
                      "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const string num2[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                      "Sixty", "Seventy", "Eighty", "Ninety"};
const string num3[] = {"Billion", "Million", "Thousand", ""};
const int divisor[] = {1000000000, 1000000, 1000, 1};
string convert(int n){
  if(n == 0) return "";
  if(n<20) return num1[n];
  if(n<100)
    return num2[n/10]+ (n%10? " " +convert(n%10): "");
  return num1[n/100] + " Hundred" + (n%100? " "+ convert(n%100): "");
}
string helper(int n, int index = 0){
  if(index >= 4) return "";
  if(n>= divisor[index]){
    int part = n/divisor[index];
    int result = n%divisor[index];
    string res = convert(part);
    if(!num3[index].empty())
      res += " "+num3[index];
    if(result != 0) res +=" "+helper(result, index+1);
    return res;
  }
  else return helper(n, index+1);
}
string NumToWords(int n){
  if(n == 0) return "Zero";
  return helper(n);
}
int main(){
  int n;
  cin >> n;
  if(n<0) cout << "No negitive numbers" << endl;
  else cout << NumToWords(n) << endl;
}
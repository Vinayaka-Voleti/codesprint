#include <iostream>
using namespace std;
bool isAffordable(int budget, int iceCreamPrices[], int n)
{
  for(int i = 0; i < n; i++)
    {
      if(iceCreamPrices[i] == budget) return true;
    }
  return false;
}

int main()
{
  int budget, iceCreamPrices[1000], n;

  cout << "Enter budget Shivam has: " << endl;
  cin >> budget;

  cout << "Enter number of IceCreams: " <<endl;
  cin >> n;

  cout << "Enter the list of IceCreamPrices: " << endl;
  for(int i = 0; i < n; i++ ){
    cin >> iceCreamPrices[i];
  }
  if(isAffordable( budget, iceCreamPrices, n)){
    cout << "true";
  } else{
    cout << "false";
  }


  return 0;
}
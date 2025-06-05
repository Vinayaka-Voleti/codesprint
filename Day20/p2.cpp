#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextsmallest(vector<int> &arr, vector<int> &nextgreatest){
  int n = arr.size();
  vector<int> result(n ,-1);
  for(int i = 0; i < n; i++){
    int a = nextgreatest[i];
    if(a != -1){
      for(int j = a+1 ;j < n; j++){
        if(arr[j] < arr[a]){
          result[i] = arr[j];
          break;
        }
      }
    }
  }
  return result;
}
vector<int> nextgreater(vector<int> &arr){
  int n = arr.size();
  vector<int> nextGreater(n, -1);
  stack<int> stack1;
  for(int i = 0; i<n; i++){
    while(!stack1.empty() && arr[stack1.top()] < arr[i]){
      nextGreater[stack1.top()] = i;
      stack1.pop();
    }
    stack1.push(i);
  }
  return nextGreater;
}
int main(){
  int n;
  vector<int> greatest, result;
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the elements: " << endl;
  for(int i = 0; i<n; i++) cin >> arr[i];
  greatest = nextgreater(arr);
  result = nextsmallest(arr, greatest);
  for(int i = 0; i < n; i++){
    if(i == n-1) cout << result[i] << endl;
    else cout << result[i] << ' ';
  } 
}
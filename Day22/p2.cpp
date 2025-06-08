#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int UnableToEat(vector<int> &students, vector<int> &sandwiches){
  queue<int> queue1;
  for(int n: students) queue1.push(n);
  int count = 0, index = 0;
  while(!queue1.empty() && count < queue1.size()){
    if(queue1.front() == sandwiches[index]){
      queue1.pop();
      index++;
      count = 0;
    }
    else{
      queue1.push(queue1.front());
      queue1.pop();
      count++;
    }
  }
  return queue1.size();
}
int main(){
  int n;
  cin >> n;
  vector<int> students(n), sandwiches(n);
  for(int i = 0; i<n; i++) cin >> students[i];
  for(int i = 0; i< n; i++) cin >> sandwiches[i];
  int result = UnableToEat(students, sandwiches);
  cout << result <<endl;
}
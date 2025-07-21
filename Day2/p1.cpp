#include <iostream>
using namespace std;
int main(){
  int n, magical_score = 0;
  cin >> n;

  if( n<3 || n>100){
    cout<< "Invalid input" << endl;
    return 0;
  }
 
  int score[n];
  for(int i = 0; i < n; i ++){
    cin >> score[i];
  }
  for(int i = 1; i<n-1;i++){
    if(score[i]>score[i-1] && score[i]>score[i+1]){
      magical_score++;
    }
  }
  cout << magical_score << endl;
}
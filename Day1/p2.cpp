#include <iostream>
using namespace std;
int main(){
  int n, score; 
  int good_shots = 0, missed_shots = 0;
  cout << "Enter the number of shots taken :";
  cin >> n;
  
  for(int i = 0 ; i< n ; i++){
   cout << "Enter Score for " << i+1 << " shot: " << endl;
    cin >> score;

    if(score >=7){
      good_shots++;
    }
    else {
      missed_shots++;
    }
  }

  cout << good_shots << " " << missed_shots;
  
}
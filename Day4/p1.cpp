#include <iostream>
using namespace std;
int main(){

    int n;
    cin >> n;
    if(n<3 || n>1000) return 0;
    if(n%2 == 0) return 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            if (i == j){
                cout << i+1 << ' ' ;
            }
            else if(i+j == n-1){
                cout << j+1 << ' ';

            }
            else{
                cout << '-' << ' ';
            }
        }
        cout << endl;
    }
    
}
#include <bits/stdc++.h>
using namespace std;

string makeFancyString(string s) {
    string res = "";
    res.push_back(s[0]);
    int freq = 1;
    for(int i = 1; i<s.length(); i++) {
        if(s[i] == res.back()){
            freq ++;
            if(freq < 3) {
                res.push_back(s[i]);
            }
        }
        else{
            res.push_back(s[i]);
            freq = 1;
        }
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    string res = makeFancyString(s);
    cout << res << endl;

    return 0;


}
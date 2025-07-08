#include <bits/stdc++.h>
using namespace std;

string even(int n){
    int m=n&1;
    if(m==0) return "even";
    else return "odd";
}

int main(){
    int n;
    cout << "Enter a number";
    cin >> n;

    string a=even(n);
    cout<< a;
    return 0;
    
}
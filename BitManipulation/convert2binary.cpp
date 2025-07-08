#include <bits/stdc++.h>
using namespace std;

string convert2binary(int n){
    string res="";

    while(n!=0){
        if(n%2==1) res+='1';
        else res+='0';
        n=n/2;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    int num;

    cout<<"Enter a num:";
    cin >> num;
    cout<<"Binary Equivalent is:";
    string a=convert2binary(num);
    cout << a;

    return 0;
}
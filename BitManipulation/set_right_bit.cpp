#include<bits/stdc++.h>
using namespace std;

int set_unset(int n){
    return n|n+1;
}

int main(){
    int n;
    cout<<"enter a number:";
    cin>> n;

    int a=set_unset(n);
    cout<< a;
}
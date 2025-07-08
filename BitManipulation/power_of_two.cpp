#include<bits/stdc++.h>
using namespace std;

bool power_of_two(int n){
    return (n>0 && (n&(n-1))==0) ;
}

int main(){
    int n;
    cout << "enter a number";
    cin >> n;

    int a=power_of_two(n);
    cout<< a;
}
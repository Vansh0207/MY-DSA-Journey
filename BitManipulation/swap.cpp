#include <bits/stdc++.h>
using namespace std;

int swap(int a,int b){
    a=a^b;
    b=a^b;
    a=a^b;

    cout<<a<<"\n";
    cout<<b;
}

int main(){
    int a,b;

    cout<<"enter a:";
    cin>> a;
    cout<<"enter b:";
    cin>> b;

    swap(a,b);
}
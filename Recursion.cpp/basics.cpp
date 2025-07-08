#include<bits/stdc++.h>
using namespace std;

int cnt=0;

void basic(){
    

    if(cnt==10){
        return;
    }
    else{
        cout<< cnt;
        cnt++;
        basic();
        
    }
    
}

void printName(){
    
}

int main(){
    basic();
}
#include<bits/stdc++.h>
using namespace std;

void prime_number(int n){
    int cnt=0;
    for(int i=1;i<sqrt(n);i++){
        if(n%i==0){
            cnt+=1;

            if(n/i != i) cnt+=1;
        }
    }

    if(cnt==2) cout<<"It is a Prime Number";
    else cout<<"It is not a Prime Number";
}

int main(){
    int n;

    cout<<"enter a number:";
    cin>> n;

    prime_number(n);
    

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

vector<int> prime_factors(int n){
    vector<int> a;

    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            a.push_back(i);

            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n!=1) a.push_back(n);

    return a;
}

int main(){
    int n;

    cout<<"enter a number:";
    cin>> n;

    vector<int> a=prime_factors(n);
    
    for(auto it:a){
        cout<<it<<"\n";
    }
    

    return 0;
}

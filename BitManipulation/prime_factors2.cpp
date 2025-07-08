//BETTER APPROACH    O(sqrt(N) x 2 x sqrt(N)) approx

#include<bits/stdc++.h>
using namespace std;

int prime(int n){
    int cnt=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            cnt+=1;

            if(n/i != i) cnt+=1;
        }
    }

    if(cnt==2) return 1 ;
    else return 0;
}

vector<int> primefactors(int n){

    vector<int> a;

    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(prime(i)) a.push_back(i);

            if(prime(n/i)) a.push_back(n/i);
        }
    }
    return a;
}

int main(){
    int n;

    cout<<"enter a number:";
    cin>> n;

    vector<int> a=primefactors(n);
    
    for(auto it:a){
        cout<<it<<"\n";
    }
    

    return 0;
}
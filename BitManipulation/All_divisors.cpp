#include<bits/stdc++.h>
using namespace std;

void allDivisors(int n){
    vector<int> a;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            a.push_back(i);

            if(i != (n/i)){
                a.push_back(n/i);
            }
        }
        sort(a.begin(),a.end());

    }
    for(auto it:a){
        cout<<it<<" ";
    }
}

int main(){
    int n;

    cout<<"enter a number:";
    cin>> n;
    allDivisors(n);

    return 0;
}



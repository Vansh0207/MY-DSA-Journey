#include<bits/stdc++.h>
using namespace std;

int f(int idx,vector<int> &dp){
    if(idx<=2) return idx;

    if(dp[idx]!=-1) return dp[idx];
    
    return dp[idx]=f((idx-1),dp)+f((idx-2),dp);
}

int main(){
    int idx;
    cout<<"enter idx:";
    cin>>idx;
    vector<int> dp(idx+1,-1);

    cout<<f(idx,dp);

    return 0;
}
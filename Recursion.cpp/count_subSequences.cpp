#include<bits/stdc++.h>
using namespace std;

int subSequence(int s,vector<int> &arr,int idx,int sum,int n){
    if(s>sum) return 0;

    if(idx==n){
        if(s==sum){
           return 1;
        }
        else return 0;
        
    }

    s+=arr[idx];
    int l=subSequence(s,arr,idx+1,sum,n);

    s-=arr[idx];

    int r=subSequence(s,arr,idx+1,sum,n);

    return l+r;

}

int main(){
    int n=3;
    int idx=0;
    vector<int> arr={1,2,1};
    int sum=2;

    cout<< subSequence(0,arr,0,sum,n);

    return 0;
}
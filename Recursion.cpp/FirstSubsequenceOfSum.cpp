#include<bits/stdc++.h>
using namespace std;

bool subSequence(int s,vector<int> &arr,int idx,int sum,vector<int> &a,int n){
    if(idx==n){
        if(s==sum){
            for(auto it: a){
                cout<<it<<" ";
                   
            }
            cout<<endl;
            return true;   //condition satisfied
        }
        else return false;  //not satisfied
    }

    a.push_back(arr[idx]);

    s+=arr[idx];

    if(subSequence(s,arr,idx+1,sum,a,n)==true) return true;

    s-=arr[idx];
    a.pop_back();

    if(subSequence(s,arr,idx+1,sum,a,n)==true) return true;


    return false;
}


int main(){
    int n=3;
    int idx=0;
    vector<int> arr={1,2,1};
    int sum=2;
    vector<int> a;

    subSequence(0,arr,0,sum,a,n);

    return 0;
}
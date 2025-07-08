//Find Nth Root of M

#include<bits/stdc++.h>
using namespace std;

//if >m == 2;
//if =m == 1;
//if <m == 0;

int func(int n,int m,int mid){
    long long ans=1;

    for(int i=1;i<=n;i++){
        ans=ans*(long long)mid;

        if(ans>m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}

int Find_Nth_Root(int n,int m){
    int low=1;
    int high=m;

    while(low<=high){
        int mid=low+(high-low)/2;
        int midN=func(n,m,mid);

        if(midN==1){
            return mid;
        }
        else if(midN==0){
            low=mid+1;
        }
        else high=mid-1;
    }
    return -1;
}

int main(){
    int n,m;

    cout << "enter the n:";
    cin >> n;

    cout << "enter the m:";
    cin >> m;
    cout<<Find_Nth_Root(n,m);
    return 0;
}
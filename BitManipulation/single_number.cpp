//Complexity of this code is O(nlog m)+O(m)   where m=n/2+1

#include<bits/stdc++.h>
using namespace std;

vector<long long int> single_number(long long int arr[100],long long int n){
    map<int,int> mpp;

    for(long long int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    vector<long long int> ans;

    for(auto it:mpp){
        if(it.second%2==1){
            ans.push_back(it.first);
        }

    }
    return ans;
}

int main(){
    long long int n;
    long long int arr[100];

    cout<< "enter the size:";
    cin>> n;
    cout<<"enter array elements:";

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<long long int> a=single_number(arr,n);
    cout<< "single elements are:";
    for(auto it: a){
        cout<< it<<"\n";
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

vector<long long int> single_number(long long int arr[100],long long int n){

    long long int x=0;
    for(int i=0;i<n;i++){
        x=x^arr[i];
    }

    long long int rm=(x&(x-1))^x;

    long long int b1=0;
    long long int b2=0;

    for(int i=0;i<n;i++){
        if(arr[i]&rm){
            b1=b1^arr[i];
        }
        else{
            b2=b2^arr[i];
        }
    }
    return {b1,b2};

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


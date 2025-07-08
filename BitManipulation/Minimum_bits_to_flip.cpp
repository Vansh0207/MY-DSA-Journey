#include<bits/stdc++.h>
using namespace std;

int count_flip_bits(int start,int end){
    int ans=start^end;
    int count=0;

    while(ans){
        count+=ans&1;
        ans>>=1;
    }
    return count;
}

int main(){
    int start,end;
    
    cout<<"enter start number:";
    cin>>start;
    cout<<"enter end number:";
    cin>>end;

    int a=count_flip_bits(start,end);
    cout<< a;
}
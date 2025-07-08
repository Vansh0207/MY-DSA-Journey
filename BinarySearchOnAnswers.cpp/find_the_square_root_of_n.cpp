//Find the Square root of n

#include<bits/stdc++.h>
using namespace std;

int root(int n){
    int low=1;
    int high=n;

    while(low<=high){
        int mid=low+(high-low)/2;
        int ans=mid*mid;

        if(ans<=n){
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return high;
} 

int main(){
    int number;

    cout << "enter the Number:";
    cin >> number;
    cout<<root(number);
    return 0;
}
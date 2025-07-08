#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
        int count=0;
        vector<int> a;

        for(int i=2;i<n;i++){
            a[i]=1;
        }

         for(int i=2;i<n;i++){
            if(a[i]==1){
                for(int j=2*i;j<=n;j+=i){
                    a[j]=0;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(a[i]==1){
                count++;
            }
        }

        return count;
    }


int main(){
    int n;

    cout<<"enter a number:";
    cin>> n;
    int a=countPrimes(n);
    cout<<a;

    return 0;
}



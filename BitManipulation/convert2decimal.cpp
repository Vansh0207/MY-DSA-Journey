#include <bits/stdc++.h>
using namespace std;

int convert2decimal(string a){
    int len=a.size();
    int num=0;
    int p2=1;

    for(int i=len-1;i>=0;i--){
        if(a[i]=='1'){
            num+=p2;
        }
        p2=p2*2;
    }
    return num;
}

int main(){
    string num;

    cout<<"Enter a Binary num:";
    cin >> num;
    cout<<"Decimal Equivalent is:";
    int a=convert2decimal(num);
    cout << a;

    return 0;
}
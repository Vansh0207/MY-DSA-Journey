#include <bits/stdc++.h>
using namespace std;

int main(){
    int num,i;
    cout << "enter a number:";
    cin >> num;
    cout << "enter a bit";
    cin >> i;

    //Get the ith bit
    cout<<((num>>i-1)&1)<<"\n";
    //Set the ith bit;
    cout<<(num|(1<<i-1))<<"\n";
    //Clear the ith bit
    cout<<(num&(~(1<<i-1)));

    return 0;
}
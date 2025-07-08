#include<bits/stdc++.h>
using namespace std;

string palindrome(string s){
    int n=s.size();
    int left=0;
    int right=0;
    int i=0;

    reverse(s.begin(),s.end());

    while(i<n){
        while(i<n && s[i]==' ') i++;
        if(i==n) break;

        while(i<n && s[i]!=' '){
            s[right]=s[i];
            right++;
            i++;
        }
        reverse(s.begin()+left,s.begin()+right);
        s[right]=' ';
        right++;
        left=right;
        i++;
    }
    s.resize(right-1);
    return s;
}

int main(){
    string s;

    cout<<"enter a string:";
    getline(cin,s);

    cout<<palindrome(s);

    return 0;
}
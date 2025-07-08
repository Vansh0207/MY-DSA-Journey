#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
        int depth=0;
        int n=s.size();
        string res="";

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(depth>0) res+=s[i];
                depth++;
            }
            else{
                depth--;
                if(depth>0) res+=s[i];
            }
        }

        return res;
}


int main(){
    string s;

    cout<<"enter a string:";
    cin>> s;

    cout<<removeOuterParentheses(s);

    return 0;
}
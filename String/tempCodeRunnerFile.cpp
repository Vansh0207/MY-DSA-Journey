#include<bits/stdc++.h>
using namespace std;

string prefix(vector<string> s){
    sort(s.begin(),s.end());
        int n=s.size();
        string m=s[0];
        string o=s[n-1];
        string ans="";

        for(int i=0;i<m.size();i++){
            if(m[i]==o[i]){
                ans+=m[i];
            }
            else break;
        }
        return ans;
}


int main(){
    int n;
    vector<string> s(n);
    cout<<"enter size:";
    cin>>n;

    cout<<"enter a string:";
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    

    string a=prefix(s);
    cout<<a;

    return 0;
}
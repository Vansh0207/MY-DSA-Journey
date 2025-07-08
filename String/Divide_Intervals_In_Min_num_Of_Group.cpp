#include<bits/stdc++.h>
using namespace std;

void group_count(vector<vector<int>> &intervals,int n){
    vector<int> start;
    vector<int> end;
    for(int i=0;i<n;i++){
        start.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
    }

    sort(start.begin(),start.end());
    sort(end.begin(),end.end());

    int ep=0;
    int gp=0;

    for(auto it: start){
        if(it>end[ep]) ep++;

        else gp++;
    }

    cout<<"No. of Groups are:"<<gp<<endl;

}

int main(){
    int n;

    cout<<"enter number of elements:";
    cin>>n;

    vector<vector<int>> intervals(n,vector<int>(2));

    //[[5,10],[6,8],[1,5],[2,3],[1,10]]

    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }

    group_count(intervals,n);
    return 0;

}
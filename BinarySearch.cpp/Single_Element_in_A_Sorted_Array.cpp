//single element in a sorted array [1,1,2,2,3,3,4,5,5,6,6]

#include<bits/stdc++.h>
using namespace std;

int singleElement(int arr[0],int n){

    if(n==1) return arr[0];

    if(arr[0]!=arr[1]) return arr[0];

    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    int low=0;
    int high=n-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];                     //(even,odd)  ->  left half
                                                                                              //(odd,even)  ->  right half
              //on left half
        if((mid%2==1 && arr[mid]==arr[mid-1])||(mid%2==0 && arr[mid]==arr[mid+1])) low=mid+1;

        else high=mid-1;
    }
    return -1;
}

int main(){
    int arr[100];
    int n;

    cout << "enter the number of elements in array:";
    cin >> n;

    cout << "enter the elements in sorted order\n";

    for(int i=0;i<n;i++){
        cout << "enter array element:";
        cin >> arr[i];
    }

   int nums=singleElement(arr,n);
   cout <<" Single Element : "<< nums;
    return 0;
}
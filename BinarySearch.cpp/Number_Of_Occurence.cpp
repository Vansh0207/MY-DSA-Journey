//Number of Occurence of an element

#include <bits/stdc++.h>
using namespace std;

int first(int arr[100],int n,int k){
    int l=0;                     //l=low or left
    int h=n-1;                //h=high or right
    int first=-1;

    while(l<=h){
        int mid=(l+h)/2;

        if(arr[mid]==k){
            first=mid;
            h=mid-1;
        }
        else if(arr[mid]<k){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return first;
}
int last(int arr[100],int n,int k){
    int l=0;
    int h=n-1;
    int last=-1;

    while(l<=h){
        int mid=(l+h)/2;

        if(arr[mid]==k){
            last=mid;
            l=mid+1;
        }
        else if(arr[mid]<k){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return last;
}

int count(int arr[100], int n, int x) {
	// Write Your Code Here
	int f=first(arr,n,x);
	
	if(f==-1) return 0;

	int l=last(arr,n,x);

	return (l-f+1);
}
int main(){
    int arr[100];
    int n;
    int k;

    cout << "enter the number of elements in array:";
    cin >> n;

    cout << "enter the target element:";
    cin >> k;

    cout << "enter the elements in sorted order\n";

    for(int i=0;i<n;i++){
        cout << "enter array element:";
        cin >> arr[i];
    }

   int nums=count(arr,n,k);
   cout <<"Number of Occurence: "<< nums;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }

    return head;
}

int Searching(Node* head,int val){
    Node* temp=head;

    while(temp){
        if(temp->data==val){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr={2,3,4,5};
    
    Node* head=convertArr2LL(arr);
    cout<<Searching(head,10);

    // while(a){
    //     cout<<a->data;
    //     a=a->next;
    // }
    // return 0;
    
}
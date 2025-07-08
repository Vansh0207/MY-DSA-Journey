#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* back=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,back);
        back->next=temp;
        back=temp;
    }
    return head;

}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* middleBrute(Node* head){
    int cnt=0;
    Node* temp=head;

    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    int mid=cnt/2+1;
    temp=head;

    while(temp!=NULL){
        mid=mid-1;
        if(mid==0) break;
        temp=temp->next;
    }

    return temp;
}


//TORTOISE AND HARE ALGORITHM
Node* middleOptimal(Node* head){
    Node* fast=head;
    Node* slow=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

    }
    return slow;
}

int main(){
    vector<int> arr={2,3,1,4,5};
    Node* head=convertArr2LL(arr);
    //Node* mid=middleBrute(head);


    Node* mid=middleOptimal(head);

    cout<<mid->data;
    //print(head);
    return 0;
}
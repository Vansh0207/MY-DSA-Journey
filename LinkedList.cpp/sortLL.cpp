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

Node* convertArr2LL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* mover=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* findMiddle(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

Node* Merge(Node* list1,Node* list2){
    Node* newHead=new Node(-1);
    Node* mover=newHead;

    while(list1!=NULL && list2!=NULL){
        if(list1->data<=list2->data){
            mover->next=list1;
            list1=list1->next;
        }
        else{
            mover->next=list2;
            list2=list2->next;
        }
        mover=mover->next;
    }
    if(list1!=NULL) mover->next=list1;
    else mover->next=list2;

    return newHead->next;
}

Node* MergeSort(Node* head){
    if(head==NULL || head->next==NULL) return head;

    Node* middle=findMiddle(head);
    Node* left=head;
    Node* right=middle->next;
    middle->next=NULL;

    left=MergeSort(left);
    right=MergeSort(right);

    return Merge(left,right);
}

Node* NaiveApproach(Node* head){
    vector<int> arr;
    Node* temp=head;

    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }

    sort(arr.begin(),arr.end());

    temp=head;

    for(int i=0;i<arr.size();i++){
        temp->data=arr[i];
        temp=temp->next;
    }

    return head;


}

int main(){
    vector<int> arr={2,1,3,4,6};
    Node* head=convertArr2LL(arr);

    //head=MergeSort(head);

    head=NaiveApproach(head);

    print(head);

    return 0;
}
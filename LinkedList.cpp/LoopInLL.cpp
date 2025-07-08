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
    Node* head=new Node(arr[0]);
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

bool DetectLoopBruteForce(Node* head){
    map<Node*,int> mpp;
    Node* temp=head;

    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()) return true;

        mpp[temp]+=1;
        temp=temp->next;

    }
    return false;
}

bool DetectLoopOptimal(Node* head){
    //TORTOISE AND HARE ALGORITHM
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next==NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arr={2,1,3,4,5,6,7,8,4};
    Node* head=convertArr2LL(arr);

    if(DetectLoopOptimal(head)){
        cout<<"LOOP was Detected"<<endl;
    }
    else{
        cout<<"LOOP was not Detected"<<endl;
    }

    return 0;

    //print(head);
}
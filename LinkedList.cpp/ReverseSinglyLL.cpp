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

Node* reverseIterative(Node* head){
    Node* prev=NULL;
    Node* temp=head;
    
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* reverseStack(Node* head){
    Node* temp=head;

    stack<int> st;

    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;

    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
}

Node* reverseRecursive(Node* head){
    
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* newhead=reverseRecursive(head->next);

    Node* front=head->next;

    front->next=head;
    head->next=NULL;

    return newhead;
}

int main(){
    vector<int> arr={2,3,1,4};
    Node* head=convertArr2LL(arr);
    
    //head=reverseStack(head);
    //head=reverseIterative(head);

    head=reverseRecursive(head);
    print(head);
    return 0;
}
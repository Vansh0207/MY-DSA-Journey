#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
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

Node* reverseDLL(Node* head){
    stack<int> st;

    Node* temp=head;

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

Node* reverseDLL2(Node* head){

    if(head==NULL && head->next==NULL) return head;

    Node* back=NULL;
    Node* cur=head;

    while(cur!=NULL){
        back=cur->prev;
        cur->prev=cur->next;
        cur->next=back;

        cur=cur->prev;
    }

    return back->prev;
}


int main(){
    vector<int> arr={2,3,1,4};

    Node* head=convertArr2DLL(arr);

    head=reverseDLL2(head);

    print(head);

    return 0;
}
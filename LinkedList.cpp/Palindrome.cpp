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
        Node* temp= new Node(arr[i]);
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

bool ispalindromeBrute(Node* head){
    Node* temp=head;
    stack<int> st;

    while(temp!=NULL){                         
        st.push(temp->data);              //2->1->3->4->*5* <-top
        temp=temp->next;
    }
    temp=head;

    while(temp!=NULL){
        if(temp->data!=st.top()) return false;

        st.pop();
        temp=temp->next;
    }
    return true;
}

Node* reverseLL(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newhead=reverseLL(head->next);

    Node* front=head->next;
    front->next=head;
    head->next=NULL;

    return newhead;

}

bool ispalindromeOptimal(Node* head){

    if(head==NULL || head->next==NULL) return true;

    Node* slow=head;
    Node* fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* newhead=reverseLL(slow->next);

    Node* first=head;
    Node* second=newhead;

    while(second!=NULL){
        if(first->data!=second->data){

            reverseLL(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
    }

    reverseLL(newhead);
    return true;
}

int main(){
    vector<int> arr={2,1,3,3,1,2,1};

    Node* head=convertArr2LL(arr);

    if(ispalindromeOptimal(head)){
        cout<<"Is a Palindrome LL"<<endl;
    }
    else{
        cout<<"Is not Palindrome LL"<<endl;
    }
    //print(head);

    return 0;
}
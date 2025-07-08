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

Node* deleteHead(Node* head){
    Node* temp=head;

    if(head==NULL) return head;

    head=head->next;
    free(temp);

    return head;
}

Node* deleteTail(Node* head){                                 //[2,4,6,1]
    Node* temp=head;                                          

    if(head==NULL || head->next==NULL) return head;          //2->4->6 !=NULL  4->6->1 !=NULL   6->1->NULL == NULL

    while(temp->next->next != NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;

    return head;


    
}

Node* dltKthElement(Node* head,int k){                     //[2,4,6,1],3
    if(head==NULL) return head;

    if(k==1){                                            // if only one element delete and return head
        Node* temp=head;
        head=head->next;
        free(temp);

        return head;
    }

    Node* temp=head;                                    
    Node* prev=NULL;
    int cnt=0;
    while(temp!=NULL){                                  //2     4        6           
        cnt++;                                          //head  prev     temp

        if(cnt==k){                                   //cnt=1 cnt=2     cnt=3 condition true
            prev->next=prev->next->next;                //4->6=4->6->1   therefore 4->1
            free(temp);
            break;

        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* deleteSpecificValue(Node* head,int val){
    if(head==NULL) return head;

    if(head->data==val){       
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    Node* temp=head;
    Node*prev=NULL;
    int cnt=0;

    while(temp!=NULL){
        if(temp->data==val){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={2,4,6,1};
    Node* head=convertArr2LL(arr);

    //cout<<head->data;

    // head = deleteTail(head);

    // head=dltKthElement(head,3);

    head=deleteSpecificValue(head,4);

    while(head){
        cout<<head->data;
        head=head->next;
    }
    // head = deleteHead(head);
    // cout<< head->data;
    return 0;
}
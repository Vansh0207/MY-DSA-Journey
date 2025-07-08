#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;                      //5->NULL
        next=next1;                      //5->2
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

};

Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);                  // head 2->NULL
    Node* mover=head;

    for(int i=1;i<arr.size();i++){               //temp   4->NULL
        Node* temp=new Node(arr[i]);
        mover->next= temp;                           //2->4
        mover=temp;                                  //2  ->   4
                                                     //head    temp    
    }
    return head;
}

Node* insertionatHead(Node* head,int val){
    Node* temp=new Node(val,head);   
    return temp;
}

Node* insertionatTail(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newnode=new Node(val);
    temp->next=newnode;

    return head;
}

Node* insertionKthpos(Node* head,int val,int k){
    if(head==NULL){
          if(k==1){
            return new Node(val);
          }
          else return head;
    }
    if(k==1){
        Node* temp=new Node(val,head);

        return head;
    }
    int cnt=0;
    Node* temp=head;

    while(temp->next != NULL){
        cnt++;
        if(cnt==k-1){
            Node* cur=new Node(val);
            cur->next=temp->next;
            temp->next=cur;
            break;
        }
        temp=temp->next;
    }
    return head;

}

Node* insertionBefVal(Node* head,int val,int ele){
    if(head==NULL) return head;

    if(head->data==ele){
        Node* temp= new Node(val,head);
        return head;
    }

    Node* temp=head;

    while(temp->next!=NULL){
        if(temp->next->data==ele){
            Node* newnode=new Node(val);
            newnode->next = temp->next;
            temp->next=newnode;

            break;
        }
        temp=temp->next;
    }

    return head;

}

int main(){
    vector<int> arr={2,4,6,1};

    Node* head=convertArr2LL(arr);

    //head=insertionatTail(head,9);

    //head=insertionKthpos(head,10,3);
    
    head=insertionBefVal(head,20,6);


    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }

    return 0;
    
}
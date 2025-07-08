#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }

    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }

    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* deleteHead(Node* head){
    Node* temp=head;

    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    delete(temp);

    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL && head->next==NULL) return head;
                                                    //tail
    Node* tail=head;                                  //2 -> 3-> 4-> 1
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;                            //2->3->4(prev)->1(tail)

    prev->next=nullptr;
    tail->back=nullptr;

    delete(tail);

    return head;
}

Node* deleteKele(Node* head,int k){                   //k is the index
    Node* temp=head;
    int cnt=0;

    if(head==NULL) return head;

    while(temp!=NULL){
        cnt++;

        if(cnt==k){
            break;
        }
        temp=temp->next;
    }

    Node* prev=temp->back;
    Node* front=temp->next;

    if(prev==NULL && front==NULL){
        return NULL;
    }
    else if(prev==NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        return deleteTail(head);
    }

    //both prev and front are not NULL
    prev->next=front;
    front->back=prev;

    temp->back=nullptr;
    temp->next=nullptr;

    delete(temp);

    return head;
}

Node* deleteNode(Node* node){
    Node* prev=node->back;
    Node* front=node->next;

    prev->next=front;
    front->back=prev;

    node->back=nullptr;
    node->next=nullptr;

}

Node* insertionHead(Node* head,int val){
    Node* temp=new Node(val,head,nullptr);
    head->back=temp;

    return temp;
}

Node* insertionTail(Node* head,int val){

    if(head->next==NULL){
        return insertionHead(head,val);
    }
    Node* tail=head;

    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;

    Node* newNode=new Node(val,tail,prev);
    prev->next=newNode;
    tail->back=newNode;

    return head;
}

Node* insertbefindex(Node* head,int val,int k){
    if(k==1) return insertionHead(head,val);

    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;

        if(cnt==k) break;

        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);

    prev->next=newNode;
    temp->back=newNode;

    return head;
}

void insertBefNode(Node* node,int val){
    Node* prev=node->back;
    Node* newnode=new Node(val,node,prev);

    prev->next=newnode;
    node->back=newnode;

}

int main(){
    vector<int> arr={2,3,1,4};
    Node* head=convertArr2DLL(arr);
    //head=deleteHead(head);
    //head=deleteTail(head);
    //head=deleteKele(head,2);
    deleteNode(head->next);

    //head=insertionHead(head,100);
    //head=insertionTail(head,100);
    //head=insertbefindex(head,100,2);
    //insertBefNode(head->next->next,100);

    print(head);

    return 0;
}
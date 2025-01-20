#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    Node(int data){
        this->data = data;
        this->next=NULL;
        this->prev=NULL;
    }
};

void insertAtHead(Node* &head,int data){
    Node* newNode=new Node(data);
    newNode->next=head;
    if(head !=NULL){
     head->prev=newNode;   
    }
    head=newNode;
}

void insertAtTail(Node* &head,int data){
        
        if(head==NULL){
            insertAtHead(head,data);
            return;
        }
        Node* newNode=new Node(data);
        Node* temp=head;
        while (temp->next!= NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }

    void deleteAtHead(Node* &head){
        Node* todelete=head;
        head=head->next;
        head->prev=NULL;

        delete todelete;
    }
    void deletion(Node* head,int pos){
        if(pos==1){
            deleteAtHead(head);
            return;
        }

        Node* temp=head;
        int count=1;
        while(temp != NULL && count !=pos){
            temp=temp->next;
            count++;
        }
        temp->prev->next=temp->next;
        if(temp->next != NULL)
        temp->next=temp->prev;

        delete temp;
    }

    void display(Node* head){
        Node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        
    }
//gggggggggggggg

    int main(){
        Node* head=NULL;
        insertAtTail(head,1);
        insertAtTail(head,2);

        insertAtTail(head,3);
        insertAtTail(head,4);
        insertAtHead(head,0);

        display(head);
    }
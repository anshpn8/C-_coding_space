#include<iostream>
#include <vector> 
using namespace std;

    class Node
    {
    private:
        /* data 12345tyuio */
    public:  

        int data;
        Node* next;       
        Node(int data){
            this->data=data;
            next=NULL;
        };
        ~Node(){

        }
    };

    void insertAtHead(Node* &head,int data){
        Node* newNode=new Node(data);

        if(head==NULL){
            newNode->next=newNode;
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next != head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        head=newNode;
    }
    void insertAtTail(Node* &head,int data){
        if(head==NULL){
            insertAtHead(head,data);
            return;
        }
        Node* newNode=new Node(data);
        Node* temp=head;
        while(temp->next != head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;

    }

    void display(Node* &head){
        Node* temp=head;
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        } while(temp !=head);
        cout<<endl;
    }
    void deleteAtHead(Node* &head){
        Node* temp=head;
        while(temp->next != head){
            temp=temp->next;
        }

        Node* todelete=head;
        temp->next=head->next;
        head=head->next;

        delete todelete;
    }
    void deleteNode(Node* &head, int pos){
        if(pos==0){
            deleteAtHead(head);
            return;
        }
        Node* temp=head;
        int count=1;
        while (count!=pos-1)
        {
            temp=temp->next;
            count++;
        }
        Node* toDelete=temp->next;
        temp->next=temp->next->next;

        delete toDelete;
        
    }
    int main(){
        Node* head=NULL;
        insertAtTail(head,1);
        insertAtTail(head,2);
        insertAtTail(head,3);
        insertAtTail(head,4);
        insertAtTail(head,5);
        insertAtHead(head,6);
        display(head);
        // deleteNode(head,5);
        // display(head);
        deleteAtHead(head);
        display(head);
        return 0;
    }
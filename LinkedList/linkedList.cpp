#include<iostream>
using namespace std;

class LinkedList{
    class Node
    {
    private:
        /* data */
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
    
    void insertAtTail(Node* &head,int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            return;
        }
        Node* temp=head;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void display(Node* head){
        Node* temp=head;
        while (temp != NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
        
    }
    int main()
    {
        Node* head=new Node(1);
        display(head);

        return 0;
    }
    
};
#include<iostream>
using namespace std;


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

    void insertAtHead(Node* &head,int data){
        Node* newNode=new Node(data);

        if(head==NULL){
            head=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

    void display(Node* head){
        Node* temp=head;
        while (temp != NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        
    }

    void deletion(Node* &head,int value){
        Node* temp=head;
        if(head->data==value){
            Node* toDelete=head;
            head=head->next;
            delete toDelete;
            return;
        }
        while(temp->next->data != value){
            temp=temp->next;
        }
        Node* toDelete=temp->next;
        temp->next=temp->next->next;
        delete toDelete;
    }

        bool search(Node* head,int key){
            Node* temp=head;
            while(temp!=NULL){
                if(temp->data==key){
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }

        Node* reverse(Node* head){
            Node* prevptr=NULL;
            Node* currptr=head;
            Node* nextptr;
            while(currptr!=NULL){
                nextptr=currptr->next;
                currptr->next=prevptr;

                prevptr=currptr;
                currptr=nextptr;
            }
            return prevptr;
        }
    Node* reverseRecursive(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* newhead=reverseRecursive(head->next);
        head->next->next=head;
        head->next=NULL;

        return newhead;
    }
    int main()
    {
        Node* head=NULL;
        //insert the value
        insertAtTail(head,1);
        insertAtTail(head,2);
        insertAtTail(head,3);
        insertAtTail(head,4);
        insertAtHead(head,0);
        insertAtTail(head,5);
        insertAtTail(head,6);

        
        
        

        // to search 4
        if(search(head,4)){
            cout<<"Key is found."<<endl;
        }
        //delete the value from linked list
        deletion(head,0);
        
        //display the data of link list
        display(head=reverse(head));
        return 0;
    }
    
    
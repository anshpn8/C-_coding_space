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
    int main()
    {
        Node* head=NULL;
        insertAtTail(head,1);
        insertAtTail(head,2);
        insertAtTail(head,3);
        insertAtTail(head,4);
        insertAtHead(head,0);

        

        display(head);
        //cout<<"hi my name is pawan nishad.";
        

        if(search(head,4)){
            cout<<"Key is found."<<endl;
        }
        return 0;
    }
    
    
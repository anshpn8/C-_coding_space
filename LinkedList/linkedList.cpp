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

    Node* reverseK(Node* &head,int k){
        Node* prevptr=NULL;
        Node* currptr=head;
        Node* nextptr;

        int count=0;
        while(currptr != NULL && count<k){
            nextptr=currptr->next;
            currptr->next=prevptr;

            prevptr=currptr;
            currptr=nextptr;
            count++;
        }
        if(nextptr != NULL)
        head->next=reverseK(nextptr,k);

        return prevptr;
    }

    void createCycle(Node* &head,int pos){
        Node* temp=head;
        Node* startNode;
        int count=0;
        while(temp->next != NULL){
            if(count==pos){
                startNode=temp;
            }
            temp=temp->next;
            count++;
        }
        temp->next=startNode;
    }
    bool detectCycle(Node* &head){
        Node* slow=head;
        Node* fast=head;

        while(fast !=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
    //floyed algorithm
    void removeCyccle(Node* head){
        Node* slow=head;
        Node* fast=head;

        do{
            slow=slow->next;
            fast=fast->next->next;
        } while(slow !=fast);

        fast=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=NULL;
    }
    
    Node* mergeTowSortedList(Node* head1, Node* head2){
        
        Node* temp1=head1;
        Node* temp2=head2;
        Node* dummy=NULL;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data < temp2->data){
                insertAtTail(dummy,temp1->data);
                temp1=temp1->next;
            }
            else if(temp1->data > temp2->data){
                insertAtTail(dummy,temp1->data);
                temp2=temp2->next;
            }
            
        }
        while(temp1!=NULL){
            insertAtTail(dummy,temp1->data);
                temp1=temp1->next;
                
        }
        while(temp2!=NULL){
            insertAtTail(dummy,temp2->data);
                temp2=temp2->next;
                
        }
        return dummy->next;
    }

    int length(Node* head){
        Node* temp=head;
        int l;
        while(temp !=NULL){
            temp=temp->next;
            l++;
        }
        return l;
    }
    Node* appendKTail(Node* head,int k){
        int l=length(head);

        Node* temp=head;
        Node* newTail;
        Node* newHead;
        int count=1;
        k=k%l;
        while(temp->next !=NULL){
            if(count==l-k){
                newTail=temp;
            }
            if(count==l-k+1){
                newHead=temp;
            }
            temp=temp->next;
            count++;
        }
        newTail->next=NULL;
        temp->next=head;

        return newHead;    
    }

    void intersect(Node* &head1,Node* &head2,int pos){
        Node* temp1=head1;
        pos--;
        while(pos--){
            temp1=temp1->next;
        }
        
        Node* temp2=head2;
        while (temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp1;
    }

    int intersectionPoint(Node* &head1,Node* &head2){
        int l1=length(head1);
        int l2=length(head2);

        int d=0;
        Node* ptr1;
        Node* ptr2;
        if(l1>l2){
            d=l1-l2;
            ptr1=head1;
            ptr2=head2;
        }
        else{
            d=l2-l1;
            ptr1=head2;
            ptr2=head1;
        }
        while(d){
            ptr1=ptr1->next;
            if(ptr1==NULL){
                return -1;
            }
            d--;
        }
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1==ptr2){
                return ptr1->data;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return -1;
    }

    int main()
    {
        /*
        Node* head=NULL;
        //insert the value
        insertAtTail(head,1);
        insertAtTail(head,2);
        insertAtTail(head,3);
        insertAtTail(head,4);
        //insertAtHead(head,0);
        insertAtTail(head,5);
        insertAtTail(head,6);
        insertAtTail(head,7);

        createCycle(head,3);

        cout<<detectCycle(head);
        */


        // to search 4
        // if(search(head,4)){
        //     cout<<"Key is found."<<endl;
        // }
        //delete the value from linked list
            //deletion(head,0);
        
        //display the data of reversed link list
            //display(head=reverse(head));

        //display the data of k reversed link list; k=2
            // Node* new_head = reverseK(head,2);
            // display(new_head);
        Node* head1=NULL;
        Node* head2=NULL;
        int arr[7]={1,3,4,8,10,11,12};
        int arr2[3]={2,5,6};
        for(int i=0; i<7;i++){
            insertAtTail(head1,arr[i]);
        }
        for(int i=0; i<3;i++){
            insertAtTail(head2,arr2[i]);
        }
        // Node* head3=mergeTowSortedList(head1,head2);
        //display(appendKTail(head1,3))
        //intersect(head1,head2,5);
        display(head1);
        display(head2);
        cout<<intersectionPoint(head1,head2);


        return 0;
    }
#include<iostream>
#include <vector> 
using namespace std;


    class Node
    {
    private:
        /* datpppppppppppppppa */
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
        Node* dummy=new Node(-1);
        Node* p3=dummy;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data < temp2->data){
                p3->next=temp1;
                temp1=temp1->next;
            }
            else{
                p3->next=temp2;
                temp2=temp2->next;
            }
            p3=p3->next;   
        }
        while(temp1!=NULL){
            p3->next=temp1;
            temp1=temp1->next;
            p3=p3->next;   
        }
        while(temp2!=NULL){
            p3->next=temp2;
            temp2=temp2->next;
            p3=p3->next;    
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

    Node* mergeRecursion(Node* head1,Node* head2){
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        Node* result;
        if(head1->data<head2->data){
            result=head1;
            result->next=mergeRecursion(head1->next,head2);
        }
        else{
            result=head2;
            result->next=mergeRecursion(head1,head2->next);
        }
        return result;
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
    void deleteAllNodes(Node* &head) {
    while (head!= NULL) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
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
        vector<int> arr={1,3,5,7,10,11,12};
        vector<int> arr2={2,4,6,8};
        for(int i=0; i<arr.size();i++){
            insertAtTail(head1,arr[i]);
        }
        for(int i=0; i<arr2.size();i++){
            insertAtTail(head2,arr2[i]);
        }
        // Node* head3=mergeTowSortedList(head1,head2);
        //display(appendKTail(head1,3))
        //intersect(head1,head2,5);
        /*
        display(head1);
        display(head2);
        cout<<intersectionPoint(head1,head2);
        */
        display(head1);
        display(head2);
        Node* h1=mergeTowSortedList(head1,head2);
        display(h1);
        





        //display(mergeRecursion(head1,head2));
        


        return 0;
    }
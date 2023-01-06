#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    // constructor created 
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};

void print(Node* &head)
{
    Node* temp = head;
    
    while (temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next ;
    }
    cout<<endl;
    
}

void insertAtTail(Node* &tail , int d)
{
    //new node created at the head 
    Node* temp = new Node(d);
    tail->next = tail;
    
}

void insertAtHead(Node* &head , int d)
{
    //new node created at the head 
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

int main()
{

    //new node creation
    Node* node1 = new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    //head pointed to node 1 
    //head creation
    Node* head = node1;
    print(head);
    //tail creation
    Node* tail = node1;
    print(tail);


    insertAtHead(head , 12);
    print(head);




    return 0;
}
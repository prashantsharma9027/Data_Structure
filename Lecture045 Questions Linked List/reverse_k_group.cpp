#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

};

void print(Node* &head)
{
    Node* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAttail(Node* &tail , int d)
{ 
    Node* temp = new Node(d);
    tail->next = temp ;
    tail = temp; 
}

Node* kreverse(Node* &head , int k)
{
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
    int count = 0 ;

    while(curr!=NULL && count<k )
    {
        next = curr-> next;
        curr->next =  prev ;
        prev = curr;
        curr = next;
        count++;
    }

    if(next!=NULL)
    {
        head->next = kreverse(next , k);
    }

    return head = prev;
}

int main()
{
    Node* node1 = new Node(200);
    Node * head = node1;
    Node* tail = node1;

    insertAttail(tail, 300);
    insertAttail(tail, 400);
    insertAttail(tail, 500);
    insertAttail(tail, 600);
    insertAttail(tail, 700);

    print(head);


    cout<<"after k gorup reverse of linked list -> "<<endl;

    kreverse(head, 2);
    print(head);

    return 0;
}
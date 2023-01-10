#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* & head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insertAtTail(Node* &tail , int d)
{ 
    Node* temp = new Node(d);
    tail->next = temp ;
    tail = temp; 
}

int length(Node* &head)
{
    Node *temp=head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;

}

int middle(Node* &head)
{
    int ans = length(head)/2;
    int cnt = 0;

    Node* temp =head;

    while(cnt<ans)
    {
        temp = temp->next;
        cnt++;
    }
    return temp->data;

}

int fastslowmiddle(Node* &head)
{
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow = slow->next;
    return slow->data;
    }
}


int main()
{ 
    Node* node1 = new Node(20);
    Node * head = node1;

    //print(head);

    Node* tail = node1;

    insertAtTail(tail , 40);
    insertAtTail(tail , 60);
    insertAtTail(tail , 80);
    insertAtTail(tail , 100);
    insertAtTail(tail , 120);

    print(head);
    // print(head);


    // Node* prev = NULL;
    // Node* curr = head;

    cout<<"The No. of elements in a linked list "<<length(head);
    cout<<endl;
    
    cout<<"The midddle element is " << middle(head);

    cout<<endl;

    cout<<"The middle element is 2nd way "<< fastslowmiddle(head);
    
    return 0;
}
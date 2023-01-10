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
    Node * temp = new Node(d);

    tail->next = temp;
    temp = tail;

}

void reverse1(Node* &head){
    
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr!=NULL)
    {
        forward = curr->next;
        curr->next=prev;
        prev= curr;
        curr= forward;
    }
    head = prev;
}


void recursion_1(Node* &head , Node* &curr , Node* &prev){
    // Recursion 1
    if(curr==NULL)
    {
        head = prev;
        return;
    }

    Node* forward = curr->next;
    recursion_1(head , forward , curr);
    curr->next=prev;
}

void reverse2(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    recursion_1(head,curr,prev);
}




// void  recursion_2(Node* &head)
// {
//     if(head==NULL || head->next==NULL)
//     {
//         head = head;
//         return;
//     }

//     Node* chotahead = recursion_2(head->next);

//     head->next->next=head;
//     head->next=NULL;

//     // return chotahead;

// }

// void reverse3(Node* head)
// {
//     recursion_2(head);
// }


int main()
{
    Node* node1 = new Node(200);

    Node* head = node1;

    Node* tail = node1;

    insertAttail(tail , 400);
    print(head);

    cout<<"reverse linked list "<<endl;

    // reverse1(head);
    // print(head);

    // reverse2(head);
    // print(head);

    reverse2(head);
    print(head);
    

    return 0;
}
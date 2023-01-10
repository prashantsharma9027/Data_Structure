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

int main()
{

    return 0;
}
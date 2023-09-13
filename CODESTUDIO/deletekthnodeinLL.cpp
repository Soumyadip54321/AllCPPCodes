#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* removeKthNode(Node* head, int K);
void displayLL(Node*);

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=nullptr;
    // head->next->next->next->next=new Node(5);
    // head->next->next->next->next->next=new Node(6);
    // head->next->next->next->next->next->next=nullptr;

    displayLL(head);
    head=removeKthNode(head,3);
    displayLL(head);
    return 0;
}
Node* removeKthNode(Node* head, int K){
    int LLlength=0;
    Node* curr=head,*prev=nullptr;

    while (curr)
    {
        LLlength++;
        curr=curr->next;
    }
    
    if(K==LLlength){
        return head->next;
    }

    curr=head;
    while (LLlength!=K)
    {
        prev=curr;
        curr=curr->next;
        LLlength--;
    }

    prev->next=curr->next;
    return head;
}
void displayLL(Node* head){
    Node* curr=head;

    while (curr)
    {
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<endl;
}
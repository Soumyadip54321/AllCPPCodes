#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            
            this->data = data;
            this->next = NULL;
        }
    };
Node *getListAfterAddingNodes(Node *head, int k);
void displayLL(Node*);

int main(){
    Node* newhead=nullptr;
    Node* head=new Node(0);
    // head->next=new Node(6);
    // head->next->next=new Node(1);
    // head->next->next->next=new Node(5);
    // head->next->next->next->next=new Node(-1);
    // head->next->next->next->next->next=new Node(6);
    // head->next->next->next->next->next->next=new Node(7);


    newhead=getListAfterAddingNodes(head,1);
    displayLL(newhead);
    return 0;
}
Node *getListAfterAddingNodes(Node *head, int k){
    Node* curr=head,*prev=nullptr;
    int times=k;

    if(curr==nullptr)
        return head;

    while (true)
    {
        int val=0;
       while (curr and times)
       {
            prev=curr;
            val+=curr->data;
            curr=curr->next;
            times--;
       }
        //cout<<val<<endl;
        Node* newnode=new Node(val);
        prev->next=newnode;

        if(curr==nullptr)
            break;
        newnode->next=curr;
        times=k;
    }
    return head;
}

void displayLL(Node* h){
    Node* c=h;
    while (c)
    {
        cout<<c->data<<"->";
        c=c->next;
    }
}
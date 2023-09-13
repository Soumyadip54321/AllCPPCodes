#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

    class LinkedListNode
    {
    public:
        int data;
        LinkedListNode *next;
        LinkedListNode(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
void deleteNode(LinkedListNode * node);
void displayLL(LinkedListNode*);

int main(){
    LinkedListNode* head=new LinkedListNode(-8);
    head->next=new LinkedListNode(3);
    head->next->next=new LinkedListNode(4);
    head->next->next->next=new LinkedListNode(-2);
    head->next->next->next->next=new LinkedListNode(1);

    deleteNode(head->next->next);
    displayLL(head);
    return 0;
}
void deleteNode(LinkedListNode * node){
    /*
    idea:
    1. since all values are unique
    */
   LinkedListNode* currptr=node,*nextptr=node->next,*prev=nullptr;

   while (nextptr)
   {
        currptr->data=nextptr->data;
        prev=currptr;
        currptr=nextptr;
        nextptr=currptr->next;
   }
   
   prev->next=nullptr;
}
void displayLL(LinkedListNode* head){
    LinkedListNode* curr=head;

    while (curr)
    {
        cout<<curr->data<<"->";
        curr=curr->next;
    }
}
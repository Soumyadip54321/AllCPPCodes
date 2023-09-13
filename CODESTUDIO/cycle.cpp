#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
	    this->data = data;
	    this->next = NULL;
	}
};
bool detectCycle(Node *head);
void removecycle(Node*);
unordered_map<Node*,bool> visited;

int main(){
    Node* head=new Node(3);
    head->next=new Node(2);
    head->next->next=new Node(0);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=head->next;
    cout<<detectCycle(head)<<endl;
    removecycle(head);
    return 0;
}
bool detectCycle(Node *head){
   //here we use hare and tortoise algorithm
   Node* slow=head,*fast=head,*current=head;

   while (fast && fast->next)
   {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
            return true;
   }
   return false;
}
void removecycle(Node* head){
    //here we assume that we have a cycle already present in LL
    Node* slow,*fast;
    slow=fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);

    fast=head;

    while (fast->next!=slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=nullptr;
}
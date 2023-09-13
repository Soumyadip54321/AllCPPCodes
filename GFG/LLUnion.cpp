#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
void display(Node*);
Node* makeUnion(struct Node* head1, struct Node* head2);
Node* createLL(int,Node*);

int main(){
    Node* unionhead;
    Node* head1=new Node(4);
    head1->next=new Node(5);
    head1->next->next=new Node(6);
    head1->next->next->next=new Node(7);
    head1->next->next->next->next=new Node(1);
    //head1->next->next->next->next->next=nullptr;

    Node* head2=new Node(1);
    head2->next=new Node(5);
    head2->next->next=new Node(1);
    head2->next->next->next=new Node(2);
    head2->next->next->next->next=new Node(2);
    head2->next->next->next->next->next=new Node(5);

    //display(head1);
    unionhead=makeUnion(head1,head2);
    display(unionhead);
    return 0;
}
void display(Node* head){
    Node* curr=head;
    while (curr)
    {
       cout<<curr->data<<"->";
       curr=curr->next;
    }
}
Node* makeUnion(struct Node* head1, struct Node* head2){
    set<int> uniqueentries;
    int LL1length=0,LL2length=0,largest;

    Node* c1=head1,*c2=head2,*uh=nullptr;

    //compute length of LLs
    while (c1 && c2)
    {
        uniqueentries.insert(c1->data);
        uniqueentries.insert(c2->data);
        c1=c1->next;
        c2=c2->next;
    }

    if(c1){
        while (c1)
        {
            uniqueentries.insert(c1->data);
            c1=c1->next;
        }
    }

    if(c2){
        while (c2)
        {
            uniqueentries.insert(c2->data);
            c2=c2->next;
        }
    }
    for(auto item:uniqueentries){
        uh=createLL(item,uh);
    }
    return uh;
}
Node* createLL(int val,Node* h){
    if(h==nullptr){
        h=new Node(val);
    }
    else{
        h->next=createLL(val,h->next);
    }
    return h;
}

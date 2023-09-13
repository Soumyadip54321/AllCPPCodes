#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class node
{
	public:
	int data;
    node * next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};
node *findKthFromLast(node *head, int k);

int main(){
    node* nodetobedeleted=nullptr;
    node* head=new node(2);
    head->next=new node(26);
    head->next->next=new node(35);
    head->next->next->next=new node(5);
    //head->next->next->next->next=new node(11);

    cout<<findKthFromLast(head,1)->data<<endl;
    return 0;
}
node *findKthFromLast(node *head, int k){
    node* curr=head;
    int len=0;

    while (curr)
    {
        len++;
        curr=curr->next;
    }
    curr=head;

    while (len>k)
    {
        curr=curr->next;
        len--;
    }
    return curr;
}
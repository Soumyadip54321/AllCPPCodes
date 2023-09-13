#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int values[3010];
int swappedval[3010];

class DLLNode {
    public:
	int data;
	DLLNode *next;
    DLLNode *prev;

	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};
DLLNode* rotateDLL(DLLNode* head, int k);
DLLNode* createDLL(DLLNode*,DLLNode*,int*,int);

int main(){
    DLLNode *head=new DLLNode(4);
    head->prev=nullptr;
    head->next=new DLLNode(3);

    head->next->prev=head;
    head->next->next=new DLLNode(9);

    head->next->next->prev=head->next;
    head->next->next->next=new DLLNode(1);

    head->next->next->next->prev=head->next->next;
    head->next->next->next->next=new DLLNode(7);

    head->next->next->next->next->prev=head->next->next->next;
    head->next->next->next->next->next=new DLLNode(8);

    head->next->next->next->next->next->prev=head->next->next->next->next;
    head->next->next->next->next->next->next=nullptr;


    head=rotateDLL(head,4);
    return 0;
}
DLLNode* rotateDLL(DLLNode* head, int k){
    /*
    idea:
    1. we simply shift the values by k in every node
    2. return head
    */
   DLLNode* curr=head;
   int i=0,length=0;

   while (curr)
   {
        length++;
        values[i]=curr->data;
        curr=curr->next;
        i++;
   }
    //we shift values in array by k
    for(int i=0;i<length;i++){
        if(i-k>=0){
            swappedval[i-k]=values[i];
        }
        else{
            swappedval[i-k+length]=values[i];
        }
    }
    DLLNode* h=nullptr;
    DLLNode* prev=nullptr;

    for(int idx=0;idx<length;idx++)
        h=createDLL(h,prev,swappedval,idx);
    // curr=h;
    // while (curr)
    // {
    //     cout<<curr->data<<"->";
    //     curr=curr->next;
    // }
    for(int i=0;i<3010;i++)
		swappedval[i]=values[i]=0;
    return h;
}
DLLNode* createDLL(DLLNode* head,DLLNode* p,int* swapval,int idx){
    if(head==nullptr){
        head=new DLLNode(swapval[idx]);
        head->prev=p;
        return head;
    }
    head->next=createDLL(head->next,head,swapval,idx);
    return head;
}
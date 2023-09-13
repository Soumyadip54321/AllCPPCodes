#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* partition(ListNode* head, int x);
ListNode* createLL(int,ListNode*);
void displayLL(ListNode*);

int main(){
    ListNode* nh=nullptr;
    ListNode* h=new ListNode(2);
    h->next=new ListNode(1);
    // h->next->next=new ListNode(3);
    // h->next->next->next=new ListNode(2);
    // h->next->next->next->next=new ListNode(5);
    // h->next->next->next->next->next=new ListNode(2);

    nh=partition(h,2);
    displayLL(nh);
    return 0;
}
ListNode* partition(ListNode* head, int x){
    /*
    idea:
    1. we maintain a vector<listnode*> v such that it has nodes in order with values < x  at the front with values >=x 
        in order from where  val<x ends.
    */
   vector<int> v;
   ListNode* cp=head,*nh=nullptr;

   while (cp)
   {
        if(cp->val<x)
            v.push_back(cp->val);
        cp=cp->next;
   }
   cp=head;
   while (cp)
   {
        if(cp->val>=x)
            v.push_back(cp->val);
        cp=cp->next;
   }
   //CREATE LL
    for(auto val:v)
        nh=createLL(val,nh);
    return nh;
}
ListNode* createLL(int val,ListNode* node){
    if(node==nullptr){
        node=new ListNode(val);
    }
    else{
        node->next=createLL(val,node->next);
    }
    return node;
}
void displayLL(ListNode* h){
    ListNode* cp=h;
    while (cp)
    {
        cout<<cp->val<<"->";
        cp=cp->next;
    }
}
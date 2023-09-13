#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;
struct node *reverse (struct node *head, int k);
void displayLL(node*);

int main(){
    // cout<<"hi"<<endl;
    head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    head->next->next->next->next=new node(5);
    // head->next->next->next->next->next=new node(6);
    // head->next->next->next->next->next->next=new node(7);
    // head->next->next->next->next->next->next->next=new node(8);

    // cout<<"hi"<<endl;
    head=reverse(head,3);
    displayLL(head);
    return 0;
}
struct node *reverse (struct node *head, int k){
    node* current=head,*prev=nullptr,*after=nullptr;
    int times=k;

    while (times!=0 && current!=nullptr)
    {
        after=current->next;
        current->next=prev;
        prev=current;
        current=after;
        times--;
    }
    if(current){
        head->next=reverse(current,k);
    }
    return prev;
}
void displayLL(node* head){
    node* current=head;

    while (current)
    {
        cout<<current->data<<"->";
        current=current->next;
    }
}
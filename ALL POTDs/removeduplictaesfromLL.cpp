#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1e5+10;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
Node * removeDuplicates( Node *head);
void displayLL(Node*);



int main(){
    Node* newh=nullptr;
    Node* head=new Node(5);
    head->next=new Node(2);
    head->next->next=new Node(7);
    head->next->next->next=new Node(6);
    head->next->next->next->next=new Node(2);
    head->next->next->next->next->next=new Node(1);
    head->next->next->next->next->next->next=new Node(1);
    head->next->next->next->next->next->next->next=new Node(2);
    head->next->next->next->next->next->next->next->next=new Node(7);

    newh=removeDuplicates(head);
    displayLL(newh);
    return 0;
}
Node * removeDuplicates( Node *head){
    vector<int> visited(N,0);
    Node* newhead=head;
    Node* current=newhead,*prev=nullptr;

    while (current)
    {
        if(visited[current->data]==1){
            prev->next=current->next;
            current=prev->next;
        }
        else{
            visited[current->data]++;
            prev=current;
            current=current->next;
        }
    }
    return newhead;
}
void displayLL(Node* nh){
    Node* curr=nh;

    while (curr)
    {
        cout<<curr->data<<"->";
        curr=curr->next;
    }
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
 public:
      int data;
      Node *prev;
      Node *next;
      Node() {
          this->data = 0;
          this->prev = NULL;
          this->next = NULL;
      }
      Node(int data) {
          this->data = data;
          this->prev = NULL;
          this->next = NULL;
      }
      Node (int data, Node *next, Node *prev) {
          this->data = data;
          this->prev = prev;
          this->next = next;
      }
 };

Node* removeDuplicates(Node *head);
void display(Node*);

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(2);
    head->next->prev=head;
    head->next->next->next=new Node(2);
    head->next->next->prev=head->next;
    // head->next->next->next->next=new Node(3);
    head->next->next->next->prev=head->next->next;

    head=removeDuplicates(head);
    display(head);
    return 0;
}
Node* removeDuplicates(Node *head){
    Node* curr=head,*after=curr->next;

    while (after)
    {
        if(after->data==curr->data){
            curr->next=after->next;

            if(curr->next==nullptr)
                break;

            after->next->prev=curr;
            after=curr->next;
        }
        else{
            curr=after;
            after=curr->next;
        }
    }
    return head;
}
void display(Node* head){
    Node* current=head;

    while (current)
    {
        cout<<current->data<<"->";
        current=current->next;
    }
}
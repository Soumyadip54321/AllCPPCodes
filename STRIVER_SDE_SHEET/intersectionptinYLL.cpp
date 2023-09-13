#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int intersectPoint(Node* head1, Node* head2);

int main(){
    Node *head1=new Node(3);
    head1->next=new Node(6);
    head1->next->next=new Node(9);
    head1->next->next->next=new Node(15);
    head1->next->next->next->next=new Node(30);

    Node *head2=new Node(10);
    head2->next=new Node(15);
    head2->next->next=new Node(30);

    cout<<intersectPoint(head1,head2);
    return 0;
}
int intersectPoint(Node* head1, Node* head2){
    
}
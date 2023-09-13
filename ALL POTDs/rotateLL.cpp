#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

void displayLL(Node*);
Node *rotate(Node *head, int k);
int main(){
    Node *rotatedllhead=nullptr;
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    // head->next->next->next->next=new Node(5);
    // head->next->next->next->next->next=new Node(6);
    
    rotatedllhead=rotate(head,0);
    displayLL(rotatedllhead);
    return 0;
}
Node *rotate(Node *head, int k){
   Node* curr=head;
     int lengthofLL=0,i=0;
     
     while(curr){
          lengthofLL++;
          curr=curr->next;
     }
     //cout<<lengthofLL<<endl;
     vector<int> nodevals(lengthofLL,0);
     curr=head;

     while(curr){
          nodevals[(i+k)%lengthofLL]=curr->data;
          curr=curr->next;
          i++;
     }
     curr=head;
     for(i=0;i<lengthofLL;i++){
        curr->data=nodevals[i];
        curr=curr->next;
     }
     return head;
}
void displayLL(Node* h){
    Node* curr=h;
    while (curr)
    {
        cout<<curr->data<<"->";
        curr=curr->next;
    }
}
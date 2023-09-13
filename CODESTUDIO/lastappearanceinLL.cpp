#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

const int n=1e6+5;
bool visited[n];

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

Node *lastAppearance(Node *head);
void displayLL(Node*);

int main(){
    Node* h=new Node(7);
    h->next=new Node(11);
    h->next->next=new Node(3);
    h->next->next->next=new Node(13);
    h->next->next->next->next=new Node(23);
    h->next->next->next->next->next=new Node(7);
    h->next->next->next->next->next->next=new Node(11);
    h->next->next->next->next->next->next->next=new Node(13);

    h=lastAppearance(h);
    return 0;
}
Node *lastAppearance(Node *head){
    /*
    idea:
    1. here we use stack to put elements into
    2. each time we keep a count of entry
    3. Then we create a LL poping elemnts from top of stack until we empty it out
    4. But we make nodes only when we come across element unvisited earlier
    */
   stack<int> s;
   Node* current=head,*prev=nullptr;

   while (current)
   {
        s.push(current->data);
        current=current->next;
   }

   //we create a LL here of only the last appearance of elements
   while (not(s.empty()))
   {
        int value=s.top();

        if(visited[value]==false){
            Node* node=new Node(value);
            node->next=prev;
            prev=node;
            visited[value]=true;
        }
        s.pop();
   }
   displayLL(prev);
   return prev;
}
void displayLL(Node* head){
    Node* c=head;

    while (c)
    {
        cout<<c->data<<"->";
        c=c->next;
    }
}
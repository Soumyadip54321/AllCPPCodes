#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
Node *firstNode(Node *head);

int main(){
    Node* cyclestart;
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);

    cyclestart=firstNode(head);
    return 0;
}
Node *firstNode(Node *head){
    Node* f=head,*s=f->next;
    unordered_map<Node*,int> m;

    if(f==nullptr || s==nullptr)
        return false;

    m[f]=1;
    m[s]=1;

    do
    {
        f=s;
        s=f->next;

        if(s==nullptr)
            break;
            
        if(m[f] && m[s])
            return s;
        else
            m[s]=1;
    }while (s);
    return nullptr;
}
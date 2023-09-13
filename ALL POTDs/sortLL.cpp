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

Node* segregate(Node *head);
// Node* formLL(Node*,int);
void displayLL(Node*);

int main(){
    Node* nh=nullptr;
    Node* head=new Node(2);
    head->next=new Node(2);
    head->next->next=new Node(0);
    head->next->next->next=new Node(1);
    // head->next->next->next->next=new Node(2);
    // head->next->next->next->next->next=new Node(2);
    // head->next->next->next->next->next->next=new Node(2);
    // head->next->next->next->next->next->next->next=new Node(0); 

    nh=segregate(head);
    displayLL(nh);
    return 0;   
}
Node* segregate(Node *head){
    vector<int> itemssorted;
    Node* curr=head;
    Node* newhead=nullptr;

    while (curr)
    {
        itemssorted.push_back(curr->data);
        curr=curr->next;
    }
    
    int i=0,j=itemssorted.size()-1;
    while (i<j)
    {
        if(itemssorted[i]>0 && itemssorted[j]==0){
            swap(itemssorted[i],itemssorted[j]);
            i++;
            j--;
        }
        else if(itemssorted[i]>0 && itemssorted[j]>0){
            j--;
        }
        else if(itemssorted[i]==0 && itemssorted[j]==0){
            i++;
        }
        else{
            i++;
            j--;
        }
    }
    i=0;
    for(i=0;i<itemssorted.size();i++){
        if(itemssorted[i]!=0){
            break;
        }
    }

    j=itemssorted.size()-1;
    while (i<j)
    {
        if(itemssorted[i]==2 && itemssorted[j]==1){
            swap(itemssorted[i],itemssorted[j]);
            i++;
            j--;
        }
        else if(itemssorted[i]==2 && itemssorted[j]==2){
            j--;
        }
        else if(itemssorted[i]==1 && itemssorted[j]==1){
            i++;
        }
        else{
            i++;
            j--;
        }
    }

    curr=head;
    
    for(i=0;i<itemssorted.size();i++){
        curr->data=itemssorted[i];
        curr=curr->next;
    }
    newhead=head;
    return newhead;
}
// Node* formLL(Node* h,int num){
//     if(h==nullptr)
//         h=new Node(num);
//     else
//         h->next=formLL(h->next,num);
//     return h;
// }
void displayLL(Node* h){
    Node* c=h;
    while (c)
    {
        cout<<c->data<<"->";
        c=c->next;
    }
}
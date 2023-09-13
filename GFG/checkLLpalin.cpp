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
bool isPalindrome(Node *head);

int main(){
    Node* head1=new Node(1);
    head1->next=new Node(2);
    head1->next->next=new Node(1);
    //head1->next->next->next=new Node(4);
    //head1->next->next->next->next=new Node(1);

    cout<<isPalindrome(head1);
    return 0;
}
bool isPalindrome(Node *head){
    string str;
    Node* curr=head;

    while (curr)
    {
        str+=curr->data+'0';
        curr=curr->next;
    }
    //cout<<str<<endl;
    int n=str.length(),i=0;
    while (i<(n/2))
    {
        if(not(str[i]==str[n-i-1]))
            return false;
        i++;
    }
    return true;
}
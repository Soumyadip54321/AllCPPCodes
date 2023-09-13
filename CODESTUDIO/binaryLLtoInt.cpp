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
    Node(int val) {
        this->data = val;
        next = NULL;
    }
    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};
int binaryToInteger(int n, Node *head);

int main(){
    Node* head=new Node(1);
    head->next=new Node(0);
    head->next->next=new Node(0);
    //head->next->next->next=new Node(0);

    cout<<binaryToInteger(3,head);
    return 0;
}
int binaryToInteger(int n, Node *head){
    string num="";
    int result=0;
    Node* curr=head;

    while (n)
    {
        num+=curr->data+'0';
        curr=curr->next;
        n--;
    }
    cout<<num<<endl;

    for(int i=0;i<num.length();i++){
        result+=(num[i]-'0')*(1<<(num.length()-i-1));
    }
    return result;
}
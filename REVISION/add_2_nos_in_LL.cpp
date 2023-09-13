#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
struct Node* addTwoLists(struct Node* first, struct Node* second);
string add2numbers(string,string);
void displayLL(Node*);

int main(){
    Node* newhead=nullptr;
    Node* head1=new Node(3);
    head1->next=new Node(4);
    head1->next->next=new Node(5);
    //head1->next->next->next=new Node(9);

    Node* head2=new Node(4);
    head2->next=new Node(5);
    // head2->next->next=new Node(9);
    // head2->next->next->next=new Node(9);

    newhead=addTwoLists(head1,head2);
    displayLL(newhead);
    return 0;
}
struct Node* addTwoLists(struct Node* first, struct Node* second){
    /*
    idea:
    1.  we first take both of the numbers in a string
    2.  next we call our helper function to add the 2 strings and return it
    3.  next we create a LL with values from the ans
    */
    Node* cp1=first,*cp2=second;
    int l1=0,l2=0;
    string s1,s2,ans;

    //we compute length so to just add a node to the end of the largest LL,put the ans in it and return it's head
    while (cp1)
    {
        l1++;
        cp1=cp1->next;
    }
    while (cp2)
    {
        l2++;
        cp2=cp2->next;
    }
    
    cp1=first;
    cp2=second;
    while (cp1)
    {
        s1+=cp1->data+'0';
        cp1=cp1->next;
    }
    while (cp2)
    {
        s2+=cp2->data+'0';
        cp2=cp2->next;
    }
    ans=add2numbers(s1,s2);
    cout<<ans<<endl;

    Node* ans_head=nullptr;
    if(l1>l2)
        ans_head=first;
    else
        ans_head=second;
    
    //CREATE LL
    Node* cp=ans_head,*prev=nullptr;
    int i=0;
    
    while (cp)
    {
        cp->data=ans[i]-'0';
        prev=cp;
        cp=cp->next;
        i++;
    }
    if(not(i==ans.length()))
        prev->next=new Node(ans[i]);
    return ans_head;
}
string add2numbers(string s1,string s2){
    if(s1.length()<s2.length())
        swap(s1,s2);
    //we keep s1 as the largest
    int n1=s1.length();
    int n2=s2.length();

    string ans;
    int carry=0;
    int diff=n1-n2;

    for(int i=n2-1;i>=0;i--){
        int sum=(s2[i]-'0')+(s1[i+diff]-'0')+carry;
        ans+=(sum%10)+'0';
        carry=sum/10;
    }

    for(int i=n1-n2-1;i>=0;i--){
        int sum=(s1[i]-'0')+carry;
        ans+=(sum%10)+'0';
        carry=sum/10;
    }
    if(carry)
        ans+=carry+'0';

    reverse(ans.begin(),ans.end());
    return ans;
}
void displayLL(Node* h){
    Node* cp=h;
    while (cp)
    {
        cout<<cp->data<<"->";
        cp=cp->next;
    }
}

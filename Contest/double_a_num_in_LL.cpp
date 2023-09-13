#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 ListNode* doubleIt(ListNode* head);
string add2numbers(string,string);
void displayLL(ListNode*);

int main(){
    ListNode* nh=nullptr;
    ListNode* h=new ListNode(7);
    h->next=new ListNode(6);
    h->next->next=new ListNode(3);

    nh=doubleIt(h);
    displayLL(nh);
    return 0;
}
ListNode* doubleIt(ListNode* head){
    //doubling can be thought of as addition
    ListNode* cp1=head,*new_head=head;
    string s1,s2,ans;

    while (cp1)
    {
        s1+=cp1->val+'0';
        cp1=cp1->next;
    }
    s2=s1;
    ans=add2numbers(s1,s2);
    //cout<<ans<<endl;

    //CREATE LL
    ListNode* cp=new_head,*prev=nullptr;
    int i=0;
    
    while (cp)
    {
        cp->val=ans[i]-'0';
        prev=cp;
        cp=cp->next;
        i++;
    }
    if(not(i==ans.length()))
        prev->next=new ListNode(ans[i]-'0');
    return new_head;
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
void displayLL(ListNode* h){
    ListNode* cp=h;
    while (cp)
    {
        cout<<cp->val<<"->";
        cp=cp->next;
    }
}
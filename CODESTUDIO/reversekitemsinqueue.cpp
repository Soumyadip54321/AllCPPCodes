#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
queue<int> reverseElements(queue<int> q, int k);

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
Node* addFirstAndReversedSecondHalf(Node* head);
string sumnumsasstrings(string,string);
Node* createlinkedlist(char,Node*);

int main(){
    queue<int> q,revq;
    Node* head1;
    Node* head=new Node(0);
    head->next=new Node(0);
    head->next->next=new Node(0);
    head->next->next->next=new Node(0);
    head->next->next->next->next=new Node(1);
    head->next->next->next->next->next=new Node(0);
    //head->next->next->next->next->next->next=new Node(6);
    // head->next->next->next->next->next->next->next=new Node(0);
    // head->next->next->next->next->next->next->next->next=new Node(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    //q.push(6);
    //revq=reverseElements(q,4);
    head1=addFirstAndReversedSecondHalf(head);
    return 0;
}
queue<int> reverseElements(queue<int> q, int k){
    vector<int> s;
    int leftele;
    leftele=q.size()-k;
    while (k)
    {
        s.push_back(q.front());
        q.pop();
        k--;
    }
    for(int i=s.size()-1;i>=0;i--){
        q.push(s[i]);
    }
    s.clear();
    while (leftele)
    {
        s.push_back(q.front());
        q.pop();
        leftele--;
    }
    for(int i=0;i<s.size();i++){
        q.push(s[i]);
    }
    return q;
}
Node* addFirstAndReversedSecondHalf(Node* head){
    /*
    idea:
    1. we store the front and reverse of back part in 2 seperate vectors
    2. we add numbers
    3. create a linked list with node values as the digits and return its head
    */
   //first we find length
   Node* curr=head;
   int listlen=0;
   string firstnum="",secondnum="";

   while (curr)
   {
        listlen++;
        curr=curr->next;
   }

   int firstpartct=listlen/2;
   if(listlen%2>0)
    firstpartct=(listlen/2)+1;
   curr=head;

   while (firstpartct)
   {
        firstnum+=to_string(curr->data);
        curr=curr->next;
        firstpartct--;
   }
    int idx=0;
   while (curr)
   {
        secondnum+=to_string(curr->data);
        curr=curr->next;
        idx++;
   }
    reverse(secondnum.begin(),secondnum.end());
    // cout<<firstnum<<","<<secondnum<<endl;
    string num=sumnumsasstrings(firstnum,secondnum);

    /*here we trim any leading zeros present in num*/
    while (num[0]-'0'==0 && num.length()>1)
        num.erase(num.begin());
    // cout<<num<<endl;

    //now we form a linked list with node values as letters of num
    Node* h=nullptr;
    for(int i=0;i<num.length();i++)
        h=createlinkedlist(num[i],h);
    
    Node* c=h;
    while (c)
    {
        cout<<c->data<<",";
        c=c->next;
    }
    return h;
}
string sumnumsasstrings(string str1,string str2){
    if(str1.length()>str2.length())         //ensures str2 is larger
        swap(str1,str2);
    
    string ans="";

    //we reverse strings here
    // reverse(str1.begin(),str1.end());
    // reverse(str2.begin(),str2.end());

    int carry=0,diff=str2.length()-str1.length();

    //here we add digits till length of smaller number
    for(int i=str1.length()-1;i>=0;i--){
        int sum=((str1[i]-'0')+(str2[i+diff]-'0')+carry);
        ans+=(sum%10+'0');
        carry=sum/10;
    }

    //we add digits for larger number
    for(int i=str2.length()-str1.length()-1;i>=0;i--){
        int sum=(str2[i]-'0')+carry;
        ans+=(sum%10+'0');
        carry=sum/10;
    }
    //we check if there exists any carry
    if(carry){
        ans+=carry+'0';
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
Node* createlinkedlist(char ch,Node* head){
    if(head==nullptr){
        head=new Node(ch-'0');
        return head;
    }
    head->next=createlinkedlist(ch,head->next);
    return head;
}
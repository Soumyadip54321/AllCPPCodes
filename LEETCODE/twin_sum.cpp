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
const int N=1e5+10;
int nodeval[N];

int pairSum(ListNode* head);

ListNode *head=nullptr;

int main(){
    cout<<pairSum(head)<<endl;
    return 0;
}
int pairSum(ListNode* head){
    /*here number of nodes is even*/
    int maxtwinsum=-1,length=0,i=0;
    ListNode *current=head;
    while (current!=nullptr)
    {
       nodeval[i]=current->val;
       length++;
       current=current->next;
       i++;
    }
    /*second approach - array*/
    int start=0,end=length-1;
    while (start<end)
    {
        maxtwinsum=max(maxtwinsum,nodeval[start]+nodeval[end]);
        start++;
        end--;
    }
    return maxtwinsum;
}

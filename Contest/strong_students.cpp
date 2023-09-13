#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int diffSum(int n,int m,int arr[]);
int mySqrt(int x);
ListNode* swapNodes(ListNode* head, int k);
double myPow(double x, int n);

double eps=1e-7;
const int num=1e9+10;
int BitSetTable[num];


int main(){
    int arr[]={5,8,11,40,15};
    int n=5,m=2;
    long long N=4;
    double x=2.00000;
    cout<<diffSum(n,m,arr)<<endl;
    //cout<<mySqrt(2147395599)<<endl;
    // cout<<myPow(x,10)<<endl;
    //cout<<countBits(N)<<endl;
    return 0;
}
int diffSum(int n,int m,int arr[]){
    int maxsum=0,minsum=0;
    sort(arr,arr+n);

    for(int i=0;i<m;i++)
        minsum+=arr[i];
    for(int i=n-1;i>=(n-1)-m+1;i--)
        maxsum+=arr[i];

    return maxsum-minsum;
}
int mySqrt(int x){
    /*here we use binary search over all possible values from 1 - x and then at each of the value compute val*val
    to check see if its equal to ,greater or less than the number and then we reduce the search space accordingly*/
    //double precision = 1e-2,low=0.0,high=x*1.0;

    double low=1,high=x,mid;
    while(high-low>eps){
        mid=(high+low)/2;

        if(mid*mid<1.0*x){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return high;
}
ListNode* swapNodes(ListNode* head, int k){
    ListNode* prev1=nullptr,*prev2=nullptr;
    ListNode* current1=head,*current2=head;
    int length=0,temp,kend;
    /*first we find the length*/
    while (current1!=nullptr)
    {
        length++;
        current1=current1->next;
    }

    if(k>length/2){
        temp=(length%k)+1;
        k=temp;
        kend=length-temp+1;
    }
    else{
        temp=k;
        kend=length-k+1;
    }
    current1=head;
    if(k==kend)
        return head;

    ListNode *next1=current1->next,*next2=current2->next;
    k--;
    /*first we find the first node*/
    while (k)
    {   
        prev1=current1;
        current1=current1->next;
        next1=current1->next;
        k--;
    }

    kend--;
    while (kend)
    {   
        prev2=current2;
        current2=current2->next;
        next2=current2->next;
        kend--;
    }

    if(next1==prev2){
        if(temp==1){
            current2->next=next1;
        }
        else{
            prev1->next=current2;
            current2->next=next1;
        }
        next1->next=current1;
        current1->next=next2;
    }
    else if(next1==current2){
        if(temp==1){
            current2->next=current1;
        }
        else{
            prev1->next=current2;
            current2->next=current1;
        }
        current1->next=next2;
    }
    else{
        if(temp==1){
            current2->next=next1;
        }
        else{
            prev1->next=current2;
            current2->next=next1;
        }
        current1->next=next2;
        prev2->next=current1;
    }
    if(temp==1)
        head=current2;
    return head;
}
double myPow(double x, int n){
    if(n==1)
        return x;
    return x*myPow(x,n-1);
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int largestFibonacciNumber(int n);
int computefib(int);
int largestForwardDiagonal(const vector<vector<int>> & M);
int computeforwardrowsum(const vector<vector<int>>&,int,int,int);
int computeforwardcolsum(const vector<vector<int>>&,int,int,int);

const int N=1e5+10;
const int N1=1e6+10;

class ListNode {
    public:
	int val;
	ListNode* next;

	ListNode() {}

	ListNode(int x) {
	    val = x;
	    next = NULL;
	}
};
ListNode *head=nullptr;
int countDuplicatesInALinkedList(ListNode* head);

int dp[N];
int nodecount[N1];

int main(){
    memset(dp,-1,sizeof(dp));
    //cout<<largestFibonacciNumber(1000000000)<<endl;
    //cout<<countDuplicatesInALinkedList(head)<<endl;
    int n, m;
    cin>>n>>m;
    vector<vector<int>>M(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>M[i][j];
        }
    }
    int result = largestForwardDiagonal(M);
    cout<<result;

    return 0;
}
int largestFibonacciNumber(int n){
    int largestfib;
    // allfib[1]=1;

    // for(int i=2;i<N;i++)
    //     allfib[i]=allfib[i-2]+allfib[i-1];
    
    // for(int i=0;i<=N;i++){
    //     if(allfib[i]<n)
    //         largestfib=allfib[i];
    //     else
    //         break;
    // }
    // return largestfib;
    for(int i=1;i<=n;i++){
        if(computefib(i)<n)
            largestfib=computefib(i);
        else
            break;
    }
    return largestfib;
}
int computefib(int num){
    if(dp[num]!=-1)
        return dp[num];
    if(num==0)
        return 0;
    if(num==1)
        return 1;
    return dp[num]=computefib(num-1)+computefib(num-2);
}
int countDuplicatesInALinkedList(ListNode* head){
    ListNode *current=head, *nextnode=current->next;
    int dupnodes=0;
    if(head==nullptr || head->next==nullptr)
        return 0;
    
    nodecount[current->val]=1;
    while (nextnode)
    {
        if(nodecount[nextnode->val]==1){
            dupnodes++;
        }
        else
            nodecount[nextnode->val]=1;
        current=nextnode;
        nextnode=current->next;
    }
    return dupnodes;
}
int largestForwardDiagonal(const vector<vector<int>> & M){
    int rows=M.size()-1, cols=M[0].size()-1;
    int numforwarddia=rows+cols-1,maxfordiasum=-1,rowstart=rows,colstart=1;

    while(rowstart>=0){
        maxfordiasum=max(maxfordiasum,computeforwardrowsum(M,rowstart,rows,cols));     /*this computes row increase sum*/
        rowstart--;
    }
    // cout<<maxfordiasum<<endl;

    while (colstart<=cols)
    {
        maxfordiasum=max(maxfordiasum,computeforwardcolsum(M,colstart,rows,cols));     /*this computes col increase sum*/
        colstart++;
    }
    return maxfordiasum;
}
int computeforwardrowsum(const vector<vector<int>>& M,int rs,int rows,int cols){
    int sum=0,j=0,i=rs;
    while(i<=rows && j<=cols){
        sum+=M[i][j];
        j++;
        i++;
    }
    return sum;
}
int computeforwardcolsum(const vector<vector<int>>& M,int cs,int rows,int cols){
    int sum=0,i=0,j=cs;
    while(i<=rows && j<=cols){
        sum+=M[i][j];
        i++;
        j++;
    }
    return sum;
}


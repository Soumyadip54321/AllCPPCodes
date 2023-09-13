#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
//given an array of N integers and Q queries with l and r number in each. Print sum of elements from l to r(inclusive).
//constraints:
/*1<=N<=10^5*/
/*1<=A[I]<=10^7*/
/*1<=Q<=10^5*/
/*1<=L,R<=N*/
const int N=1e5+10;
int prefix_sum[N];
int a[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        prefix_sum[i]=prefix_sum[i-1]+a[i];
    }
    
    int q;
    cin>>q;
    while(q--){                             //This now has T(N)=O(N)+O(Q)=O(N)
        int l,r;
        cin>> l >> r;
        // long long sum=0;
        // for(int i=l;i<=r;i++)
        //     sum+=a[i];
        // cout<<sum<<endl;
        cout<<prefix_sum[r]-prefix_sum[l-1]<<endl;
    }
    //O(N)+O(Q*N)=O(N^2)=10^10 NOT RUNNABLE WITHIN 1 sec

    //we use prefix sum concept where each element of array has sum starting from beginning of array till that number

    return 0;
}
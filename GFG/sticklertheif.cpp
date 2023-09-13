#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int FindMaxSum(int arr[], int n);
int computemaxsum(int*,int,int);
int dp[10010];

int main(){
    memset(dp,-1,sizeof(dp));
    int arr[]={5,5,10,100,10,5};
    cout<<FindMaxSum(arr,6);
    return 0;
}
int FindMaxSum(int arr[], int n){
    return computemaxsum(arr,n,0);           //TC=O(2^n),SC=O(n); must be solved using dp
}
int computemaxsum(int* arr,int n,int idx){
    if(dp[idx]!=-1)
        return dp[idx];

    if(idx>=n){
        return 0;
    }
    //take money from house or not take;
    //here we capture the maximum amount the thief can loot considering first house or not;
    // we store the amount in dp[idx];
    return dp[idx]=max(arr[idx]+computemaxsum(arr,n,idx+2),computemaxsum(arr,n,idx+1));
}
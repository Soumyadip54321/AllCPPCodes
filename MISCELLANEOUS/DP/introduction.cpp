#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int fib(int);

const int N=1e5+10;
int dp[N];
//top down approach

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];           //memoize

    return dp[n]=fib(n-1)+fib(n-2);
}
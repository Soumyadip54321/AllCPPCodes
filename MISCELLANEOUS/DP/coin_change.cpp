#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int N=1e5+10;
int dp[N];

int func(int,vector<int>);
int coinchange(vector<int>,int);

int main(){
    vector<int> coins={1,2,5};
    cout<<coinchange(coins,11)<<endl;
    return 0;
}
int coinchange(vector<int> coins,int amount){
    int ans=func(amount,coins);
    return ans==INT_MAX?-1:ans;
}
int func(int amount,vector<int> coins){
    if(amount==0)
        return 0;
    int ans=INT_MAX;
    for(auto coin:coins){
        if(amount-coin>=0)
            ans=min(func(amount-coin,coins)+1LL,ans+0LL);
    }
    return ans;
}
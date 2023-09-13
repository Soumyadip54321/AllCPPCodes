#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums);
int findmaxsum(vector<int>,int);
// int largest=-1;
vector<int> dp(1010,-1);

int main(){ 
    vector<int> nums={3,10,10,7};
    cout<<maximumNonAdjacentSum(nums);
    return 0;
}
int maximumNonAdjacentSum(vector<int> &nums){
    return findmaxsum(nums,0);
}
int findmaxsum(vector<int> nums,int idx){
    if(idx>=nums.size()){
        return 0;
    }
    if(dp[idx]!=-1)
        return dp[idx];

    //take
    int takesum=nums[idx]+findmaxsum(nums,idx+2);
    //not take
    int nottakesum=findmaxsum(nums,idx+1);

    return dp[idx]=max(takesum,nottakesum);
}
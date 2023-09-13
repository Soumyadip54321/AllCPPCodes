#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums);

int main(){
    vector<int> nums={1,4,4};
    cout<<minSubArrayLen(4,nums);
    return 0;
}
int minSubArrayLen(int target, vector<int>& nums){
    //we use 2 ptr method here
    int p1=0,p2=0,sum=0,len=INT_MAX;

    do
    {
        sum+=nums[p2];

        if(sum>=target){
            len=min(len,p2-p1+1);
            sum-=nums[p1];
            sum-=nums[p2];
            p1++;
            p2--;
        }
            p2++;
    }while (p2<nums.size());

    if(len==INT_MAX)
        return 0;
    return len;
}
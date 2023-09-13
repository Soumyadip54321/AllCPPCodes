#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int longestSubarray(vector<int>& nums);

int main(){
    vector<int> nums={1,1,0,1};
    cout<<longestSubarray(nums);
    return 0;
}
int longestSubarray(vector<int>& nums){
    int left=0,centre=0,right=0,ctones1=0,ctones2=0,maxlands=0;
    while (nums[centre]!=0 && centre<nums.size())
        {
            ctones1++;
            centre++;
        }
    maxlands=max(maxlands,ctones1);

    if(centre>=nums.size())
        return maxlands-1;

    while (right<nums.size())
    {
        right=centre+1;
        while (nums[right]!=0 && right<nums.size())
        {
            ctones2++;
            right++;
        }
        maxlands=max(maxlands,ctones2+ctones1);
        left=centre;
        centre=right;
        ctones1=ctones2;
        ctones2=0;
    }
    return maxlands;
}
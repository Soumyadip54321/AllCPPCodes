#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target);

int main(){
    vector<int> nums={3,1};
    cout<<search(nums,1)<<endl;
    return 0;
}
int search(vector<int>& nums, int target){
    int n=nums.size(),low=0,high=n-1;

    while (high-low>1)
    {
        int mid=(low+high)/2;
        //check for sorted half
        if(nums[low]<nums[mid]){
            if(target>=nums[low] and target<nums[mid])
                high=mid;
            else
                low=mid;
        }
        else{
            if(target>nums[mid] and target<=nums[high])
                low=mid;
            else
                high=mid;
        }
    }
    if(nums[low]==target)
        return low;
    
    if(nums[high]==target)
        return high;

    return -1;
}
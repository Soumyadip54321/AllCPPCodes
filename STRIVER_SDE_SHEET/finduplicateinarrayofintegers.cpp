#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int findDuplicate(vector<int>& nums);

int main(){
    vector<int> nums={1,2,3,5,4,4};
    cout<<findDuplicate(nums);
    return 0;
}
int findDuplicate(vector<int>& nums){
    /*
    idea:
    1. we assume all items present only once such that since we've item ranging from [1,n]
    we mark for each entry its corresponding value at arr[val-1] negative indicating it's presence
    2. In the event we obtain a duplicate element we'd try and mark an already marked negative element in which case we return
    */

   int m=nums.size(),dupitem=0;
   for(int i=0;i<m;i++){
        if(nums[abs(nums[i])-1]<0){
            dupitem=abs(nums[i]);
            break;
        }
        else{
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
   }

    for(int i=0;i<m;i++){
        if(nums[i]<0)
            nums[i]*=-1;
    }

    // for(auto val:nums)
    //     cout<<val<<",";
    // cout<<endl;

   return dupitem;
}
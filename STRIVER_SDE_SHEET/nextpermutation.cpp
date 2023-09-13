#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
void nextPermutation(vector<int>& nums);

int main(){
    vector<int> nums={3,2,1};
    nextPermutation(nums);
    return 0;
}
void nextPermutation(vector<int>& nums){
    int n=nums.size();
    int s=n-2,e=n-1;

    /*
    1. we keep the longest prefix that matches i.e. we start from that end of the vector and 
    find position where arr[i]<arr[i+1]
    2. that gives the position where we need to put element greater than arr[i] but closes into
    */

   //breakpoint find
   while (s>=0)                             //TC=O(N)
   {
        if(nums[s]<nums[e])
            break;
        e=s;
        s--;
   }

                                                    /*case when number is the laregst possible permutation
                                                     in which case we simply fall back to the smallest number possible via rearrangement 
                                                    and return that.*/
        
    if(s<0){                                        //TC=O(NLOG(N))
        sort(nums.begin(),nums.end());
        return;
   }

   //find element greater than that at nums[s] but closest (minimal difference)such that we obtain the immediate next largest permutation
   int diff=INT_MAX,clidx;
   for(int i=n-1;i>s;i--){                                  //TC=O(N)
        if(nums[i]>nums[s] && nums[i]-nums[s]<diff){
            clidx=i;
            diff=nums[i]-nums[s];
        }
   }

   swap(nums[s],nums[clidx]);                       //TC=O(1)

   //next we sort all entries after s in incresing order
   sort(nums.begin()+s+1,nums.end());                   //TC=O(NLOG(N))

    for(auto val:nums)
        cout<<val<<",";
    cout<<endl;

    /*overall TC=O(NLOG(N))*/
}
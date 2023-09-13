#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> slidingWindowMaximum(vector<int> &nums, int &k);


int main(){
    vector<int> nums={1,0,1,2,2,2,2,1,0,2},v;
    int k=2;
    v=slidingWindowMaximum(nums,k);
    return 0;
}
vector<int> slidingWindowMaximum(vector<int> &nums, int &k){
    /*
    idea
    1. we traverse the window size and set the maximum in each in a priority queue
    2. we empty out queue in every new window
    */
   //BRUTE FORCE APPROACH

   vector<int> largestwindowelement;
   int maxval=-1,i=0;

//    while (i<=nums.size()-k)
//    {
//         largestwindowelement.push_back(*max_element(nums.begin()+i,nums.begin()+i+k));
//         i++;
//    }

   //BETTER APPROACH
   /*
   idea:
   1. here we maintain 2 variables -> largest & second largest
   */

    if(k==1)
        return nums;

    int largestidx=0,slargestidx=-1,start=0,end=0;

    while (start<=nums.size()-k)
    {
        end++;
        if(nums[end]>=nums[largestidx]){
            slargestidx=largestidx;
            largestidx=end;
        }
        else if(nums[end]>slargestidx)
            slargestidx=end;
        
        if(end==start+k-1){
            start++;

            largestwindowelement.push_back(nums[largestidx]);

            if(largestidx<start){
                largestidx=slargestidx;
            }
            slargestidx=-1;
        }
    }
    
   //TC=O((N-K+1)*K);
    for(auto val:largestwindowelement)
        cout<<val<<",";
    cout<<endl;
    return largestwindowelement;
}
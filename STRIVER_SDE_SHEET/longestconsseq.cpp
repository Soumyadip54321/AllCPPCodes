#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
// #include <unordered_map>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums);

int main(){
    vector<int> nums={4, 100, 3, 98, 99, 5, 2, 1};
    cout<<longestConsecutive(nums);
    return 0;
}
int longestConsecutive(vector<int>& nums){
    //----------METHOD-I TC=O(nLOG(n))----------------------
   /*
   idea:
   1.  we sort the array at first
   2. keep 3 variables ct=1,longest=1 & lastsmaller=INT_MIN(at t=0) which keeps the last smallest element visited in the array
   3. at every iteration we check whether A[i]-1 ==lastsmaller if it is then we increase ct 
   4. else if lastsmaller==A[i] we simply move forward
   5. when A[i]!=lastsmaller we start afresh with longest=max(longest,ct) & ct=1,lastsmaller=A[i];
   */

    // sort(nums.begin(),nums.end());
    // int n=nums.size(),longest=1,ct=1,lastsmaller=nums[0];

    // if(n==0)
    //     return 0;

    // for(int i=1;i<n;i++){
    //     if(nums[i]-1==lastsmaller){
    //         lastsmaller=nums[i];
    //         ct++;
    //     }
    //     else if(nums[i]!=lastsmaller){
    //         longest=max(longest,ct);
    //         ct=1;
    //         lastsmaller=nums[i];
    //     }
    // }
    // longest=max(longest,ct);
    // return longest;
    /*---------------METHOD-II TC=O(n)--------------------------*/

    /*idea:
    1.  we initialise a set to have only unique elements
    2.  we then traverse the set and at every iteration we check whether any element such that element-1 exists 
    3. if so we move forward else we start count the length of subseq starting from the element we're at
    */
    unordered_set<int> uniqueitems;
    int n=nums.size(),longest=1,ct=1;

    if(n==0)
        return 0;

    for(int i=0;i<n;i++){
        uniqueitems.insert(nums[i]);
    }

    for(auto it=uniqueitems.begin();it!=uniqueitems.end();it++){
        int num=*it;
        if(uniqueitems.find(num-1)==uniqueitems.end()){     //we find the start point of a sequence     //TC=O(1);
            while (uniqueitems.find(num+1)!=uniqueitems.end())          //TC=O(n)
            {
                ct++;
                num+=1;
            }
        }
        longest=max(longest,ct);
        ct=1;
    }
    return longest;
}
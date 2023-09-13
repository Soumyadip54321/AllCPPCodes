#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long minCost(vector<int>& nums, vector<int>& cost);

int main(){
    vector<int> nums={5,4,9,3},cost={1,2,8,3};
    cout<<minCost(nums,cost);
    return 0;
}
long long minCost(vector<int>& nums, vector<int>& cost){
    priority_queue<pair<int,int>> pq;

    int maxelement=*max_element(nums.begin(),nums.end()),idxofelementtoequalto;
    long long minsum=0;

    for(int i=0;i<nums.size();i++){
        pq.push({abs(maxelement-nums[i])*cost[i],i});
    }

    /*
    now we consider the element present at the index of pq.top() to be the one to make all other enreies equal to
    to minimize the overall cost
    */
   idxofelementtoequalto=pq.top().second;
    for(int i=0;i<nums.size();i++){
        minsum+=abs(nums[i]-nums[idxofelementtoequalto])*cost[i];
        nums[i]=nums[idxofelementtoequalto];
    }

    // for(auto val:nums)
    //     cout<<val<<",";
    // cout<<endl;
   return minsum;
}
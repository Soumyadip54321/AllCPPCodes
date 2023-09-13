#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int TotalPairs(vector<int>&nums, int x, int y);

int main(){
    vector<int> nums={5,3,7,9,7,9,7,7};
    cout<<TotalPairs(nums,7,19);
    return 0;
}
int TotalPairs(vector<int>&nums, int x, int y){
    int totalpairs=0;

    sort(nums.begin(),nums.end());

    //lower bound syntax: lower_bound(low,high,value) => this gives a pointer to the smallest index at which num[i]>=value exists
    //upper bound syntax: upper_bound(low,high,value) => this gives a pointer to the smallest index at which num[i]>value exists

    for(int i=0;i<nums.size();i++){
        int lb=0,ub=0;
        if(x%nums[i]==0)
            lb=lower_bound(nums.begin()+i+1,nums.end(),(x/nums[i]))-nums.begin();
        else
            lb=lower_bound(nums.begin()+i+1,nums.end(),((x/nums[i])+1))-nums.begin();

        ub=upper_bound(nums.begin()+i+1,nums.end(),(y/nums[i]))-nums.begin();
        totalpairs+=(ub-lb);
    }
    return totalpairs;
}
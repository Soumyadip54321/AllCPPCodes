#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
 vector<int> majorityElement(vector<int>& nums);

int main(){
    vector<int> nums={1,1,2,3,1,2,2,3},ans;
    ans=majorityElement(nums);
    return 0;
}
vector<int> majorityElement(vector<int>& nums){
    // int n=nums.size(),minct=ceil(n/3);
    // vector<int> ans;
    // int itemct=1;

    // sort(nums.begin(),nums.end());

    // for(int i=1;i<n;i++){
    //     if(nums[i]==nums[i-1])
    //         itemct++;
    //     else{
    //         if(itemct>minct)
    //             ans.push_back(nums[i-1]);
    //         itemct=1;
    //     }
    // }
    // if(itemct>minct)
    //     ans.push_back(nums[n-1]);


    // return ans;
    //TC=O(nlg(n)),SC=O(1);

    vector<int> ans;
    int ct1=0,ct2=0,el1,el2;                //since to find elements that occur >floor(n/3) times there can atmost be 2 such items
    int n=nums.size(),minct=floor(n/3);

    for(int i=0;i<n;i++){
        if(ct1==0 and nums[i]!=el2){
            el1=nums[i];
            ct1++;
        }
        else if(ct2==0 and nums[i]!=el1){
            el2=nums[i];
            ct2++;
        }
        else if(nums[i]==el1)
            ct1++;
        else if(nums[i]==el2)
            ct2++;
        else{
            ct1--;
            ct2--;
        }
    }
    ct1=0,ct2=0;
    //we check if el1 and/or el2 does form majority elements here
    for(int i=0;i<n;i++){
        if(nums[i]==el1)
            ct1++;
        if(nums[i]==el2)
            ct2++;
    }
    if(ct1>minct)
        ans.push_back(el1);
    if(ct2>minct)
        ans.push_back(el2);

    // for(auto val:ans)
    //     cout<<val<<",";
    // cout<<endl;
    
    return ans;

    //TC=O(n),SC=O(1);
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target);

int main(){
    vector<int> nums={2,2,2,2,2};
    vector<vector<int>> quadruplets;
    quadruplets=fourSum(nums,8);
    return 0;
}
vector<vector<int>> fourSum(vector<int>& nums, int target){

    int n=nums.size();
    vector<vector<int>> result;

    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])
            continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1])
                continue;

            int k=j+1,l=n-1;

            while (k<l)
            {
                long long sum=nums[i]+nums[j];
                sum+=nums[k];
                sum+=nums[l];

                if(sum==target){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    temp.push_back(nums[l]);

                    result.push_back(temp);
                    k++;
                    l--;

                    while (k<l && nums[k]==nums[k-1])
                    {
                        k++;
                    }

                    while (k<l && nums[l]==nums[l+1])
                    {
                        l--;
                    }
                }
                else if(sum<target){
                    k++;
                }
                else
                    l--;
            }
        }
    }

    // for(int i=0;i<result.size();i++){
    //     cout<<"{";
    //     for(auto val:result[i])
    //         cout<<val<<",";
    //     cout<<"}"<<endl;
    // }

    return result;
}
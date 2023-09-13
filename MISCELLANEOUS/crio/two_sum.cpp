#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target);
map<int,vector<int>> m;

const int n=1e5+10;
vector<int> adjlist[n];

int main(){
    vector<int> nums={2,4,5,9,8},v;
    int target=7;
    v=twoSum(nums,target);
    cout<<"{"<<v[0]<<","<<v[1]<<"}"<<endl;
    return 0;
}
vector<int> twoSum(vector<int>& nums, int target){
    vector<int> indices;
    for(int i=0;i<nums.size();i++){
        m[nums[i]]={i,target-nums[i]};
    }

    for(int i=0;i<nums.size();i++){
        if(m.find(m[nums[i]][1])!=m.end()){
            indices={i,m[m[nums[i]][1]][0]};
            break;
        }
    }
    sort(indices.begin(),indices.end());
    return indices;
}


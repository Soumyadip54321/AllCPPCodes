#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
void threeSum(vector<int>& nums);
const int n=1e6+10;
int ct[n];

int main(){
    vector<int> nums={-3,0,1,2,-1,1,-2};
    threeSum(nums);
    return 0;
}
void threeSum(vector<int>& nums){
    set<vector<int>> s;
    int minitem=0;
    if(*min_element(nums.begin(),nums.end())<0)
        minitem=*min_element(nums.begin(),nums.end());
    
    for(int i=0;i<nums.size();i++){
        ct[nums[i]-minitem]++;
    }

    //BRUTE FORCE TC=O(N^2)
    for(int i=0;i<nums.size();i++){
        set<int> hashset;
        for(int j=i+1;j<nums.size();j++){

            if(hashset.find(-(nums[i]+nums[j]))!=hashset.end()){
                vector<int> temp={nums[i],nums[j],-1*(nums[i]+nums[j])};
                sort(temp.begin(),temp.end());
                s.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }

    vector<vector<int>> alltriplets(s.begin(),s.end());

    for(int i=0;i<alltriplets.size();i++){
        for(auto val:alltriplets[i])
            cout<<val<<",";
        cout<<endl;
    }
}
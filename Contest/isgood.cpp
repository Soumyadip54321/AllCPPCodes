#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
bool isGood(vector<int>& nums);

int main(){
    vector<int> nums={1,1};
    cout<<isGood(nums);
    return 0;
}
bool isGood(vector<int>& nums){
    int n=nums.size();
    int maxitem=*max_element(nums.begin(),nums.end());
    unordered_map<int,int> m;

    if(n!=maxitem+1)
        return false;
    
    for(int i=0;i<n;i++)
        m[nums[i]]++;

    for(int i=1;i<=maxitem;i++){
        if(i<maxitem){
            if(m[i]!=1)
                return false;
        }
        else if(i>maxitem){
            return false;
        }
        else{
            if(m[i]!=2)
                return false;
        }
    }
    return true;
}
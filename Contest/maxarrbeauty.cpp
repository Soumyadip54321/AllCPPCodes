#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int maximumBeauty(vector<int>& nums, int k);

int main(){ 
    vector<int> nums={4,6,1,2};
    cout<<maximumBeauty(nums,2);
    return 0;
}
int maximumBeauty(vector<int>& nums, int k){
    //here each element can be made to take a value b/w [nums[i]-k,nums[i]+k]
    /*
    idea:
    1.   start at 1st index and traverse array trying to change all rem item to match nums[0] if possible
    */
   int maxbeauty=-1,n=nums.size(),p1=0;
   vector<pair<int,int>> rangesofitems;
   unordered_map<int,int> maxoccur;
   bool issame=true;

   //first check if all array items same in which case we return length
    for(int i=0;i<n-1;i++){
        if(nums[i]!=nums[i+1]){
            issame=false;
            break;
        }
    }
    if(issame)
        return n;
    
    /*
    idea:
    1.  now we find range each value can attain.
    */
    for(int i=0;i<n;i++){
        pair<int,int> p;

        if(nums[i]-k>=0)
            p.first=nums[i]-k;
        else
            p.first=0;
        p.second=nums[i]+k;
        rangesofitems.push_back(p);
    }

    for(auto p:rangesofitems)
        cout<<"("<<p.first<<","<<p.second<<")";
    cout<<endl;

    //now we layout all elements present in the ranges in a vector



    return 0;
}
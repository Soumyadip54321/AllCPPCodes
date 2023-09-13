#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int minimumIndex(vector<int>& nums);

int main(){
    vector<int> nums={1,2,2,2};
    cout<<minimumIndex(nums);
    return 0;
}
int minimumIndex(vector<int>& nums){
    //find dominant item
    int n=nums.size(),domitem,splitpos=0,fidx,lidx,totaldomct,rightdomct=0,leftdomct=0;
    unordered_map<int,int> freq;

    for(int i=0;i<n;i++)
        freq[nums[i]]++;
    
    for(auto val:freq){
        if(val.second*2>n){
            domitem=val.first;
            totaldomct=val.second;
            break;
        }
    }

    //find out first and last index of domitem
    for(int i=0;i<n;i++){
        if(nums[i]==domitem){
            fidx=i;
            break;
        }
    }

    splitpos=fidx;
    leftdomct=1;
    rightdomct=totaldomct-leftdomct;

    int leftarrsize=splitpos+1;
    int rightarrsize=n-leftarrsize;

    while ((leftdomct*2<=leftarrsize || rightdomct*2<=rightarrsize))
    {
        splitpos++;
        if(splitpos>=n)
            break;

        if(nums[splitpos]==domitem){
            leftdomct++;
            rightdomct--;
        }
        leftarrsize++;
        rightarrsize--;
    }
    
    if(splitpos==n)
        return -1;
    return splitpos;
}
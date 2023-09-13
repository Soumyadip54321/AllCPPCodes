#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int minAbsoluteDifference(vector<int>& nums, int x);
void computemindiff(vector<int>,int,int);

int mindiff=INT_MAX;

int main(){
    vector<int> nums={5,3,2,10,15};
    cout<<minAbsoluteDifference(nums,2);
    return 0;
}
int minAbsoluteDifference(vector<int>& nums, int x){
    /*
    idea:
    1.  
    */
    computemindiff(nums,nums.size(),0,0,0);
    return mindiff;
}
void computemindiff(vector<int> nums,int n,int idx1,int idx2,int ct){
    if(idx>=n)
        return;

    if(ct==2){
        mindiff=min(mindiff,diff);
        return;
    }

    for(int i=idx1;i<n;i++){
        computemindiff(nums,n,i,)
    }
}
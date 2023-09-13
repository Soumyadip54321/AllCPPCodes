#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int maxsubarraysum(vector<int>&);
int maxsubarraysum2(vector<int>&);
const int n=1e5+10;
int contsum[n];

int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4},indices;
    cout<<maxsubarraysum(nums)<<endl;
    return 0;
}   
int maxsubarraysum(vector<int>& nums){
    //here we use KADANE'S ALGORITHM
    int maxsum=INT_MIN,total=0,start=0,end=0;
    for(int i=0;i<nums.size();i++){
        if(total==0)
            start=i;

        total+=nums[i];

        if(total>maxsum){
            maxsum=total;
            start=start;
            end=i;
        }
        if(total<0){
            total=0;
        }
    }
    cout<<start<<":"<<end<<endl;
    return maxsum;
}
//TC=O(n), SC=O(1); 
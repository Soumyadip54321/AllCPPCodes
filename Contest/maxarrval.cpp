#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
long long maxArrayValue(vector<int>& nums);

int main(){
    vector<int> nums={34,92,42,24,98,87,40,82,51,67,70,75,45,57,67};
    cout<<maxArrayValue(nums);
    return 0;
}
long long maxArrayValue(vector<int>& nums){
    int n=nums.size(),sum=0,res=-1;
    sum=nums[n-1];

    for(int i=n-2;i>=0;i--)
    {
        if(nums[i]<=sum)
            sum+=nums[i];
        else{
            res=max(res,sum);
            sum=nums[i];
        }
    }
    res=max(res,sum);
    return res;
}
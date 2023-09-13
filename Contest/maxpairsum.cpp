#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int maxSum(vector<int>& nums);
bool issamemaxdigit(int,int);

int main(){
    vector<int> nums={1,2,3,4};
    cout<<maxSum(nums);
    return 0;
}
int maxSum(vector<int>& nums){
    /*
    idea:
    1.  we iterate through the array
    2.  for every element we check whether there exists element with max digit same as that and if so compute sum storing it in our ans
    */
   int maxsum=-1,n=nums.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(issamemaxdigit(nums[i],nums[j]))
                maxsum=max(maxsum,nums[i]+nums[j]);
        }
    }
   return maxsum;
}
bool issamemaxdigit(int num1,int num2){
    string s1=to_string(num1),s2=to_string(num2);
    int maxdigit1=0,maxdigit2=0;

    for(int i=0;i<s1.length();i++){
        if(s1[i]-'0'>maxdigit1)
            maxdigit1=max(maxdigit1,s1[i]-'0');
    }
    for(int i=0;i<s2.length();i++){
        if(s2[i]-'0'>maxdigit2)
            maxdigit2=max(maxdigit2,s2[i]-'0');
    }

    if(maxdigit1==maxdigit2)
        return true;
    return false;
}
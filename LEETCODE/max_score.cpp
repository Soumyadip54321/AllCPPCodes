#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int maxScore(vector<int>& nums);
void maxgcdsum(vector<int>,int,priority_queue<int>&);
int findgcd(int,int);


int main(){
    vector<int> nums={697035,181412,384958,575458};
    cout<<maxScore(nums)<<endl;
    return 0;
}
int maxScore(vector<int>& nums){
   priority_queue<int> maxgcds;
   int sum=0;

   maxgcdsum(nums,nums.size()-1,maxgcds);

   for(int i=nums.size()/2;i>=1;i--){
        sum+=i*maxgcds.top();
        maxgcds.pop();
   }
    return sum;
}
void maxgcdsum(vector<int> nums,int idx,priority_queue<int>& maxgcds){
    int maxgcd=-1,pos=0,prevgcd=maxgcd;
    for(int i=0;i<idx;i++){
        maxgcd=max(maxgcd,findgcd(nums[idx],nums[i]));
        if(maxgcd>prevgcd){
            pos=i;
            prevgcd=maxgcd;
        }
    }
    cout<<maxgcd<<":"<<nums[idx]<<" and "<<nums[pos]<<endl;
    nums.erase(nums.begin()+idx);
    nums.erase(nums.begin()+pos);

    maxgcds.push(maxgcd);
    if(!nums.empty())
        maxgcdsum(nums,nums.size()-1,maxgcds);
}
int findgcd(int num1,int num2){
    if(num1<num2)
       swap(num1,num2);

    if(num1%num2==0 || num1==0)
        return num2;
    return findgcd(num2,num1%num2);
}

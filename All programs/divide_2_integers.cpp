#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int divide(int dividend, int divisor);
void countresult(int,int,int&);
int uniquePaths(int m, int n);
int numpaths(int x,int y,int m,int n);
int removeDuplicates(vector<int>& nums);

const int N=1e5+10;
int elect[N];


int main(){
    // cout<<divide(-7,3)<<endl;
    vector<int> nums={-1,0,0,0,0,3,3};
    //cout<<uniquePaths(3,7)<<endl;
    cout<<removeDuplicates(nums)<<endl;
    return 0;
}
int divide(int dividend, int divisor) {
        int result=0;
        if(divisor<0)
            countresult((dividend),divisor,result);
        countresult((dividend),(divisor),result);
        return result;
}

void countresult(int dividend, int divisor,int& result){
    if(abs(dividend)-abs(divisor)<=0)
        return;
    if(dividend<0 || divisor<0)
        result--;
    else 
        result++;
    // cout<<result<<endl;
    if(dividend<0 || divisor<0)
        countresult(dividend+divisor,divisor,result);
    countresult(dividend-divisor,divisor,result);
}
int uniquePaths(int m, int n) {
        int x=0,y=0;
        return numpaths(x,y,m,n);
    }
int numpaths(int x,int y,int m,int n){
    if(x==m-1 && y==n-1)
        return 1;
    if(x>m-1 || y>n-1)
        return 0;
        
    return numpaths(x+1,y,m,n)+numpaths(x,y+1,m,n);
}
int removeDuplicates(vector<int>& nums){
    int i=0,min_el=1e5;
    for(auto num:nums){
        if(num<min_el)
            min_el=num;
    }
    if(min_el>=0)
        min_el=0;

    for(auto num:nums)
        elect[num-min_el]++;

    while(i<nums.size()){
        if(elect[nums[i]-min_el]>2){
            nums.erase(nums.begin()+i);
            elect[nums[i]-min_el]--;
        }
        else
            i++;
    }
    for(auto num:nums)
        cout<<num<<" ";
    cout<<endl;
    return nums.size();
}
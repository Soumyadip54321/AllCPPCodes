#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> subarraySum(vector<int>arr, int n, long long s);
bool checksum(long long,vector<int>&,int,int);
const int N=1e5+10;
// int hsh[N];
int dp[N];


int main(){
    memset(dp,-1,sizeof(dp));
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    v=subarraySum(v,10,15);
    cout<<endl;
    for(auto item:v)
        cout<<item<<" ";
    return 0;
}
vector<int> subarraySum(vector<int>arr, int n, long long s){
    // long long temp=s;
    // for(int i=0;i<n;i++){
    //     if(checksum(temp,arr,i,i)){
    //        return arr;
    //     }
    //     temp=s;
    // }
    if(s==0)
        return {-1};

    long long sum=0;
    int start=0,end=0;

    while(end<n){
        sum+=arr[end];
        cout<<sum<<endl;
        if(sum<s)
            end=end+1;

        else if(sum==s)
            return {start+1,end+1};
        
        else{
            sum-=arr[end];
            sum-=arr[start];
            start++;
        }
    }
    return {-1};
}
bool checksum(long long s,vector<int>& arr,int idx,int start){          //{1,3,6,10,15,21,28,35,44,54}

    if(s<0 || idx==arr.size())
        return false;

    if(s-arr[idx]==0){
        arr.clear();
        arr.push_back(start+1);
        arr.push_back(idx+1);
        return true;
    }
    // cout<<arr[idx]<<":"<<s-arr[idx]<<endl;
    return checksum(s-arr[idx],arr,idx+1,start);
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> solve(int n, vector<int> &arr, int q, vector<vector<int>> &queries);
void subarrmax(vector<int>&,vector<int>,int,int);

int main(){
    vector<int> arr={6, 4, 0, -17, -19},res;
    vector<vector<int>> queries={{0,2}};
    res=solve(5,arr,1,queries);
    return 0;
}
vector<int> solve(int n, vector<int> &arr, int q, vector<vector<int>> &queries){
    vector<int> maxsubsum;

    for(int i=0;i<q;i++){
        subarrmax(maxsubsum,arr,queries[i][0],queries[i][1]);
    }
    /* 
    TC=O(q*(queries[i][0]-queries[i][1])^2);
    */
    return maxsubsum;
}
void subarrmax(vector<int>& maxsubsum,vector<int> arr,int low,int high){
    int p=low,ms=INT_MIN;

    while (low<=high)
    {
        int sum=0;
        while (p<=high)
        {
            sum+=arr[p];
            ms=max(ms,sum);
            p++;
        }
        low++;
        p=low;
    }
    maxsubsum.push_back(ms);
}
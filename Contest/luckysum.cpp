#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int M=1e9+7;
int luckySum(int n, long long k, vector<long long> &a);
void computesubsetsum(vector<long long>,long long,int,long long);
long long ct=0;

int main(){
    vector<long long> a={1,4,3,2,6};
    long long k=6;
    cout<<luckySum(5,k,a);
    return 0;
}
int luckySum(int n, long long k, vector<long long> &a){
    long long totalsubsets,sum=0;
    totalsubsets=pow(2,n)-1;

    computesubsetsum(a,k,0,sum);
    cout<<ct<<endl;
    cout<<totalsubsets<<endl;

    return (ct/totalsubsets)%M;
}
void computesubsetsum(vector<long long> arr,long long div,int idx,long long sum){
    if(idx==arr.size()){
        if(sum%div==0 and sum!=0)
            ct++;
        return;
    }

    //pick item
    computesubsetsum(arr,div,idx+1,sum+arr[idx]);

    //not pick item
    computesubsetsum(arr,div,idx+1,sum);
}
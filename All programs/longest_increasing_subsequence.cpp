#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int addDigits(int num);
int addDigitsoptimised(int num);
int lis(int);
int sum;
vector<int> arr={5,2,4,8,3,40};
list<int> ans;
vector<list<int>> alldecseq;
int dp[6];

int main(){
    memset(dp,-1,sizeof(dp));       //introducing DP to reduce exponential time complexity of recursion

    int number=456,length=0;
    for(int i=arr.size()-1;i>=0;i--){
        length=max(length,lis(i));
        ans.clear();
    }
    
    for(int j=0;j<alldecseq.size();j++){
        cout<<"{";
        for(auto item:alldecseq[j])
            cout<<item<<" ";
        cout<<"}"<<endl;
    }
    cout<<length<<endl;
    return 0;
}
int addDigits(int num){
    if(num==0)
        return 0;
    
    sum=num%10+addDigits(num/10);
    if(sum/10==0)
        return sum;
    else
        return addDigits(sum);
}
int addDigitsoptimised(int num){
    if (num%9==0)
        return 9;
    else
        return num%9;
}

//Very important LONGEST INCREASING SUBSEQUENCE FOR DYNAMIC PROGRAMMING.
int lis(int idx){

    if(dp[idx]!=-1)
        return dp[idx];

    ans.push_front(arr[idx]);
    int length=1;

    for(int i=0;i<idx;i++){
        list<int> prev=ans;
        if(arr[i]<arr[idx]){
            length=max(length,1+lis(i));
        }
        ans=prev;
    }
    alldecseq.push_back(ans);
    return dp[idx]=length;
}

//with DP T(n)=O(n^2)


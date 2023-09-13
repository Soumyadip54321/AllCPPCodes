#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

long long mostPoints(vector<vector<int>>& questions);
// long long calculatemaxpoints(vector<vector<int>>,int,long long);
long long calculatemaxpointsdp(vector<vector<int>>,int,long long);
const int N=1e5+10;
long long dp[N];

int main(){
    memset(dp,-1,sizeof(dp));
    vector<vector<int>> questions={{5,2},{6,1},{4,4},{2,5}};
    cout<<mostPoints(questions)<<endl;
    return 0;
}
long long mostPoints(vector<vector<int>>& questions){
    // maxpoints = max(maxpoints,calculatemaxpointsdp(questions,questions.size()-1,0));
    return calculatemaxpointsdp(questions,questions.size()-1,0);
}
long long calculatemaxpoints(vector<vector<int>> questions,int idx,long long maxpts){       //BRUTE FORCE RECURSION WITH DP
    if(dp[idx]!=-1)
        return dp[idx];

    if(idx>=questions.size())
        return 0;

    maxpts=max(questions[idx][0]+calculatemaxpoints(questions,idx+1+questions[idx][1],maxpts),calculatemaxpoints(questions,idx+1,maxpts));
    return dp[idx]=maxpts;
}
long long calculatemaxpointsdp(vector<vector<int>> questions,int idx,long long maxpts){
    for(int i=idx;i>=0;i--){
        maxpts=max(maxpts,max(questions[i][0]+calculatemaxpoints(questions,i+1+questions[i][1],maxpts),calculatemaxpoints(questions,i+1,maxpts)));
    }
    return maxpts;
}




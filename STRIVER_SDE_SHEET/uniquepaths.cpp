#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int uniquePaths(int m, int n);
int computepaths(int,int,int,int,vector<vector<int>>&);

int main(){
    cout<<uniquePaths(90,70);
    return 0;
}
int uniquePaths(int m, int n){
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return computepaths(m,n,0,0,dp);
}
int computepaths(int m,int n,int x,int y,vector<vector<int>>& dp){
    if(x==m-1 && y==n-1)
        return 1;
    if(x>=m || y>=n)
        return 0;
    
    if(dp[x][y]!=-1)
        return dp[x][y];
    
    return dp[x][y]=computepaths(m,n,x+1,y,dp)+computepaths(m,n,x,y+1,dp);
}
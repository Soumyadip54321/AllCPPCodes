/*This DP approach demonstrates finding the longest palindromic subsequence of a string*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int longestPalinSubseq(string A);
int computeLPS(string,int,int);
int LPSdp(string,string,int,int);
int dp[1001][1001];

int main(){
    memset(dp,-1,sizeof(dp));

    string str="bbabcbcab";
    cout<<longestPalinSubseq(str);
    return 0;
}
int longestPalinSubseq(string A){
    int n=A.length();
    string dupA=A;
    reverse(dupA.begin(),dupA.end());
    //return computeLPS(A,0,n-1);
    return LPSdp(A,dupA,n,n);
}
int computeLPS(string s,int i,int j){
/*------------------------------BRUTE FORCE RECURSION  TC=O(2^n)/SC=O(n^2)-------------------------------------*/
    if(i==j)                     //when string has only single character
        return 1;

    if(j==i+1 && s[i]==s[j])    //string has 2 characters with both same
        return 2;
    
    //string has >2 characters & first and last same
    if(s[i]==s[j]){
        return 2+computeLPS(s,i+1,j-1);
    }
    //string with first & last dissimilar
    return max(computeLPS(s,i+1,j),computeLPS(s,i,j-1));
}
int LPSdp(string s1,string s2,int n1,int n2){
    /*---------METHOD-II DP-APPROACH----------------------*/
    if(n1==0 || n2==0)          //both string empty
        return 0;

    if(dp[n1][n2]!=-1)                                  /*dp[i][j]=> lps for substring starting at i and ending at j*/
        return dp[n1][n2];

    if(s1[n1-1]==s2[n2-1]){
        return dp[n1][n2]=1+LPSdp(s1,s2,n1-1,n2-1);
    }
    return dp[n1][n2]=max(LPSdp(s1,s2,n1,n2-1),LPSdp(s1,s2,n1-1,n2));
}
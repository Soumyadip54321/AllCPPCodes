#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

long long appealSum(string s);
int countDistinct(vector<int>& nums, int k, int p);
void subsetsgenerate(vector<string>&,string,string);

const int n=1e5+10;

int dp[n];

int main(){
    memset (dp,-1,sizeof(dp));
    vector<int> nums={1,2,3,4};
    string s="code";
    cout<<appealSum(s)<<endl;
    //cout<<countDistinct(nums,4,1)<<endl;
    return 0;
}
/*int countDistinct(vector<int>& nums, int k, int p){
    string s="";
    int ct=0,numdiv=0;
    set<string> subsets;
    for(auto val:nums)
        s+=to_string(val);

    subsetsgenerate(subsets,s,"");

    for(auto str:subsets){
        cout<<str<<" ";
        for(int i=0;i<str.length();i++){
            if((str[i]-'0')%k==0)
                numdiv++;
        }
        //cout<<numdiv<<" ";
        if(numdiv<=p)
            ct++;
        numdiv=0;
    }
    return ct;
}*/
void subsetsgenerate(vector<string>& subsets,string s,string str){
    if(s.length()==0){
        if(str!="")
            subsets.push_back(str);
        return;
    }
    string ros=s.substr(1);
    char ch=s[0];

    subsetsgenerate(subsets,ros,str+ch);
    subsetsgenerate(subsets,ros,str);
}
long long appealSum(string s){
    vector<string> v;
    long long sum=0;
    /*we use sliding window approach to generate all strings of length 1 to whole string length*/
    int sz=1,i=0;
    while(sz<=s.length()){
        while (i<s.length())
        {
            if(i+sz<=s.length())
                v.push_back(s.substr(i,sz));
            i++;
        }
        i=0;
        sz++;
    }
    for(auto str:v){
        //cout<<str<<" ";
        unordered_map<char,int> m;
        for(int i=0;i<str.length();i++){
            if(m.find(str[i])==m.end()){
                sum++;
                m[str[i]]++;
            }
        }
    }
    /*now for every substring we add 1 for evry different chracters present*/
    return sum;
}

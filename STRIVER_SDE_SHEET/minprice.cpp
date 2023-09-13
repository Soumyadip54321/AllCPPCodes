#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

long long minCost(int n, vector<int> &p, vector<int> &f);
void computemincost(vector<pair<int,int>>,int,int,int);
long long minspent=__LONG_LONG_MAX__;

int main(){
    vector<int> p={1,10,100},f={0,0,2};
    cout<<minCost(3,p,f);
    return 0;
}
long long minCost(int n, vector<int> &p, vector<int> &f){
    /*
    idea:
    1. we try out all combinations and then select the one with minimum spend while attainment of n items
    */
   //first we create pairs of form (cp,freeitem);
    vector<pair<int,int>> v;

    for(int i=0;i<n;i++)
        v.push_back({p[i],f[i]});
    
    computemincost(v,0,0,0);
    return minspent;
}
void computemincost(vector<pair<int,int>> v,int idx,int itempurchased,int moneyneeded){
    if(idx==v.size()){
        if(itempurchased>=v.size() and minspent>moneyneeded)
            minspent=moneyneeded;
        return;
    }
    //take
    computemincost(v,idx+1,itempurchased+1+v[idx].second,moneyneeded+v[idx].first);

    //not-take
    computemincost(v,idx+1,itempurchased,moneyneeded);
}
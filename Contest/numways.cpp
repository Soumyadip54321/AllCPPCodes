#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int M=1e9+7;

int numberOfWays(int n, int x);
void computeways(vector<int>,int,int,int,int);
int wayct=0;

int main(){
    cout<<numberOfWays(10,2);
    return 0;
}
int numberOfWays(int n, int x){
    /*
    idea:
    1. we fill an array with numbers from 1....n
    2. we run through the array items computing arr[i]^x everytime to check see if its equal or lesser or greater than n
    3.  if equal we increase ct that stores num ways we can form element
    4. if lesser we continue adding the next num^x
    5. else we return
    */
    vector<int> numtilln;

    for(int i=1;i<=n;i++)
        numtilln.push_back(i);
    
    computeways(numtilln,n,x,0,0);
    return wayct;
}
void computeways(vector<int> v,int target,int p,int idx,int sum){
    if(sum==target){
        wayct=(wayct+1)%M;
        return;
    }
    else if(sum>target){
        return;
    }
    
    for(int i=idx;i<v.size();i++){
        sum=(sum+(int)pow(v[i],p))%M;
        computeways(v,target,p,i+1,sum);

        sum=(sum-(int)pow(v[i],p))%M;          //backtrack
    }
}
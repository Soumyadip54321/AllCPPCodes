#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int maxCoins(int n,vector<vector<int>> &ranges);
int update(vector<vector<int>>,int);
/*we use hashing here to compute maximum coin value for each position*/
const int N=1e5+10;


int main(){
    vector<vector<int>> ranges={{1,3,4},{2,3,5},{3,4,2}};
    int n=3;
    cout<<maxCoins(n,ranges)<<endl;
    return 0;
}
int maxCoins(int n,vector<vector<int>> &ranges){
    int max_st=-1;
    // int *mch=new int[];

    for(int i=0;i<n;i++){
        if(ranges[i][0]>max_st)
            max_st=ranges[i][0];
    }

    // cout<<max_st<<endl;
    int* mch=new int[max_st+1];
    for(int i=0;i<max_st+1;i++)
        mch[i]=0;

    for(int i=0;i<n;i++){
        if(mch[ranges[i][0]]<ranges[i][2])
            mch[ranges[i][0]]=ranges[i][2];
    }
    for(int i=1;i<max_st+1;i++)
        cout<<mch[i]<<" ";
    cout<<endl;

    for(int i=0;i<n;i++){
        if(ranges[i][1]>max_st)
            continue;
        else{
            ranges[i][2]+=*max_element(mch+ranges[i][1],mch+max_st+1);
        }
    }
    max_st=-1;
    for(int i=0;i<n;i++){
        cout<<ranges[i][2]<<" ";
        if(ranges[i][2]>max_st)
            max_st=ranges[i][2];
    }
    cout<<endl;   
    return max_st;
}


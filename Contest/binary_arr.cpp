#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
vector<int> binaryArray(int n, vector<int> &arr);
int gfgGame(int N, int G, vector<int> &require, vector<int> &recieve);
const int N=1e5+10;
int rightsum[N];
pair<int,int> reqrec[N];

int main(){
    vector<int> arr={1,32,7,9},v,req={6,6,6},rec={4,1,3};
    int n=9,g=4;
    //v=binaryArray(4,arr);
    cout<<gfgGame(n,g,req,rec)<<endl;
    return 0;   
}
vector<int> binaryArray(int n, vector<int> &arr){
    int total=0,ls=0,sumtotal=0;
    int *rs=new int[n];

    for(int i=0;i<n;i++)
        rs[i]=0;

    for(auto num:arr)
        total+=num;

    sumtotal=total;
    for(int i=0;i<n;i++){
        rs[i]=total-arr[i];
        total=rs[i];
    }

    for(int i=0;i<n;i++)
        cout<<rs[i]<<" ";

    for(int i=0;i<n;i++){
        if((ls+rs[i])%2==0){
            ls=sumtotal-rs[i];
            arr[i]=1;
        }
        else{
            ls=sumtotal-rs[i];
            arr[i]=0;
        }
    }
    return arr;
}
int gfgGame(int N, int G, vector<int> &require, vector<int> &recieve){
    vector<int> indexes;
    int numtimes=0,min_diff;
    
    for(int i=0;i<N;i++){
        reqrec[require[i]-recieve[i]]=make_pair(require[i],recieve[i]);
        indexes.push_back(require[i]-recieve[i]);
    }
    sort(indexes.begin(),indexes.end());
    for(auto num:indexes)
        cout<<num<<" ";
    cout<<endl;


    // for(int i=0;i<N;i++){
    //     cout<<reqrec[indexes[i]].first<<","<<reqrec[indexes[i]].second<<" ";
    // }
    // cout<<endl;
    // int i=0;
    // while (i<indexes.size())
    // {
    //     if(G>=reqrec[indexes[i]].first){
    //         G=G-reqrec[indexes[i]].first+reqrec[indexes[i]].second;
    //         numtimes++;
    //     }
    //     else
    //         i++;
    // }
    return numtimes;
}
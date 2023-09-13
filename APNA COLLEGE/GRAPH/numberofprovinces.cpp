#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int findCircleNum(vector<vector<int>>& isConnected);
bool issafe(vector<vector<int>>,int,int);
void dfs(int);

const int n=1e5+10;
vector<int> adjlist[n];
bool visited[n];

int main(){
    vector<vector<int>> isconnected={{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    cout<<findCircleNum(isconnected)<<endl;
    return 0;
}
int findCircleNum(vector<vector<int>>& isConnected){
    int numprovinces=0;

    for(int i=0;i<isConnected.size();i++){
        for(int j=0;j<isConnected.size();j++){
            if(i==j){
                isConnected[i][j]=0;
                continue;
            }
            if(isConnected[i][j]==1)
                adjlist[i+1].push_back(j+1);
        }
    }
    // for(int i=1;i<=isConnected.size();i++){
    //     for(auto val:adjlist[i]){
    //         cout<<val<<" ";
    //     cout<<endl;
    //     }
    // }
    // cout<<endl;

    for(int i=1;i<=isConnected.size();i++){
        if(!visited[i]){
            dfs(i);
            numprovinces++;
        }
    }
    return numprovinces;
}
bool issafe(vector<vector<int>> isConnected,int x,int y){
    if(x>=0 && x<isConnected.size() && y>=0 && y<isConnected.size() && isConnected[x][y]==1)
        return true;
    return false;
}
void dfs(int city){
    visited[city]=true;

    for(auto child:adjlist[city]){
        if(visited[child])
            continue;
        dfs(child);
    }
}

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define SIZE 110
using namespace std;

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges);
void dfs(int,vector<int>&,int);
void bfs(int,vector<int>&);

vector<pair<int,int>> adj[SIZE];

int main(){
    vector<vector<int>> edges={{0,2,6},{0,3,7},{0,4,9},{0,6,8},{0,7,6},{1,2,6},{1,3,7},{1,5,10},{1,6,1},{1,7,4},{2,3,3},{2,6,10},{2,8,8},{2,9,10},{3,5,3},{3,6,10},{3,7,5},{5,6,9},{5,7,7},{6,7,7},{6,8,8},{6,9,8},{7,9,1},{8,9,6}};
    vector<int> ans;
    ans=shortestPath(10,24,edges);
    return 0;
}
vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    vector<int> ans(N,INT_MAX);       //ans[i]=>min distance from root  form (0,INT_MAX),(1,INT_MAX),....,

    for(int i=0;i<M;i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});      //adj form: (child,distance);
    }
    //dfs(0,ans,0);
    bfs(0,ans);

    //check if there exists any node with INT_MAX as distance => isolated node in which case we make distance -1
    for(int i=0;i<N;i++){
        if(ans[i]==INT_MAX)
            ans[i]=-1;
    }

    for(auto val:ans)
        cout<<val<<",";
    cout<<endl;

    return ans;
}
void dfs(int vertex,vector<int>& ans,int d){
    //we do not keep a visited array since we need to find the minimum distance of each node from root 
    // and there could be same need being connected to more than one other nodes
    ans[vertex]=min(ans[vertex],d);

    for(auto child:adj[vertex]){
        dfs(child.first,ans,d+child.second);
    }
}
void bfs(int vertex,vector<int>& ans){
    queue<pair<int,int>> q;
    q.push({vertex,0});

    while (not(q.empty()))
    {
        int v=q.front().first;
        int d=q.front().second;
        ans[v]=min(ans[v],d);
        q.pop();

        for(auto child:adj[v]){
            q.push({child.first,child.second+d});
        }
    }
}   
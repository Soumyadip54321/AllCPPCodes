#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int n=1e4+10;
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end);
vector<pair<int,double>> adjlist[n];
void dfs(int,int,double);
bool visited[n];
double maxprob=0.0;

int main(){
    vector<vector<int>> edges={{0,1},{0,2},{1,2}};
    vector<double> succProb={0.5,0.3,0.5};
    cout<<maxProbability(3,edges,succProb,0,2);
    return 0;
}
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end){
    //n=>number of vertices
    double prob=1.0;
    for(int i=0;i<edges.size();i++){
        adjlist[edges[i][0]].push_back({edges[i][1],succProb[i]});
        //adjlist[edges[i][1]].push_back({edges[i][0],succProb[i]});
    }

    //display adjlist
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto vertices:adjlist[i])
            cout<<vertices.first<<":"<<vertices.second<<",";
        cout<<endl;
    }

    dfs(start,end,prob);
    //visited[start]=true;
    return maxprob;
}
void dfs(int stvertex,int endvertex,double prob){
    if(stvertex==endvertex){
        maxprob=max(maxprob,prob);
        return;
    }

    //visited[stvertex]=true;

    for(auto child:adjlist[stvertex]){
        // if(visited[child.first])
        //     continue;
        dfs(child.first,endvertex,prob*child.second);
    }
}
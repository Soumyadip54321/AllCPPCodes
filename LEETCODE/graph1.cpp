#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges);
void dfs(int,int);
const int n=1e5+10;
vector<int> adjlist[n];
bool visited[n];
int indegreect[n];

int main(){
    vector<vector<int>> edges={{0,1},{2,1},{3,1},{1,4},{2,4}};
    vector<int> smallestset;
    smallestset=findSmallestSetOfVertices(5,edges);

    for(auto vert: smallestset)
        cout<<vert<<" ";
    cout<<endl;
    return 0;
}
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges){
    vector<int> smallestsetofvert;
    /*we create the adj list here*/

    /*----------------------Method-I: perform DFS on graph and mark only those vertices which are reachable-------------------------------------------------------------*/
    for(int i=0;i<edges.size();i++){
        adjlist[edges[i][0]].push_back(edges[i][1]);
    }
    /*here the idea is when we visit a node we mark it and we visit the node sequentially from 0 - n-1*/
    /*the parent node we visit from we keep it unmarked such that it signifies nodes which are unvisited from any other*/
    dfs(0,n);
    for(int i=0;i<n;i++){
        cout<<visited[i]<<endl;
        if(visited[i]==0)       /*these nodes remain unvisited or cannot be reached from other nodes*/
            smallestsetofvert.push_back(i);
    }

    /*----------------------Method-II count indegree-------------------------------------------------------------*/
    for(int i=0;i<edges.size();i++)
        indegreect[edges[i][1]]++;
    
    /*next we look for those vertices with indegree 0*/
    for(int i=0;i<n;i++){
        if(indegreect[i]==0)
            smallestsetofvert.push_back(i);
    }
    /*-------------------------------------------------------------------------------------------------------------*/
    return smallestsetofvert;
}
void dfs(int vertex,int n){

    for(auto child:adjlist[vertex]){
        if(visited[child])
            continue;
        visited[child]=true;
    }
    if(vertex+1<n)
        dfs(vertex+1,n);
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph);
bool bfs(int,vector<vector<int>>,int*);

int main(){
    vector<vector<int>> graph={{2,4,6},{},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    cout<<isBipartite(graph)<<endl;
    return 0;
}
bool isBipartite(vector<vector<int>>& graph){
    int *color = new int[graph.size()];
    for(int i=0;i<graph.size();i++)
        color[i]=-1;
    return bfs(0,graph,color);
}
bool bfs(int vertex,vector<vector<int>> graph,int* color){
    queue<int> q;
    color[vertex]=0;        /*here 0->red, 1->blue*/
    q.push(vertex);

    if(graph[vertex].empty()){
        if(vertex+1<graph.size())
            return bfs(vertex+1,graph,color);
        return true;
    }

    while (not(q.empty()))
    {
        int vertex=q.front();
        q.pop();

        for(auto child:graph[vertex]){
            if(color[child]==-1){
                if(color[vertex]==0)
                    color[child]=1;
                else if(color[vertex]==1)
                    color[child]=0;
                q.push(child);
            }
            else if(color[vertex]!=color[child])
                continue;
            else
                return false;
        }
    }
    return true;
}
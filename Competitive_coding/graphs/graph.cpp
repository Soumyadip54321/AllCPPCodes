#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

bool dfs(int,int);
const int N=1e3+10;
int graph1[N][N];

vector<int> graph2[N];      //adjacency list of graph
bool visited[N];
vector<vector<int>> connected_components;
vector<int> current_cc;

int main(){
    int m,n;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin >> v1 >> v2;
        graph2[v1].push_back(v2);           //adjacency list space complexity - O(V+E)
        graph2[v2].push_back(v1);
    }

    // for(int i=0;i<n;i++){
    //     for(auto item:graph2[i])
    //         cout<<item<<" ";
    //     cout<<endl;
    // }
    int ct=0;       //count of connected components
    bool isloopexists=false;

    for(int i=1;i<n;i++){
        if(visited[i]){
            // current_cc.clear();
            continue;
        }
        isloopexists|=dfs(i,0);
        if(isloopexists)
            break;
        // connected_components.push_back(current_cc);
        // ct++;
    }
    cout<<"is there cycle in the graph? "<<isloopexists<<endl;
    // cout<<"number of connected components is: "<<ct<<endl;

    // for(int i=0;i<connected_components.size();i++){
    //     for(auto item:connected_components[i])
    //         cout<<item<<"->";
    //     cout<<endl;
    // }
    //to detect cycle in a graph we ignore the vertex we arrived from ie the parent but in the event we visit a child node
    //already visited previously we say there exists a cycle.
    return 0;
}
bool dfs(int vertex,int parent){
    visited[vertex]=true;
    //current_cc.push_back(vertex);
    bool isloopexists=false;

    for(auto child:graph2[vertex]){
        if(visited[child] && child==parent)
            continue;

        if(visited[child])
            return true;
        isloopexists|=dfs(child, vertex);
    }
    return isloopexists;
}


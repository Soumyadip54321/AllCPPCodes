#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void creategraph(vector<vector<int>>,int);
void bfs(int);
void dfs(int);

const int n=1e5+10;
vector<int> adjlist[n];
int visited[n];


int main(){
    vector<vector<int>> edges={{1,2},{1,3},{3,4},{3,7},{4,8},{8,7},{2,5},{2,6}};
    int v=8;
    creategraph(edges,v);
    return 0;
}
void creategraph(vector<vector<int>> edges,int n){

    for(int i=0;i<edges.size();i++){
        adjlist[edges[i][0]].push_back(edges[i][1]);
        adjlist[edges[i][1]].push_back(edges[i][0]);
    }

    for(int i=1;i<=n;i++){
        for(auto vertex:adjlist[i])
            cout<<vertex<<",";
        cout<<endl;
    }
    //bfs(1);
    dfs(1);
}
void bfs(int vertex){
    queue<int> q;
    q.push(vertex);

    while(not(q.empty())){
        visited[q.front()]=1;
        cout<<q.front()<<" ";

        for(auto child:adjlist[q.front()]){
            if(visited[child]==1)
                continue;
            q.push(child);
        }
        q.pop();
    }
}
void dfs(int vertex){
    visited[vertex]=1;
    cout<<" parent: "<<vertex;

    for(auto child:adjlist[vertex]){
        if(visited[child]==1)
            continue;
        cout<<" child: "<<child<<endl;
        dfs(child);
    }

    cout<<" "<<vertex<<" exits"<<endl;
}

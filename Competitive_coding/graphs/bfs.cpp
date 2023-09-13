#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void bfs(int,queue<int>);
const int N=1e3+10;
vector<int> graph[N];       //adj list of graph
bool visited[N];
int level[N];

int main(){
    int n;
    queue<int> q;

    cin>>n;
    for(int i=0;i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;            //taking vertices with edge between
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i=1;i<=n;i++){
        for(auto item:graph[i])
            cout<<item<<" ";
        cout<<endl;
    }   
    
    q.push(1);          //putting in queue the starting vertex
    level[1]=1;
    bfs(1,q);

    //display level array
    for(int i=1;i<=n;i++)
        cout<<i<<":"<<level[i]<<endl;
    return 0;
}
void bfs(int vertex,queue<int> q){
    visited[vertex]=1;          //after entering vertex section
    cout<<q.front()<<endl;
    q.pop();

    for(auto child:graph[vertex]){
        if(visited[child])
            continue;
        level[child]=level[vertex]+1;
        q.push(child);
    }
    if(not(q.empty()))
        bfs(q.front(),q);            //exiting vertex section
    return;                         //when queue empty return


    /*method-II*/
    // visited[vertex]=true;
    // queue<int> q;
    // q.push(vertex);

    // while(not(q.empty())){
    //     int curr_v=q.front();
    //     q.pop();
    //     cout<<curr_v<<" ";
    //     for(auto child:graph[curr_v]){
    //         if(not(visited[child])){
    //             q.push(child);
    //             level[child]=1+level[curr_v];
    //         }
    //     }
    // }
    // cout<<endl;
}
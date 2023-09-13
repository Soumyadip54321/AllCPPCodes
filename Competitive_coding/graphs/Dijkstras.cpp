#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void dijkstras(int,int);

const int N=1e5+10;
const int INF=1e9+10;

vector<pair<int,int>> g[N];

vector<int> vis(N,0);


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        g[v1].push_back({v2,wt});
    }
    dijkstras(1,n);
    return 0;
}
void dijkstras(int source,int n){
    int min_distance=-1;
    vector<int> distance(N,INF);
    /*here we use set instead of priority queue which does the same thing to help you pick optimally the node with minimum distance from root*/
    /*But keep pai in the form of (wt,vertex) to help you insert elements in increasing order of wt/distance*/
    set<pair<int,int>> st;
    st.insert({0,source});
    distance[source]=0;

    while(st.size()>0){
        auto node=*st.begin();
        int v=node.second;
        int dist=node.first;
        st.erase(st.begin()); 

        if(vis[v])
            continue;
        vis[v]=1;
        for(auto child:g[v]){
            int child_v=child.first;
            int wt=child.second;
             
             if(distance[v]+wt<distance[child_v]){
                distance[child_v]=distance[v]+wt;
                st.insert({distance[child_v],child_v});
             }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<distance[i]<<endl;
}

//dijkstra's algorithm kas T(N)=O(V+ELogV)
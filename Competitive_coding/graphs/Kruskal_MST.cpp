#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int N=1e5+10;
int parent[N];
int SIZE[N];

void make(int);
int find(int);
void Union(int,int);


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++)
        make(i);

    int total_cost=0;
    for(auto edge:edges){
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u)==find(v))
            continue;
        Union(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost<<endl;
    return 0;
}
void make(int v){
    parent[v]=v;
    SIZE[v]=1;
}
int find(int v){
    if(parent[v]==v)
        return v;
    
    while (parent[v]!=v)
        v=parent[v];
    return v;
} 
void Union(int a,int b){
    a=find(a);          //returns the root of the groups
    b=find(b);
    if(a!=b){
        if(SIZE[a]<SIZE[b])
            swap(a,b);
        parent[b]=a;
        SIZE[a]+=SIZE[b];
    }
}
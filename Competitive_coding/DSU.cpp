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
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        make(i);
    }
        while (k--)
        {
            int u,v;    //invasions
            cin>>u>>v;
            Union(u,v);
        }
        
        int connected_ct=0;
        for(int i=1;i<=n;i++){
            if(find(i)==i)
                connected_ct++;
        }
    cout<<connected_ct<<endl;
    return 0;
}
void make(int v){
    parent[v]=v;
    SIZE[v]=1;
}
int find(int v){
    if(parent[v]==v)
        return v;
    return parent[v]=find(parent[v]);
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

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

int maximumDetonation(vector<vector<int>>& bombs);
double distance(int,int,int,int);
int bfs(int,vector<vector<int>>);

const int n=1e5+10;
vector<int> adjlist[n];
bool visited[n];


int main(){
    vector<vector<int>> bombs={{1,1,100000},{1,1,100000}};
    cout<<maximumDetonation(bombs)<<endl;
    return 0;
}
int maximumDetonation(vector<vector<int>>& bombs){
    /*we first sort bombs basis distance from origin*/
    int maxdetonated=-1;
    sort(bombs.begin(),bombs.end());

    /*next we set up the adj mtx where entries indicate whether a bomb detonates another*/
    /*for each we find distance from other bombs and if distance <=radii we include them in adjlist*/
    for(int i=0;i<bombs.size();i++){
        for(int j=0;j<bombs.size();j++){
            if(i==j)
                continue;
            if(distance(bombs[i][0],bombs[i][1],bombs[j][0],bombs[j][1])<=bombs[i][2])
                adjlist[i].push_back(j);
        }
    }
    for(int i=0;i<bombs.size();i++){
        cout<<"{";
        for(auto val:adjlist[i])
            cout<<val<<" ";
        cout<<"}"<<endl;
    }
    /*now we find the maximum path*
    hence we run bfs on each node finding the maximum bombs detonated*/
    for(int i=0;i<bombs.size();i++){
        maxdetonated=max(maxdetonated,bfs(i,bombs));
    }
    return maxdetonated;
}
double distance(int x1,int y1,int x2,int y2){
    long long int delx=(x1-x2);
    long long int dely=(y1-y2);
    return sqrt(delx*delx+dely*dely);
}
int bfs(int bomb,vector<vector<int>> bombs){
    int bombsdetonated=0;
    queue<int> q;

    for(int i=0;i<bombs.size();i++)
        visited[i]=false;
    visited[bomb]=true;

    q.push(bomb);

    while (not(q.empty()))
    {
        int b=q.front();
        q.pop();
        for(auto child:adjlist[b]){
            if(visited[child]==false){
                visited[child]=true;
                q.push(child);
                bombsdetonated++;
            }
        }
    }
    return bombsdetonated+1;
}
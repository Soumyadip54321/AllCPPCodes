#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y);
int bfs(vector<vector<int>>,int,int);
void shortpathdp(vector<vector<int>>,int,int,int,int,int);

int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
int minpath=INT_MAX;

int main(){
    vector<vector<int>> A={{1,1,1,0},
                           {1,1,1,0},
                           {0,0,0,0}};

    cout<<shortestDistance(3,4,A,0,2)<<endl;
    return 0;
}
int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y){
    vector<vector<int>> Atemp(A.begin(),A.end());

    //idea: we run BFS and once visited a cell with 1 we mark it 0 to avoid re-visiting it from any other node
    /*
    1. at every step we keep a count implying distance
    2. First time we reach dst we return the count
    */
    // minpath=bfs(Atemp,X,Y);

    shortpathdp(Atemp,X,Y,0,0,0);
    return minpath;
}
int bfs(vector<vector<int>> mtx,int X,int Y){
    int n=mtx.size(),m=mtx[0].size();

    queue<pair<pair<int,int>,int>> q;               //form:((x,y),dist);
    q.push({{0,0},0});

    while (not(q.empty()))
    {
        int xcoord=q.front().first.first;
        int ycoord=q.front().first.second;
        int d =q.front().second;
        mtx[xcoord][ycoord]=0;
        q.pop();

        if(xcoord==X and ycoord==Y){
            return d;
        }

        for(int i=0;i<4;i++){
            if((xcoord+x[i]>=0 and xcoord+x[i]<n) and (ycoord+y[i]>=0 and ycoord+y[i]<m) and mtx[xcoord+x[i]][ycoord+y[i]]==1){
                q.push({{xcoord+x[i],ycoord+y[i]},d+1});
            }
        }
    }
    return -1;
}
void shortpathdp(vector<vector<int>> mtx,int X,int Y,int xcoord,int ycoord,int pathct){
    if(xcoord<0 or ycoord<0 or xcoord==mtx.size() or ycoord==mtx[0].size() or mtx[xcoord][ycoord]!=1)
        return;

    if(xcoord==X and ycoord==Y){
        minpath=min(minpath,pathct);
        return;
    }
    
    mtx[xcoord][ycoord]=0;

    shortpathdp(mtx,X,Y,xcoord+0,ycoord+1,pathct+1);

    shortpathdp(mtx,X,Y,xcoord+0,ycoord-1,pathct+1);

    shortpathdp(mtx,X,Y,xcoord+1,ycoord+0,pathct+1);

    shortpathdp(mtx,X,Y,xcoord-1,ycoord+0,pathct+1);
}
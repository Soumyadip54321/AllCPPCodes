#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid);
int bfs(vector<vector<int>>,int&);
bool isvalid(vector<vector<int>>,int,int);

const int n=1e5+10;
vector<int> adjmtx[n];

int main(){
    vector<vector<int>> grid={{1,2,1},{1,1,0},{0,0,1}};
    cout<<orangesRotting(grid)<<endl;
    return 0;
}
int orangesRotting(vector<vector<int>>& grid){
    int freshct=0;
    /* idea: as there can be multiple 2s to start with we capture their position in a queue and perform bfs
    we also find out number of fresh oranges present initially*/
    vector<vector<int>> dupgrid=grid;

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1)
                freshct++;
        }
    }
    return bfs(grid,freshct);
}
int bfs(vector<vector<int>> g,int& freshoranges){
    queue<pair<pair<int,int>,int>> q;
    int vis[g.size()][g[0].size()];
    int tm=0;
    /*we include all rotten oranges*/
    for(int i=0;i<g.size();i++){     
        for(int j=0;j<g[0].size();j++){
            if(g[i][j]==2){
                q.push({{i,j},0});              /*we store pair in form ((x,y),time)*/
                vis[i][j]=2;
            }
            else
                vis[i][j]=0;
        }
    }
    int drow[]={-1,0,+1,0};
    int dcol[]={0,1,0,-1};
    while (not(q.empty()))
    {   
        int t=q.front().second;
        int x=q.front().first.first;
        int y=q.front().first.second;
        tm=max(tm,t);

        for(int i=0;i<4;i++){
            int newx=x+drow[i];
            int newy=y+dcol[i];

            if(newx>=0 && newx<g.size() && newy>=0 && newy<g[0].size() && g[newx][newy]==1 && vis[newx][newy]!=2){
                q.push({{newx,newy},t+1});
                vis[newx][newy]=2;
            }
        }
        q.pop();
    }
    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[0].size();j++){
            if(vis[i][j]!=2 && g[i][j]==1)
                return -1;
        }
    }
    return tm;
}

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int numislands(vector<vector<int>>);
void dfs(int,int,vector<vector<int>>,int**);
vector<vector<int>> movement={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};       /*all possible movements*/
bool issafe(int,int,int,int);

int main(){
    vector<vector<int>> mtx={{0,1},{1,0},{1,1},{1,0}};
    cout<<numislands(mtx)<<endl;
    return 0;
}
int numislands(vector<vector<int>> adjmtx){
    int islandcount=0;
    int **visited,sx=adjmtx.size(),sy=adjmtx[0].size();

    visited=new int*[sx];
    if(visited==nullptr)
        exit(-1);
    
    for(int i=0;i<sx;i++){
        visited[i]=new int[sy];
        for(int j=0;j<sy;j++)
            visited[i][j]=0;
    }

    for(int i=0;i<adjmtx.size();i++){
        for(int j=0;j<adjmtx[0].size();j++){
            if(visited[i][j]!=1 && adjmtx[i][j]==1){
                dfs(i,j,adjmtx,visited);
                islandcount++;
            }
        }
    }
    return islandcount;
}
void dfs(int x,int y,vector<vector<int>> adjmtx,int** visited){
    visited[x][y]=1;

    for(int i=0;i<movement.size();i++){
        if(issafe(x+movement[i][0],y+movement[i][1],adjmtx.size(),adjmtx[0].size()) && adjmtx[x+movement[i][0]][y+movement[i][1]]==1 && visited[x+movement[i][0]][y+movement[i][1]]!=1)
            dfs(x+movement[i][0],y+movement[i][1],adjmtx,visited);
    }
}
bool issafe(int x,int y,int sx,int sy){
    if((x>=0 && x<sx) && (y>=0 && y<sy))
        return true;
    return false;
}
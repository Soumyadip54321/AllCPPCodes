#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid);
int bfs(vector<vector<int>>,int,int);

bool visited[100][100];

int main(){
    vector<vector<int>> grid={{0,0,0},{1,1,0},{1,1,0}};
    cout<<shortestPathBinaryMatrix(grid)<<endl;
    return 0;
}
int shortestPathBinaryMatrix(vector<vector<int>>& grid){
    /*idea: we apply either dfs/bfs to compute all possible path lengths and then select the minimum through zeros
    from each zeros we compute length to the end zero and return the minimum*/
    return bfs(grid,0,0);
}
int bfs(vector<vector<int>> grid,int x,int y){
    queue<pair<pair<int,int>,int>> q;                   /*q has elements of form((x,y),length_of_path)*/
    vector<pair<int,int>> movement={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

    if(grid[0][0]==1)
        return -1;
    if(grid[0][0]==0 && grid.size()==1 && grid[0].size()==1)
        return 1;

    q.push({{0,0},1});
    visited[0][0]=true;

    while (not(q.empty()))
    {
        int lengthofpath=q.front().second;
        
        for(auto neigbours:movement){
            int newx= neigbours.first+x;
            int newy=neigbours.second+y;

            if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && grid[newx][newy]==0 && !visited[newx][newy]){

                    q.push({{newx,newy},lengthofpath+1});
                    visited[newx][newy] = true;
                    
                    if(newx==grid.size()-1 && newy==grid[0].size()-1)
                     return lengthofpath+1;
            }
        }
        q.pop();
    }
    return -1;
}

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int latestDayToCross(int row, int col, vector<vector<int>>& cells);
bool bfs(vector<vector<int>>&);

int main(){
    vector<vector<int>> cells={{4,2},{6,2},{2,1},{4,1},{6,1},{3,1},{2,2},{3,2},{1,1},{5,1},{5,2},{1,2}};
    cout<<latestDayToCross(6,2,cells);
    return 0;
}
int latestDayToCross(int row, int col, vector<vector<int>>& cells){
    //we create the cell at first
    //0=> land, 1=>water

    vector<vector<int>> mtx;
    vector<int> value(col,1);
    int lastdaytocross=cells.size();
    bool landfoundinfirstrow=false;
    

    for(int i=0;i<row;i++)
        mtx.push_back(value);
    
    /*idea:
    1. we apply bfs every day the landscape changes to check if its possible to reach the final row starting at the top
    2. The point when its no longer possible we exit
    */

    //we start from the back
    for(int i=cells.size()-1;i>=0;i--){

        mtx[cells[i][0]-1][cells[i][1]-1]=0;

        if(cells[i][0]-1==0 || landfoundinfirstrow){
            if(bfs(mtx)){
                lastdaytocross--;
                return lastdaytocross;
            }
            landfoundinfirstrow=true;
        }
            lastdaytocross--;
    }
    return -1;
}
bool bfs(vector<vector<int>>& landscape){
    queue<pair<int,int>> coordinate;
    vector<vector<int>> visited=landscape;

    for(int c=0;c<landscape[0].size();c++){
        if(landscape[0][c]==0){
            coordinate.push({0,c});
            visited[0][c]=-1;
        }
    }
    if(coordinate.empty())
        return false;
    
    int rdir[]={0,0,-1,1};
    int cdir[]={1,-1,0,0};

    while (not(coordinate.empty()))
    {
        int rpos=coordinate.front().first;
        int cpos=coordinate.front().second;
        coordinate.pop();

        if(rpos==landscape.size()-1)
            return true;

        for(int i=0;i<4;i++){
            if((rpos+rdir[i]>=0 && rpos+rdir[i]<=landscape.size()-1) && (cpos+cdir[i]>=0 && cpos+cdir[i]<=landscape[0].size()-1) && landscape[rpos+rdir[i]][cpos+cdir[i]]==0 && visited[rpos+rdir[i]][cpos+cdir[i]]!=-1){
                coordinate.push({rpos+rdir[i],cpos+cdir[i]});
            }
        }
    }
    return false;
}
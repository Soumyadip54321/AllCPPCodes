#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);
void bfs(int,int,int,vector<vector<int>>&,vector<vector<int>>&,int);
bool isSafe(int,int,int,int);
vector<vector<int>> movement={{0,1},{0,-1},{1,0},{-1,0}};

int main(){
    vector<vector<int>> image={{2,1,2,1,3},{2,3,3,3,2},{2,3,1,3,2},{1,2,3,2,2}},new_img;
    new_img=floodFill(image,0,0,1);
    return 0;
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
    /*here we apply either bfs/dfs and color all connected nodes in the image to start node with color newColor*/
    vector<vector<int>> ans=image;
    int initcolor=image[sr][sc];

    bfs(sr,sc,newColor,image,ans,initcolor);

    // for(int i=0;i<image.size();i++){
    //     cout<<"{";
    //     for(auto rowpx:ans[i])
    //         cout<<rowpx<<" ";
    //     cout<<"}"<<endl;
    // }
    return ans;
}
void bfs(int x,int y,int newcolor,vector<vector<int>>& image,vector<vector<int>>& ans,int initcolor){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while (not(q.empty()))
    {
        ans[q.front().first][q.front().second]=newcolor;
        for(int i=0;i<movement.size();i++){
            if(isSafe(q.front().first+movement[i][0],q.front().second+movement[i][1],image.size(),image[0].size()) && ans[q.front().first+movement[i][0]][q.front().second+movement[i][1]]==initcolor && ans[q.front().first+movement[i][0]][q.front().second+movement[i][1]]!=newcolor){
                q.push(make_pair(q.front().first+movement[i][0],q.front().second+movement[i][1]));
            }
        }
        q.pop();
    }
}   
bool isSafe(int x,int y,int sx,int sy){
    if((x>=0 && x<sx) && (y>=0 && y<sy))
        return true;
    return false;
}
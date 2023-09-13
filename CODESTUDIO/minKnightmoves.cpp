#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int minimumKnightMoves(int x, int y);
vector<vector<int>> moves={{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};

int main(){
    cout<<minimumKnightMoves(5,12);
    return 0;
}
int minimumKnightMoves(int x, int y){
    /*
    idea:
    1. we apply BFS that yields the shortest path in an unweighted graph
    */
   queue<pair<int,pair<int,int>>> q;
   q.push({0,{0,0}});

   while (not(q.empty()))
   {    int xcoord=q.front().second.first;
        int ycoord=q.front().second.second;
        int move=q.front().first;

        if(xcoord==x && ycoord==y)
            return move;

        q.pop();

        // for(auto val:moves){
        //     q.push({move+1,{xcoord+val[0],ycoord+val[1]}});
        // }
        q.push({move+1,{xcoord+2,ycoord+1}});
        q.push({move+1,{xcoord+2,ycoord-1}});
        q.push({move+1,{xcoord+1,ycoord+2}});
        q.push({move+1,{xcoord+1,ycoord-2}});
        q.push({move+1,{xcoord-1,ycoord+2}});
        q.push({move+1,{xcoord-1,ycoord-2}});
        q.push({move+1,{xcoord-2,ycoord+1}});
        q.push({move+1,{xcoord-2,ycoord-1}});

   }
   return -1;
}
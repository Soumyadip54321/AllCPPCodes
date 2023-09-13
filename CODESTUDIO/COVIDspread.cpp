#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int covidSpread(vector<vector<int>> &houses);

int main(){
    vector<vector<int>> houses={{2,1,1},{1,1,0},{0,1,1}};
    cout<<covidSpread(houses);
    return 0;
}
int covidSpread(vector<vector<int>> &houses){
    /*
    idea:
    1. here we apply BFS 
    */
   queue<pair<pair<int,int>,int>> q;
   vector<vector<int>> duphouses=houses;
   int mindaystospread=-1;

   for(int r=0;r<houses.size();r++){
    for(int c=0;c<houses[0].size();c++){
        if(houses[r][c]==2){
            q.push({{r,c},0});
        }
    }
   }
   int xdir[]={1,-1,0,0};
   int ydir[]={0,0,1,-1};

   while (not(q.empty()))
   {
        pair<pair<int,int>,int> p=q.front();
        mindaystospread=max(mindaystospread,q.front().second);
        q.pop();

        for(int i=0;i<4;i++){
            if((p.first.first+xdir[i]>=0 && p.first.first+xdir[i]<houses.size()) && (p.first.second+ydir[i]>=0 && p.first.second+ydir[i]<houses[0].size()) && duphouses[p.first.first+xdir[i]][p.first.second+ydir[i]]==1){
                q.push({{p.first.first+xdir[i],p.first.second+ydir[i]},p.second+1});
                duphouses[p.first.first+xdir[i]][p.first.second+ydir[i]]=2;
            }
        }
   }
//    for(int r=0;r<duphouses.size();r++){
//     for(int c=0;c<duphouses[0].size();c++){
//         cout<<duphouses[r][c]<<",";
//     }
//     cout<<endl;
//    }

   for(int r=0;r<duphouses.size();r++){
    for(int c=0;c<duphouses[0].size();c++){
        if(duphouses[r][c]==1)
            return -1;
    }
   }
   return mindaystospread;
}
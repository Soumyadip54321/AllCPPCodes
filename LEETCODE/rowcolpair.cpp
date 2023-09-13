#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int equalPairs(vector<vector<int>>& grid);
int computeequality(vector<vector<int>>,int);



int main(){
    vector<vector<int>> grid={{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    cout<<equalPairs(grid)<<endl;
    return 0;
}
int equalPairs(vector<vector<int>>& grid){
    if(grid.size()==1)
        return 1;

    int ep=0;
    for(int i=0;i<grid.size();i++)
        ep+=computeequality(grid,i);
    return ep;
    /*---------------TC = O(N^3)------------------------*/

    /*
    -----------------TC=O(N^2) solution with unordered map
    */
   unordered_map<string,int> m;
   int samect=0;

   for(int i=0;i<grid.size();i++){
        string ans="";
        for(int j=0;j<grid.size();j++){
            ans+=grid[i][j]+'0';
        }
        m[ans]++;
   }

   for(int i=0;i<grid.size();i++){
    string ans="";
        for(int j=0;j<grid.size();j++){
            ans+=grid[j][i]+'0';
        }
        samect+=m[ans];
   }

   for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<":"<<it->second<<" ";
    return samect;
}
int computeequality(vector<vector<int>> grid,int idx){
    int samepairs=0;

    for(int i=0;i<grid.size();i++){
        bool same= true;
        for(int j=0;j<grid.size();j++){
            if(grid[j][i]!=grid[idx][j]){
                same=false;
                break;
            }
        }
        if(same)
            samepairs++;
    }
    return samepairs;
}
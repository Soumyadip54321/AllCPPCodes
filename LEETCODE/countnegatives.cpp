#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int countNegatives(vector<vector<int>>& grid);


int main(){
    vector<vector<int>> grid={{3,2},{1,0}};
    cout<<countNegatives(grid)<<endl;
    return 0;
}
int countNegatives(vector<vector<int>>& grid){

    /*naive approach:
    1. we cheack each entry of the matrix
    2. increase count of negative if any entry is <0
    */

   int rownum=0,colnum=0,negct=0;

   while (rownum<grid.size())
   {
        if(colnum==grid[0].size()){
            rownum++;
            colnum=0;
            continue;
        }
        
        if(grid[rownum][colnum]<0)
            negct++;
        colnum++;
   }
   return negct;
}
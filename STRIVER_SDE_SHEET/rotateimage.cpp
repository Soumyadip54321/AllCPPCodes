#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
void rotate(vector<vector<int>>& matrix);

int main(){
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotate(matrix);
    return 0;
}
void rotate(vector<vector<int>>& matrix){
    //rotation by 90 deg is just the opposite of transpose
    /*
    idea:
    1. 1st row becomes last col,2nd becomes 2nd last col and so on
    */

   
   int m=matrix.size();
   int rh=0,rl=m-1,cl=0,ch=m-1;

   while (cl<ch && rh<rl)
   {
        //first we swap the corner elements
        swap(matrix[rh][cl],matrix[rh][ch]);
        swap(matrix[rl][cl],matrix[rl][ch]);
        swap(matrix[rh][cl],matrix[rl][ch]);

        int p2=cl+1,p1=rl-1;

        while (p1>rh)
        {
            swap(matrix[p1][cl],matrix[rh][p2]);
            p1--;
            p2++;
        }

        p1=rh+1;
        p2=rl-1;

        while (p1<rl)
        {
            swap(matrix[p1][cl],matrix[p2][ch]);
            p1++;p2--;
        }
        p1=rh+1;
        p2=cl+1;

        while (p1<rl)
        {
            swap(matrix[p1][cl],matrix[rl][p2]);
            p1++;
            p2++;
        }

        cl++;ch--;
        rh++;rl--;
   }

   //display matrix
    for(int i=0;i<m;i++){
        for(auto val:matrix[i])
            cout<<val<<",";
        cout<<endl;
    }
    //TC=O(MN)
}
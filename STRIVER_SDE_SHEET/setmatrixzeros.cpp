#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 250
using namespace std;

void setZeroes(vector<vector<int>>& matrix);

int main(){
    vector<vector<int>> matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    return 0;
}
 void setZeroes(vector<vector<int>>& matrix){
   int m=matrix.size(),n=matrix[0].size();

   /*------------------------METHOD-I (BRUTE FORCE)  TC=O(n^3) & SC=O(1)------------------------------------------------*/
    
    for(int r=0;r<m;r++){                   //TC=O(mn)*O(m+n)=O(mn(m+n))=O(n^3)        SC=O(1)
        for(int c=0;c<n;c++){
            if(matrix[r][c]==0){
                //mark all non-zero elements -1 along row and col

                //row-wise rightward
                int col=c+1;
                while (col<n)                       //TC=O(n+m)
                {
                    if(matrix[r][col]!=0)
                        matrix[r][col]=INT_MAX;
                    col++;
                }

                //row-wise left
                col=c-1;
                while (col>=0)
                {
                    if(matrix[r][col]!=0)
                        matrix[r][col]=INT_MAX;
                    col--;
                }

                //col-wise downward
                int row=r+1;
                while (row<m)                   
                {
                    if(matrix[row][c]!=0)
                        matrix[row][c]=INT_MAX;
                    row++;
                }

                //col-wise upward
                row=r-1;
                while (row>=0)
                {
                    if(matrix[row][c]!=0)
                        matrix[row][c]=INT_MAX;
                    row--;
                }
            }
                
        }
    }

    for(int r=0;r<m;r++){
        for(int c=0;c<n;c++)
            if(matrix[r][c]==INT_MAX)
                matrix[r][c]=0;
    }

    /*----------------METHOD-II(BETTER APPROACH) TC=O(n^2) & SC=O(m+n)----------------------------------*/

    /*
    idea:
    1. we keep arrays of sizes m and n initially set to zero 
    2. The arrays depict whether there exists a zero at a specific location
    */

   vector<int> colarr(n,0); //SC=O(m+n)
   vector<int> rowarr(m,0);

    for(int r=0;r<m;r++){
        for(int c=0;c<n;c++){
            if(matrix[r][c]==0){
                colarr[c]=1;
                rowarr[r]=1;
            }
        }   
    }

    for(int i=0;i<n;i++){       //TC=O(nm)
        if(colarr[i]==1){
            for(int r=0;r<m;r++){
                matrix[r][i]=0;
            }
        }
    }

    for(int i=0;i<m;i++){       //TC=O(nm)
        if(rowarr[i]==1){
            for(int c=0;c<n;c++){
                matrix[i][c]=0;
            }
        }
    }

    for(int r=0;r<m;r++){
        cout<<"{";
        for(int c=0;c<n;c++)
            cout<<matrix[r][c]<<",";
        cout<<"}"<<endl;
    }
 }
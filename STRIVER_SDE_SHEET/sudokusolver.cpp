#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define N 9
using namespace std;

bool SolveSudoku(int grid[N][N]);
bool ispossible(int grid[N][N],int,int,int);        //helper function to check if an empty cell is filled with a digit whether it satisfies all 3 rules of sudoku
void printGrid (int grid[N][N]) ;
unordered_map<int,bool> mpp={{1,false},{2,false},{3,false},{4,false},{5,false},{6,false},{7,false},{8,false},{9,false}};

int main(){
    int grid[N][N]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if(SolveSudoku(grid))
        printGrid(grid);

    // SolveSudoku(grid);
    // printGrid(grid);

    return 0;
}
bool SolveSudoku(int grid[N][N]){
    for(int r=0;r<N;r++){
        for(int c=0;c<N;c++){
            if(grid[r][c]==0){
                for(int num=1;num<=9;num++){
                    if(ispossible(grid,r,c,num)){
                        grid[r][c]=num;

                        if(SolveSudoku(grid))
                            return true;
                        else
                            grid[r][c]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool ispossible(int grid[N][N],int row,int col,int num){

    //row,col and box check
    for(int i=0;i<N;i++){
        if(grid[row][i]==num)
            return false;
        if(grid[i][col]==num)
            return false;
        
        if(grid[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==num)
            return false;
    }
    return true;
}
void printGrid (int grid[N][N]) {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<grid[i][j]<<",";
        cout<<endl;
    }
}
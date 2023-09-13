#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<char>> solveNQueens(int n);
bool placequeens(vector<vector<char>>&,int);
bool canplace(vector<vector<char>>&,int,int);
void displayboard(vector<vector<char>>&);

int main(){
    vector<vector<char>> finalboard;
    finalboard=solveNQueens(4);
    return 0;
}
vector<vector<char>> solveNQueens(int n){
    //first set the board up
    vector<vector<char>> board;
    int fr,fc;

    for(int r=0;r<n;r++){
        vector<char> cells;
        for(int c=0;c<n;c++)
            cells.push_back('.');
        board.push_back(cells);
    }
    //display board
    //displayboard(board);

    if(placequeens(board,0))
        displayboard(board);
    return board;
}
bool placequeens(vector<vector<char>>& board,int row){
    if(row==board.size())
        return true;

    for(int col=0;col<board.size();col++){
        if(canplace(board,row,col)){
            board[row][col]='Q';

            if(placequeens(board,row+1))
                return true;
            else
                board[row][col]='.';
        }
    }
    return false;
}
bool canplace(vector<vector<char>>& board,int r,int c){
    //check top
    for(int i=0;i<r;i++){
        if(board[i][c]=='Q')
            return false;
    }
    int row=r-1;
    int col=c+1;
    //check right dia
    while (col<board.size() and row>=0)
    {
        if(board[row][col]=='Q')
            return false;
        row--;
        col++;
    }
    
    row=r-1;
    col=c-1;
    //check left dia
    while (col<board.size() and row>=0)
    {
        if(board[row][col]=='Q')
            return false;
        row--;
        col--;
    }
    return true;
}
void displayboard(vector<vector<char>>& board){
    for(int r=0;r<board.size();r++){
        cout<<"{";
        for(int c=0;c<board.size();c++){
            cout<<board[r][c]<<",";
        }
        cout<<"}"<<endl;
    }
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define SIZE 3
using namespace std;

string ticTacToeWinner(vector<vector<int>> moves, int n);
char checkwinner(vector<vector<char>>&);
void displaygrid(vector<vector<char>>&);

int main(){
    vector<vector<int>> moves={{0,0},{1,1},{2,2},{0,2},{1,0},{2,0}};
    cout<<ticTacToeWinner(moves,6);
    return 0;
}
string ticTacToeWinner(vector<vector<int>> moves, int n){
    /*
    idea:
    1.  we at first put the respective markers in the grid location dictated
    2.  at evry move we check whether either of 2 diagonals or 3 rows or 3 colmuns has same marker preent in which case we end 
        game and announce the winner
    3.  else we continue untill all grids been filled or all moves end whichever is earlier and set the game  "DRAWN" if all grid is filled else display
        "UNCERTAIN".  
    */
    vector<vector<char>> grid(SIZE,vector<char> (SIZE,'-'));

    for(int i=0;i<n;i++){
        if(i%2==0)
            grid[moves[i][0]][moves[i][1]]='X';
        else
            grid[moves[i][0]][moves[i][1]]='O';

        if(checkwinner(grid)=='X'){
            displaygrid(grid);
            return "player1";
        }
        else if(checkwinner(grid)=='O'){
            displaygrid(grid);
            return "player2";
        }
        
        displaygrid(grid);
    }

    //we check whether any cell is empty
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(grid[i][j]=='-')
                return "uncertain";
        }
    }
    return "draw";
}
char checkwinner(vector<vector<char>>& grid){

    //check for row
    for(int r=0;r<SIZE;r++){
        int p1ct=0,p2ct=0;
        for(int c=0;c<SIZE;c++){
            if(grid[r][c]=='X')
                p1ct++;
            else if(grid[r][c]=='O')
                p2ct++;
        }
        if(p1ct==3)
            return 'X';
        if(p2ct==3)
            return 'O';
    }

    //col check
    for(int c=0;c<SIZE;c++){
        int p1ct=0,p2ct=0;
        for(int r=0;r<SIZE;r++){
            if(grid[r][c]=='X')
                p1ct++;
            else if(grid[r][c]=='O')
                p2ct++;
        }
        if(p1ct==3)
            return 'X';
        if(p2ct==3)
            return 'O';
    }

    //right dia check
    int p1ct=0,p2ct=0;
    for(int c=0;c<SIZE;c++){
        if(grid[c][c]=='X')
            p1ct++;
        else if(grid[c][c]=='O')
            p2ct++;
    }
    if(p1ct==3)
        return 'X';
    if(p2ct==3)
        return 'O';
    
    //left dia check
    p1ct=0,p2ct=0;
    for(int r=0;r<SIZE;r++){
        if(grid[r][SIZE-r-1]=='X')
            p1ct++;
        else if(grid[r][SIZE-r-1]=='O')
            p2ct++;
    }
    if(p1ct==3)
        return 'X';
    if(p2ct==3)
        return 'O';
    return ' ';
}
void displaygrid(vector<vector<char>>& grid){
    //display grid 
    for(int r=0;r<SIZE;r++){
        cout<<"{";
        for(int c=0;c<SIZE;c++){
            cout<<grid[r][c]<<",";
        }
        cout<<"}"<<endl;
    }
    cout<<"--------------------------------"<<endl;
}

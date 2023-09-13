#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool isSafe(int**,int,int,int);
bool nQueen(int**,int,int);


int main(){
    int n;      //board size
    cin>>n;

    int** arr=new int*[n];

    for(int i=0;i<n;i++){               //specifying all entries to be 0.
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
            arr[i][j]=0;
    }

    if(nQueen(arr,0,n)){                //display the board with Queens placed such that none attacks the other
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
bool isSafe(int** arr,int x,int y,int n){
    for(int i=0;i<x;i++){                           //check for presence of queen in the same column upwards.
        if(arr[i][y]==1)
            return false;
    }

    int row=x,col=y;
    while(row>=0 && col>=0){                        //check for any queen present in left diagonal
        if(arr[row][col]==1)
            return false;
        row--;
        col--;
    }
    row=x;
    col=y;
    while(row>=0 && col<n){                     //check for queen presence in right diagonal
        if(arr[row][col]==1)
            return false;
        row--;
        col++;
    }
    return true;
}
bool nQueen(int** arr,int x,int n){
    if(x>=n)            //base condition when all queens have been correctly placed in the board.
        return true;


    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;
            if(nQueen(arr,x+1,n))
                return true;
            arr[x][col]=0;                  //backtracking
        }
    }
    return false;
}

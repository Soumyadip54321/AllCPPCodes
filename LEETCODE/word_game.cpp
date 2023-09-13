#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

bool exist(vector<vector<char>>& board, string word);
bool check(vector<vector<char>>,int,int,int);

int visited[26];        /*contains count of letters in word*/
vector<int> colmovement={1,-1};
int rowmovement=-1;

int main(){
    vector<vector<char>> board={
                                {'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}
                                };
    string word="ABCCED";
    cout<<exist(board,word)<<endl;
    return 0;
}
bool exist(vector<vector<char>>& board, string word){
    int rows=board.size()-1,cols=board[0].size()-1;

    for(int i=0;i<word.length();i++)
        visited[word[i]-'A']++;
    
    check(board,0,rows,cols);
}
bool check(vector<vector<char>> board,int rowidx,int rows,int cols){
    for(int j=0;j<=cols;j++){
        if(visited[board[rowidx][j]]>0){
            
        }
    }
}
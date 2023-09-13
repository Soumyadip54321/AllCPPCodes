#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int maxProfit(vector<int>& prices);
int findminbuy(vector<int>&,int);
void reset();
bool isValidSudoku(vector<vector<char>>& board);
bool isValidrowcol(vector<vector<char>>&,int,int);
bool isValidgrid(vector<vector<char>>&,int,int);
void display();
set<pair<int,int>> buysell;

const int N=1e5+10;
const int INF=1e5+10;
int dp[N];
int visiteddigit[N];


int main(){
    memset(dp,-1,sizeof(dp));
    vector<vector<char>> board={{'.','.','.','1','.','8','.','.','.'},
                                {'.','.','.','.','.','.','.','.','.'},
                                {'.','.','.','.','.','.','.','.','.'},
                                {'4','.','.','.','.','7','.','.','.'},
                                {'.','.','.','7','.','.','8','4','1'},
                                {'.','.','.','.','7','.','.','.','.'},
                                {'.','.','.','.','.','.','6','.','.'},
                                {'.','.','.','6','.','.','.','.','.'},
                                {'6','.','.','.','.','.','.','.','.'}};
    vector<int> prices={7,1,5,3,6,4};
    // cout<<maxProfit(prices)<<endl;
    cout<<isValidSudoku(board)<<endl;
    return 0;
}
int maxProfit(vector<int>& prices){
    int x,max_profit=-1;
    x=findminbuy(prices,prices.size()-1);

    for(auto item:buysell){
        cout<<"("<<item.first<<","<<item.second<<")";
        if(item.second-item.first>max_profit)
            max_profit=item.second-item.first;
    }
    cout<<endl;
    return max_profit;
}
int findminbuy(vector<int>& prices,int idx){
    if(dp[idx]!=-1)
        return dp[idx];    

    int ans=prices[idx];
    for(int i=0;i<idx;i++){
            ans=min(ans,findminbuy(prices,i));
    }
    buysell.insert(make_pair(ans,prices[idx]));
    return dp[idx]=ans;
}
bool isValidSudoku(vector<vector<char>>& board){

    bool result=true;
    for(int row=0;row<board.size();row++){        //we go diagonal and check for each row and column  
        result&=isValidrowcol(board,row,row);
        if(result==false)
            return result;
    }
    // cout<<"result before grid display:"<<resultrc<<endl;
    int range=1;
    for(int row=0;row<board.size();row+=3){      //grid check row wise
        result&=isValidgrid(board,row,range);
        // cout<<"result after:"<<resultgrid<<endl;
        if(result==false){
            return result;
        }
        range++;
    }
    //cout<<"result after:"<<resultgrid<<endl;
    return true;
}
void reset(){
    for(int i=0;i<10;i++)
        visiteddigit[i]=0;
}

void display(){
    for(int i=0;i<10;i++)
        cout<<visiteddigit[i];
    cout<<endl;
}
bool isValidrowcol(vector<vector<char>>& board,int row,int col){

    for(int i=0;i<board.size();i++){ 
        if(board[row][i]=='.')
            continue;                           
        visiteddigit[board[row][i]-'0']++;
    }
    cout<<"display for row: "<<row<<endl;
    display();
    for(int i=0;i<sizeof(visiteddigit)/sizeof(int);i++){            //check for row duplicates
        if(visiteddigit[i]>=2){
            // cout<<"I returned HERE"<<endl;
            return false;
        }
    }
    // display();
    reset();
    
    for(int i=0;i<board.size();i++){ 
        if(board[i][col]=='.')
            continue;                                   
        visiteddigit[board[i][col]-'0']++;
    }
    cout<<"display for column: "<<col<<endl;
    display();

    for(int i=0;i<sizeof(visiteddigit)/sizeof(int);i++){            //check for col duplicates
        if(visiteddigit[i]>=2){
            // cout<<"I returned here"<<endl;
            return false;
        }
    }
    // display();
    reset();
    return true;
}
bool isValidgrid(vector<vector<char>>& board,int row,int range){

    for(int i=row;i<range*board.size()/3;i++){
        for(int j=3*0;j<board.size()/3;j++){
            if(board[i][j]=='.')
                continue;
            visiteddigit[board[i][j]-'0']++;
        }
    }
    cout<<"grid display: "<<row+1<<endl;
    display();
    for(int i=0;i<sizeof(visiteddigit)/sizeof(int);i++){
        if(visiteddigit[i]>=2)
            return false;
    }
    // display();
    reset();
    // display();
    for(int i=row;i<range*(board.size()/3);i++){
        for(int j=3*1;j<2*(board.size()/3);j++){
            if(board[i][j]=='.')
                continue;
            visiteddigit[board[i][j]-'0']++;
        }
    }
    cout<<"grid display: "<<row+2<<endl;
    display();
    for(int i=0;i<sizeof(visiteddigit)/sizeof(int);i++){
        if(visiteddigit[i]>=2)
            return false;
    }
    // display();
    reset();

    for(int i=row;i<range*(board.size()/3);i++){
        for(int j=3*2;j<board.size();j++){
            if(board[i][j]=='.')
                continue;
            visiteddigit[board[i][j]-'0']++;
        }
    }
    cout<<"grid display: "<<row+3<<endl;
    display();
    for(int i=0;i<sizeof(visiteddigit)/sizeof(int);i++){
        if(visiteddigit[i]>=2)
            return false;
    }
    // display();
    reset();
    return true;
}

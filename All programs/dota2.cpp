#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

string predictPartyVictory(string senate);
void senate_updates(string);
string senate_votes(string,int);
double average(vector<int>& salary);
bool isValidSudoku(vector<vector<char>>& board);
bool isSafe_colrow(int);
bool isSafe_subboxes(int);
int team_count[2];      //say 0=>radiant and 1=>dire

vector<vector<char>> board_type={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

int main(){
    string senate="DRDRR";
    vector<int> salary={1000,2000,3000};
    // cout<<predictPartyVictory(senate)<<endl;
    cout<<average(salary)<<endl;
    cout<<isValidSudoku(board_type)<<endl;
    return 0;
}
string predictPartyVictory(string senate){
    senate_updates(senate);
    return senate_votes(senate,0);
}
void senate_updates(string senate){
    for(int i=0;i<senate.length();i++){
        if(senate[i]=='R')
            team_count[0]++;
        else
            team_count[1]++;
    }
}
string senate_votes(string senate,int idx){
    if(team_count[0]==0)
        return "Dire";
    if(team_count[1]==0)
        return "Radiant";
    
    string new_senate;
    int index,checked=0;
    if(idx>senate.length()-1)
        idx=0;

    if(senate[idx]=='R'){
        team_count[1]--;                                        //radiant cancels voting right of one dire
        // int index=find(senate.begin(),senate.end(),'D')-senate.begin();        
        for(int i=idx+1;i<senate.length();i++){     //omitting from the RHS at first
            if(senate[i]=='D'){
                index=i;
                checked=1;
                break;
            }
        }
        if(checked==1)
            new_senate=senate.substr(0,index)+senate.substr(index+1);
        else{
            index=find(senate.begin(),senate.begin()+idx,'D')-senate.begin();       //omitting from LHS secondly
            new_senate=senate.substr(0,index)+senate.substr(index+1);
        }
    }
    else{
        team_count[0]--;        //dire cancels voting right of one radiant
        for(int i=idx+1;i<senate.length();i++){     ///omitting from the RHS at first
            if(senate[i]=='R'){
                index=i;
                checked=1;
                break;
            }
        }
        if(checked==1)
            new_senate=senate.substr(0,index)+senate.substr(index+1);
        else{
            index=find(senate.begin(),senate.begin()+idx,'R')-senate.begin();       //omitting from LHS secondly
            new_senate=senate.substr(0,index)+senate.substr(index+1);
        }
    }
    return senate_votes(new_senate,idx+1);
}
double average(vector<int>& salary){
    double sum=0;
    int max_salary=*max_element(salary.begin(),salary.end());
    int min_salary=*min_element(salary.begin(),salary.end());

    sum-=(max_salary+min_salary);
    for(auto item:salary)
        sum+=item;
    // double average=sum/(salary.size()-2);
    return sum/(salary.size()-2);
}
bool isValidSudoku(vector<vector<char>>& board){

}
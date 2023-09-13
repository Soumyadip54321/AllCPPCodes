#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int minTime(vector<vector<int>> &logs, int n);
vector<pair<int,int>> adjlist[200];

int main(){
    vector<vector<int>> logs={{2,0,1},{3,1,2},{1,2,3},{1,0,3}};
    cout<<minTime(logs,4);
    return 0;
}
int minTime(vector<vector<int>> &logs, int n){
    /*
    idea: 
    1. we use DFS here
    */
    for(int i=0;i<n;i++){
        adjlist[logs[i][1]].push_back({logs[i][2],logs[i][0]});
        adjlist[logs[i][2]].push_back({logs[i][1],logs[i][0]});
    }

    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto p:adjlist[i]){
            cout<<"("<<p.first<<","<<p.second<<")";
        }
        cout<<endl;
    }
    return 0;
}
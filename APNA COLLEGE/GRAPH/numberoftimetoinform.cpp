#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime);

const int n=1e5+10;
vector<int> adjlist[n];
bool visited[n];


int main(){
    vector<int> manager={1,2,-1,2,3,1,3,5,4},informTime={0,1,1,2,1,3,0,0,0};
    cout<<numOfMinutes(9,2,manager,informTime)<<endl;
    return 0;
}
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){
    queue<pair<int,int>> q;                 //q of form (emp,time)
    int totaltimetoinform=0;
    
    for(int i=0;i<manager.size();i++){          //TC=O(N)
        if(manager[i]!=-1)
            adjlist[manager[i]].push_back(i);
    }
    // for(int i=0;i<manager.size();i++){                      /*adjlist of form manager-->subordinates*/
    //     cout<<"{";
    //     for(auto subordinates:adjlist[i])
    //         cout<<subordinates<<",";
    //     cout<<"}"<<endl;
    // }
    q.push({headID,0});
    visited[headID]=true;

    while (not(q.empty()))
    {   
        int emp=q.front().first;
        // int tm=q.front().second;
        totaltimetoinform=max(totaltimetoinform,q.front().second);

        for(auto sub:adjlist[emp]){
            if(!visited[sub]){
                visited[sub]=true;
                q.push({sub,q.front().second+informTime[emp]});
            }
        }
        q.pop();
    }
    return totaltimetoinform;
}

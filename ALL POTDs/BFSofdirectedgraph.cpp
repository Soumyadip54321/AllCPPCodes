/*Here we find BFS of directed graph with possibility of vertices interconnectivity
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[]);

int main(){
    vector<int> adj[]={{0,1},{0,2},{0,4},{0,8},{1,5},{1,6},{1,9},{2,4},{3,7},{3,8},{5,8},{6,7},{6,9}};
    vector<int> ans;
    ans=bfsOfGraph(10,adj);
    return 0;
}
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,0);
        
        queue<int> q;
        vector<int> ans;
        q.push(0);
        
        visited[0]=true;
        
        while(not(q.empty())){
            
            int node=q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto child:adj[node]){
                if(not(visited[child])){
                    q.push(child);
                    visited[child]=true;
                }
            }
            
            // for(auto val:ans)
            //     cout<<val<<",";
            // cout<<endl;
        }
        return ans;
    }
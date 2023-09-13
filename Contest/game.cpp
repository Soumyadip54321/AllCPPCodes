#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int n=1e5+10;

string findMaxScore(int n, int d, vector<int> a);
long long int maximize(int n, vector<int> x);
vector<int> findGood(int n, vector<int> &x, vector<int> &y);
long long waterFlow(int n, vector<vector<int>> &edges, vector<int> &a);
void bfs(int);

vector<pair<int,int>> adjlist[n];
//bool visited[n];
long long totalwater=0,feasiblewaterleft=LONG_MAX,feasiblewaterright=LONG_MAX;

int main(){
    vector<int> a={1,3,5,7},x={3,9},y={2,3},v,l={7,2,1,3};
    vector<vector<int>> edges={{3,4},{0,2},{2,3},{0,1}};
    //cout<<findMaxScore(4,2,a)<<endl;
    //cout<<maximize(3,x)<<endl;
    //v=findGood(2,x,y);
    cout<<waterFlow(5,edges,l)<<endl;
    return 0;
}
string findMaxScore(int n, int d, vector<int> a){
    int maxfunscore=*max_element(a.begin(),a.end());
    int weektype;

    if(d%2==0){
        if(maxfunscore%2==0)
            return "Yay!";
        return "Nay!";
    }
    
    if(maxfunscore%2!=0)
        return "Yay!";
    return "Nay!";
}

long long int maximize(int n, vector<int> x)
{
  // Write your code here.
  long long total=0;
  sort(x.rbegin(),x.rend());

  for(int i=0;i<x.size();i++){
    total+=(x[i]-i)*(x[i]-i);
  }
  return total;
}
long long waterFlow(int n, vector<vector<int>> &edges, vector<int> &a) {
    // Write your code here.
    for(int i=0;i<edges.size();i++){
        adjlist[edges[i][0]].push_back({edges[i][1],a[i]});
    }

    for(int i=0;i<n;i++){
        cout<<i<<":";
        for(auto p:adjlist[i]){
            cout<<"("<<p.first<<","<<p.second<<")";
        }
        cout<<endl;
    }
    bfs(0);
    return feasiblewaterleft+feasiblewaterright;
}
void bfs(int vertex){
    queue<pair<int,int>> ql,qr;
    ql.push({vertex,0});
    ql.push({-1,-1});

    while (not(ql.empty()))
    {   
        for(auto child:adjlist[ql.front().first]){
            ql.push(child);
            totalwater+=child.second;
        }
        ql.pop();
        //cout<<totalwater<<endl;
        if(ql.front().first==-1 && ql.front().second==-1){
            ql.pop();

            if(ql.size())
                feasiblewaterleft=min(feasiblewaterleft,totalwater);
            else
                return;
            totalwater=0;
            ql.push({-1,-1});
        }
    }
    //cout<<"feasible water: "<<feasiblewater<<endl;
}   

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int countRoutes(vector<int>& locations, int start, int finish, int fuel);
void dfs(int,int,int);

const int n=200;
vector<pair<int,int>> adjlist[n];
vector<int> visited(n);
vector<int> v;
long long paths=0;

int main(){
    vector<int> locations={2,3,6,8,4};
    cout<<countRoutes(locations,1,3,5);
    return 0;
}
int countRoutes(vector<int>& locations, int start, int finish, int fuel){
    /*
    idea:
    1. we create the adj list where source connects to all possoble destinations with weights |location[i]-location[j]| implying
    fuel to be consumed
    2. Then we apply dfs from source to each of the other cities it connects to
    */

   int cities=locations.size();

    for(int i=0;i<cities;i++){
        for(int j=0;j<cities;j++){
            if(i!=j)
                adjlist[i].push_back({j,abs(locations[i]-locations[j])});
        }
    }

    //display adj list
    for(int i=0;i<cities;i++){
        cout<<"city: "<<i<<"->";
        for(auto p:adjlist[i]){
            cout<<"{"<<p.first<<","<<p.second<<"};";
        }
        cout<<endl;
    }
    // if(start==finish)
    //     return paths;

    // dfs(start,finish,fuel);

    for(auto city:adjlist[start]){
        visited[start]=1;

        if(fuel>=city.second){
            dfs(city.first,finish,fuel-city.second);
            visited.assign(n,0);
            v.clear();
        }
    }
    return paths;
}
void dfs(int startcity,int endcity,int fuel){

    if(startcity==endcity){
        paths++;
        return;
    }
    visited[startcity]=1;

    if(fuel<=0)
        return;

    for(auto child:adjlist[startcity]){
        if(visited[child.first])
            continue;

        if(fuel>=child.second)
            dfs(child.first,endcity,fuel-(child.second));
    }
}
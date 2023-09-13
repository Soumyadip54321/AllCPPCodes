#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);
bool dfs(int,string);
void restorevisited();

const int n=1e5+10;
double varval[n];
vector<string> adjlist[n];
map<string,int> m;
int visited[n];

int main(){
    vector<vector<string>> equations={{"x1","x2"},{"x2","x3"},{"x1","x4"},{"x2","x5"}};
    vector<double> values={3.0,0.5,3.4,5.6},result;
    vector<vector<string>> queries={{"x2","x4"},{"x1","x5"},{"x1","x3"},{"x5","x5"},{"x5","x1"},{"x3","x4"},{"x4","x3"},{"x6","x6"},{"x0","x0"}};
    result=calcEquation(equations,values,queries);
    return 0;
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
    /*we use a map first to translate resp var to corresponding indexes in varval*/
    vector<double> result;
    int idx=0;
    
    for(int i=0;i<queries.size();i++){
        m[queries[i][0]]=0;
        m[queries[i][1]]=0;
    }

    for(int i=0;i<queries.size();i++){
        if(m[queries[i][0]]==0){
            idx+=1;
            m[queries[i][0]]=idx;
        }
        if(m[queries[i][1]]==0){
            idx+=1;
            m[queries[i][1]]=idx;
        }
    }
    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<":"<<it->second<<" ";
    cout<<endl;

    /*backward scan*/
    for(int i=equations.size()-1;i>=0;i--){
        if(varval[m[equations[i][1]]]==0)
            varval[m[equations[i][1]]]=1;
        varval[m[equations[i][0]]]=values[i]*varval[m[equations[i][1]]];
    }

    cout<<"first"<<endl;
    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<":"<<varval[it->second]<<" ";

    /*now we rescan to update any change in value that may have occured*/
    for(int i=equations.size()-1;i>=0;i--){
        if(varval[m[equations[i][1]]]==0)
            varval[m[equations[i][1]]]=1;
        varval[m[equations[i][0]]]=values[i]*varval[m[equations[i][1]]];
    }

    cout<<"\n"<<"updated"<<endl;
    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<":"<<varval[it->second]<<" ";
    cout<<endl;
    
    /*now we check for dependency of variables using dfs*/
    /*if found we compute values else we put -1 against the query*/
    for(int i=0;i<equations.size();i++){
        adjlist[m[equations[i][0]]].push_back(equations[i][1]);
        adjlist[m[equations[i][1]]].push_back(equations[i][0]);
    }

    for(auto it=m.begin();it!=m.end();it++){
        for(auto item:adjlist[it->second])
            cout<<item<<" ";
        cout<<endl;
    }
    /*now we compute queries one by one and put it in vector the result*/
    for(int i=0;i<queries.size();i++){
        if(varval[m[queries[i][0]]]==0 || varval[m[queries[i][1]]]==0)
            result.push_back(-1);
        else if(m[queries[i][0]]!=m[queries[i][1]]){
            /*now we look for dependency if exists*/
            if(dfs(m[queries[i][0]],queries[i][1]))
                result.push_back(varval[m[queries[i][0]]]/varval[m[queries[i][1]]]);
            else
                result.push_back(-1);
            restorevisited();
        }
        else
            result.push_back(1);
    }

    cout<<"\n"<<"result"<<endl;
    for(auto val:result)
        cout<<val<<" ";
    return result;
}
bool dfs(int idx,string s2){
    visited[idx]=1;
    bool a =false;

    for(auto child:adjlist[idx]){
        if(visited[m[child]]==1)
            continue;

        if(child==s2)
            return true;
         a|=dfs(m[child],s2);
    }
    return a;
}
void restorevisited(){
    for(int i=0;i<n;i++)
        visited[i]=0;
}
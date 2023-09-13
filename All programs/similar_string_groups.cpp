#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int numSimilarGroups(vector<string>& strs);
bool similarstringcheck(string,string);
void groupfill(int,vector<string>);

const int N=25e2+10;
vector<vector<string>> allgroups;
vector<string> group;
int dp[N];

int main(){
    memset(dp,-1,sizeof(dp));                   //introducing DP here.
    vector<string> all_strings={"nmiwx","mniwx","wminx","mnixw","xnmwi"};
    cout<<numSimilarGroups(all_strings);
    return 0;
}
int numSimilarGroups(vector<string>& strs){

    for(int i=strs.size()-1;i>=0;i--){
        groupfill(i,strs);
        if(not(group.empty())){
            allgroups.push_back(group);
            group.clear();
        }
    }
    for(int i=0;i<allgroups.size();i++){
        cout<<"{";
        for(auto item:allgroups[i])
            cout<<item<<" ";
        cout<<"}"<<endl;
    }
    return allgroups.size();
}
void groupfill(int idx ,vector<string> strs){

    for(int i=idx+1;i<strs.size();i++){
        if(similarstringcheck(strs[i],strs[idx])){
            strs.erase(strs.begin()+idx);
            groupfill(idx+1,strs);
        }
            allgroups.push_back(group);
    }

    if(dp[idx]!=-1)
        return;

    for(int i=0;i<idx;i++){
        if(similarstringcheck(strs[i],strs[idx]))
            groupfill(i,strs);
    }
    group.push_back(strs[idx]);
    dp[idx]=1;
    return;
}
bool similarstringcheck(string s1,string s2){
    if(s1==s2)
        return true;
    int numexchanges=0;
    
    for(int i=s1.size()-1;i>=0;i--){
        if(s1[i]==s2[i])
            continue;
        int index=find(s2.begin(),s2.end(),s1[i])-s2.begin();
        swap(s1[index],s1[i]);

        cout<<s1<<" "<<s2<<endl;
        numexchanges++;
        if(s1==s2 && numexchanges<=2)
            return true;
    }
    return false;
}

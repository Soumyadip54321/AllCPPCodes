#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int numSimilarGroups(vector<string>& strs);
bool similarstringcheck(string,string);
void checker(int,vector<string>&,vector<int>&);
// const int N=25e2+10;
// vector<int> groups(N,-1);


int main(){
    vector<string> all_strings={"tars","rats","arts","star"},n={"kccomwcgcs","socgcmcwkc","sgckwcmcoc","coswcmcgkc","cowkccmsgc","cosgmccwkc","sgmkwcccoc","coswmccgkc","kowcccmsgc","kgcomwcccs"},n1={"koqnn","knnqo","noqnk","nqkon"};
    int totalgroups=0,temp=-1;
    cout<<numSimilarGroups(n)<<endl;
    return 0;
}
int numSimilarGroups(vector<string>& strs){
    vector<int> groups(strs.size(),-1);
    checker(0,strs,groups);
    int temp=-1,totalgroups=0;

    sort(groups.begin(),groups.end());
        
    for(int i=0;i<strs.size();i++){
        cout<<groups[i]<<" ";
        if(temp!=groups[i]){
            totalgroups++;
            temp=groups[i];
        }
    }
    cout<<endl;
    return totalgroups;
}
void checker(int idx,vector<string>& strs,vector<int>& groups){
        if(idx==strs.size())
            return;
        if(groups[idx]==-1)
            groups[idx]=idx;

        for(int i=idx+1;i<strs.size();i++){
            if(similarstringcheck(strs[idx],strs[i])){
                groups[i]=groups[idx];
            }
        }
        checker(idx+1,strs,groups);
}
bool similarstringcheck(string s1,string s2){
    if(s1==s2)
        return true;
    
    for(int i=s1.size()-1;i>=0;i--){
        if(s1[i]==s2[i])
            continue;
        int index=find(s2.begin(),s2.end(),s1[i])-s2.begin();
        if(s1[index]==s1[i])
            continue;
        swap(s1[index],s1[i]);
        if(s1==s2)
            return true;
        else
            break;
    }
        return false;
}
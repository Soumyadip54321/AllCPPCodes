#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int goodSubsequence(vector<int> &a);
void computgoodsubs(vector<int>,int,vector<int>,vector<vector<int>>&);


int main(){
    vector<int> a={2,3,1};
    cout<<goodSubsequence(a);
    return 0;
}
int goodSubsequence(vector<int> &a){
    vector<int> subs;
    vector<vector<int>> allsubs;
    int ct=0;
    computgoodsubs(a,0,subs,allsubs);

    for(int i=0;i<allsubs.size();i++){
        unordered_map<int,int> m;
        bool found=false;

        for(auto val:allsubs[i]){
            if(m[val]==1){
                found=true;
                break;
            }
            m[val]++;
        }
        if(not(found))
            ct++;
    }
    //we run through all subseq 
    return ct;
}
void computgoodsubs(vector<int> arr,int idx,vector<int> subs,vector<vector<int>>& allsubs){
    if(idx>=arr.size()){
        if(not(subs.empty()))
            allsubs.push_back(subs);
        return ;
    }
    //take
    subs.push_back(arr[idx]);
    computgoodsubs(arr,idx+1,subs,allsubs);

    //not-take
    subs.pop_back();
    computgoodsubs(arr,idx+1,subs,allsubs);
}   
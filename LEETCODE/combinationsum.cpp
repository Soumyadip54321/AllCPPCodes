#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<int> v;
vector<vector<int>> s;


vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void findsum(vector<int>,int,int);

int main(){
    vector<int> candidates={2,3,5};
    vector<vector<int>> v;
    v=combinationSum(candidates,8);
    return 0;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    /*idea: here we put entries in an unordered map where from we pick elements to make the target at every iteration*/
    sort(candidates.begin(),candidates.end());
    candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
    findsum(candidates,target,0);

    for(int i=0;i<s.size();i++){
        for(auto val:s[i])
            cout<<val<<",";
        cout<<endl;
    }
    return s;
}
void findsum(vector<int> candidates,int target,int idx){
    if(target==0){
        s.push_back(v);
    }

    while(idx<candidates.size() && target-candidates[idx]>=0){
        v.push_back(candidates[idx]);
        findsum(candidates,target-candidates[idx],idx);
        idx++;
        v.pop_back();       //backtrack
    }
}
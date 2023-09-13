#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N=1e5+10;

int hsh[N];
vector<vector<int>> allsets;
void combinationSum(vector<int>& candidates, int target);
void updateset(vector<int>&,int,vector<int>);
void uniquecheck();
void reset();


int main(){
    int n=5,k=3,target=7;
    vector<int> candidates={2,3,6,7};
    combinationSum(candidates,target);

    for(int i=0;i<allsets.size();i++){
        cout<<"{";
        for(auto item:allsets[i])
            cout<<item<<" ";
        cout<<"}"<<endl;
    }
    uniquecheck();
    return 0;
}
void reset(){
    for(int i=0;i<N;i++)
        hsh[i]=0;
}
void combinationSum(vector<int>& candidates, int target){
    for(auto num:candidates)
        hsh[num]++;
    vector<int> v;
    updateset(candidates,target,v);
}
void updateset(vector<int>& candidates,int target,vector<int> comb){
    if(target==0){
        allsets.push_back(comb);
        comb.clear();
        return;
    }
    vector<int> ps=comb;
    int ptarget=target;
    for(int i=0;i<candidates.size();i++){
        if(candidates[i]<=target)
            comb.push_back(candidates[i]);
        else
            return;
        updateset(candidates,target-candidates[i],comb);
        comb=ps;
        target=ptarget;
    }
}
void uniquecheck(){     //remove sets with same freq elements
    reset();
}

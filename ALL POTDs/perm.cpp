#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> permute(vector<int>& nums);
void allperms(vector<int>,vector<vector<int>>&,int,vector<int>,unordered_map<int,bool>&);
void permutations(vector<int>,unordered_map<int,bool>&,vector<vector<int>>&,vector<int>);

int main(){
    vector<int> nums={1,2,3};
    vector<vector<int>> ans;

    ans=permute(nums);
    return 0;
}
vector<vector<int>> permute(vector<int>& nums){
   vector<vector<int>> ans;
   vector<int> ds;
   unordered_map<int,bool> m;
   sort(nums.begin(),nums.end());

//    do{
//         ans.push_back(nums);
//    }while(next_permutation(nums.begin(),nums.end()));
   permutations(nums,m,ans,ds);

   for(int i=0;i<ans.size();i++){
        cout<<"{";
        for(auto val:ans[i])
            cout<<val<<",";
        cout<<"}"<<endl;
   }
   return ans;
}
void permutations(vector<int> nums,unordered_map<int,bool>& m,vector<vector<int>>& ans,vector<int> ds){
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }

    for(int i=0;i<nums.size();i++){
        if(m[i])
            continue;
        m[i]=true;
        ds.push_back(nums[i]);
        permutations(nums,m,ans,ds);

        m[i]=false;
        ds.pop_back();
    }
}

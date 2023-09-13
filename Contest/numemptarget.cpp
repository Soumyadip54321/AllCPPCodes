#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target);
int countCompleteSubarrays(vector<int>& nums);
string minimumString(string a, string b, string c);

int main(){
    vector<int> hours={5,1,4,2,2};
    vector<int> nums={5,5,5,5};
    string a="aaaaa",b="bca",c="aaa";
    //cout<<numberOfEmployeesWhoMetTarget(hours,6);
    //cout<<countCompleteSubarrays(nums)<<endl;
    cout<<minimumString(a,b,c);
    return 0;
}
int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target){
    int numemp=0;

    for(auto h:hours){
        if(h>=target)
            numemp++;
    }
    return numemp;
}
int countCompleteSubarrays(vector<int>& nums){
    //BRUTE FORCE
    vector<vector<int>> allsubs;
    unordered_map<int,bool> m;
    int n=nums.size(),numofdistdigits=0,ans=0;

    for(auto val:nums)
        m[val]=true;
    
    for(auto it:m){
        numofdistdigits++;
    }
    //cout<<numofdistdigits<<endl;


    for(int i=0;i<n;i++){
        vector<int> subarr;
        subarr.push_back(nums[i]);
        allsubs.push_back(subarr);

        for(int j=i+1;j<n;j++){
            subarr.push_back(nums[j]);
            allsubs.push_back(subarr);
        }
    }

    // for(int i=0;i<allsubs.size();i++){
    //     cout<<"{";
    //     for(auto val:allsubs[i])
    //         cout<<val<<",";
    //     cout<<"}"<<endl;
    // }

    for(int i=0;i<allsubs.size();i++){
        int distfound=0;
        unordered_map<int,bool> visited;

        if(allsubs[i].size()>=numofdistdigits){
            for(auto val:allsubs[i]){
                if(m[val] and not(visited[val])){
                    distfound++;
                    visited[val]=true;
                }
            }
            if(distfound==numofdistdigits)
                ans++;
        }
    }
    return ans;
}
string minimumString(string a, string b, string c){
    vector<string> allstrings;
    string ans;

    allstrings.push_back(a);
    allstrings.push_back(b);
    allstrings.push_back(c);

    sort(allstrings.begin(),allstrings.end());

    ans=allstrings[0];

    for(auto s:allstrings)
        cout<<s<<",";
    cout<<endl;
    
    return "";
}
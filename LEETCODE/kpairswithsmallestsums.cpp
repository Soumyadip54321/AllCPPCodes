#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k);

int main(){
    vector<vector<int>> pairs;
    vector<int> nums1={1,2},nums2={3};
    pairs=kSmallestPairs(nums1,nums2,2);
    return 0;
}
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
    //BRUTE FORCE APPROACH
    vector<vector<int>> allpairs,ksmallestsumpair;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int i=0;

    for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            allpairs.push_back({nums1[i],nums2[j]});
        }
    }

    while(k && i<allpairs.size()){
        pq.push({allpairs[i][0]+allpairs[i][1],i});
        k--;
        i++;
    }

    while (not(pq.empty()))
    {
        ksmallestsumpair.push_back(allpairs[pq.top().second]);
        pq.pop();
    }
    
    for(int i=0;i<ksmallestsumpair.size();i++){
        cout<<"{";
        for(auto val:ksmallestsumpair[i]){
            cout<<val<<",";
        }
        cout<<"}";
    }
    return ksmallestsumpair;
}
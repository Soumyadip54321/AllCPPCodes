#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k);
long long computemaxscore(vector<int>,int,int,long long);

int main(){
    vector<int> nums1={4,2,3,1,1},nums2={7,5,10,9,6};
    cout<<maxScore(nums1,nums2,1)<<endl;
    return 0;
}
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k){
    vector<pair<int,int>> p;
    long long total=0,res=-1;
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<nums1.size();i++)
        p.push_back({nums2[i],nums1[i]});
    
    /*now we sort in descending order of elements in nums2 following greedy approach to obtain 
    the max score*/                                             //(4,2),(3,3),(1,3),(2,1)
    sort(p.rbegin(),p.rend());

    /*once number of elements in hea exceeds k we pop the one with min value such that we obtain max (sum*min nums2 element)*/
    for(int i=0;i<nums1.size();i++){
        pq.push(p[i].second);
        total+=p[i].second;

        if(pq.size()>k){            //here we omit the minimum element present in heap to obtain max sum once heap size goes past k
            total-=pq.top();
            pq.pop();
        }

        if(pq.size()==k)
            res=max(res,total*p[i].first);
    }
    return res;
}
long long computemaxscore(vector<int> nums1,int idx,int k,long long sum){
        if(k==0)
            return sum;

        long long maxsc=-1,prev=sum;
        for(int i=idx;i<nums1.size();i++){
            sum+=nums1[i];
            if(computemaxscore(nums1,i+1,k-1,sum)>maxsc){
                maxsc=computemaxscore(nums1,i+1,k-1,sum);
            }
            sum=prev;
        }
    return maxsc;
}
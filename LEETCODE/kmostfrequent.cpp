#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define DEFAULT -2000

using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k);
void initialize();
const int n=1e5+10;

vector<int> freqarr[n];
int elect[n];       /*this helps to keep count of elements*/

int main(){
    vector<int> nums={5,3,1,1,1,3,73,1},mostfreq;
    mostfreq=topKFrequent(nums,2);
    return 0;
}
vector<int> topKFrequent(vector<int>& nums, int k){
    /*idea is to construct a hash table with indexes representing frequency of elements assuming that no two elements have
    the same frequency*/
    int minel=*min_element(nums.begin(),nums.end()),prev=-1;
    vector<int> topfreqelements;
    if(minel>=0)
        minel=0;

    for(auto val:nums)
        elect[val-minel]++;

    for(int i=0;i<=*max_element(nums.begin(),nums.end())-minel;i++){
        if(elect[i]!=0)
            freqarr[elect[i]].push_back(i+minel);
    }
    int st=*max_element(elect,elect+n),idx=0;

    for(int i=st;i>=0;i--){
        for(auto item:freqarr[i])
            cout<<item<<" ";
        cout<<endl;
    }
    cout<<endl;
    while (k)
    {
        if(freqarr[st].empty()){
            st--;
            continue;
        }
        topfreqelements.push_back(freqarr[st][idx]);
        if(freqarr[st].size()-1-idx>0)
            idx++;
        else{
            idx=0;
            st--;
        }
        k--; 
    }
    for(auto elements:topfreqelements)
        cout<<elements<<" ";
    return {};
}

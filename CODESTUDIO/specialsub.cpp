#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
vector<int> specialSubarray(int n, vector<int> &arr);

int main(){
    vector<int> arr={4, 2, 17, 8, 2, 4, 20, 5, 5, 11, 6, 16},special;
    special=specialSubarray(12,arr);
    return 0;
}
vector<int> specialSubarray(int n, vector<int> &arr){
    unordered_map<int,int> frequency;
    vector<int> subarrwithfreqitem,freqitem;
    set<int> allfreq;

    int left=0,right=n-1,maxfreq=-1,firstfreq;
    bool checkequalfreq=true;

    for(int i=0;i<n;i++){
        frequency[arr[i]]++;
    }

    for(auto item:frequency)
        allfreq.insert(item.second);

    if(allfreq.size()==1 && frequency.size()!=1){
        return {*max_element(arr.begin(),arr.end())};
    }

    for(auto item:frequency){
        if(item.second>=maxfreq){
            if(item.second==maxfreq && item.first<freqitem){
                freqitem.push_back(item.first);
            }
            else if(item.second>maxfreq){
                maxfreq=item.second;
                freqitem.push_back(item.first);
            }
        }
    }
    //we look for the 1st occurance of freq item
    while (arr[left]!=freqitem && left<n)
    {
        left++;
    }

    while (arr[right]!=freqitem && right>=0)
    {
        right--;
    }
    
    for(int i=left;i<=right;i++)
        subarrwithfreqitem.push_back(arr[i]);
    
    for(auto val:subarrwithfreqitem)
        cout<<val<<",";
    cout<<endl;
    return subarrwithfreqitem;
}
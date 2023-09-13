#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> majorityElementII(vector<int> &arr);

int main(){
    vector<int> arr={1,2,4,4,3,4},v;
    v=majorityElementII(arr);
    return 0;
}
vector<int> majorityElementII(vector<int> &arr){
    unordered_map<int,int> m;
    vector<int> feasibleitems;

    for(int i=0;i<arr.size();i++)
        m[arr[i]]++;
    
    for(auto item:m){
        if(item.second>(arr.size()/3))
            feasibleitems.push_back(item.first);
    }

    // for(auto val:feasibleitems)
    //     cout<<val<<",";
    // cout<<endl;
    return feasibleitems;
}
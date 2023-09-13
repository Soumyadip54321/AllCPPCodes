#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> leftRotationsOfArray(vector<int> nums, vector<int> queries);

int main(){
    vector<vector<int>> leftrotated;
    vector<int> nums={7,8,6,1,2},queries={456,99,3};
    leftrotated=leftRotationsOfArray(nums,queries);
    return 0;
}
vector<vector<int>> leftRotationsOfArray(vector<int> nums, vector<int> queries){
    vector<vector<int>> leftrotated;


    for(int i=0;i<queries.size();i++){      //TC=O(N)*O(numqueries);
        vector<int> rotatedarr;

        if(queries[i]>=nums.size())
            queries[i]=queries[i]%nums.size();

        for(int j=queries[i];j<nums.size();j++)     /*O(N)*/
            rotatedarr.push_back(nums[j]);
        for(int j=0;j<queries[i];j++)
            rotatedarr.push_back(nums[j]);
        
        leftrotated.push_back(rotatedarr);
    }

    // for(int i=0;i<leftrotated.size();i++){
    //     cout<<"{";
    //     for (auto val:leftrotated[i])
    //     {
    //         cout<<val<<",";
    //     }
    //     cout<<"}"<<endl;
    // }

    return leftrotated;
}
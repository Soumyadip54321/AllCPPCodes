#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals);


int main(){
    vector<vector<int>> intervals={{1,3},{2,7},{3,5},{1,8},{9,10},{5,11},{11,12},{7,10},{12,12},{14,17}},mergedint;
    mergedint=mergeIntervals(intervals);
    return 0;
}
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals){
   queue<vector<int>> interq;       /*q contains final intervals*/
   vector<vector<int>> mergedint;
   sort(intervals.begin(),intervals.end());

   interq.push(intervals[0]);

   for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=interq.front()[1]){
            interq.push({interq.front()[0],max(intervals[i][1],interq.front()[1])});
            interq.pop();
        }
        else{
            mergedint.push_back(interq.front());
            interq.push(intervals[i]);
            interq.pop();
        }
   }
    mergedint.push_back(interq.front());
    interq.pop();
    
    // for(int i=0;i<mergedint.size();i++){
    //     cout<<"{";
    //     for(auto val:mergedint[i])
    //         cout<<val<<",";
    //     cout<<"}"<<endl;
    // }
   return mergedint;
}
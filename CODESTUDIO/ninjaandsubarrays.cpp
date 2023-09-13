#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int sumOfSmallestAndSecondSmallest(int n, vector<int> &arr);


int main(){
    vector<int> arr={3,8};
    cout<<sumOfSmallestAndSecondSmallest(2,arr);
    return 0;
}
int sumOfSmallestAndSecondSmallest(int n, vector<int> &arr){
    //vector<pair<int,int>> smallandsecsmall;
    int maxsum=INT_MIN;
    int s=-1,ss=-1;
    /*
    idea:
    1. use 2 ptr method to find all subarrays of size >=2
    2. insert only the smallest and second smallest among those
    */
   int start=0,end=1;

   while (start<n-1)
   {
        if(s==-1 && ss==-1){
            s=min(arr[start],arr[end]);
            ss=max(arr[start],arr[end]);
        }
        else{
            if(arr[end]<s){
                ss=s;
                s=arr[end];
            }
            else if(arr[end]>s && arr[end]<ss){
                ss=arr[end];
            }
        }
        maxsum=max(maxsum,ss+s);
        //smallandsecsmall.push_back({s,ss});
        end++;

        if(end>=n){
            start++;
            end=start+1;
            s=ss=-1;
        }
   }

//    for(auto p:smallandsecsmall){
//         cout<<p.first<<","<<p.second<<endl;
//    }
   return maxsum;
}
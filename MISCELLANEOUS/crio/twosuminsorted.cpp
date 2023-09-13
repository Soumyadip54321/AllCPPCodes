#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

bool twoSumInSortedArray(int n, vector<int> arr, int target);
vector<vector<int>> threeSum(vector<int>& nums);
void computesum(vector<int>,vector<int>&,int,int,int);

const int n=1e5+10;
int itemct[n];

int main(){
    vector<int> arr={2,4,5,8,9},nums={-1,0,1,2,-1,4};
    vector<vector<int>> v;
    //cout<<twoSumInSortedArray(5,arr,7)<<endl;
    v=threeSum(nums);
    return 0;
}
bool twoSumInSortedArray(int n, vector<int> arr, int target){
    int low=0,high=n-1;
    while (low<high)
    {
        if(arr[low]+arr[high]==target)
            return true;
        else{
            if(arr[low]+arr[high]>target)
                high--;
            else
                low++;
        }   
    }
    return false;
}
vector<vector<int>> threeSum(vector<int>& nums){
    vector<int> threesumele;
    vector<vector<int>> allthreesums;
    int k=3,first=0,sec;
    

    
}

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int minJumps(int arr[], int n);
int minSwaps(vector<int>&nums);

const int n=1e5+10;
bool visited[n];

int main(){
    int arr[]=  {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    vector<int> nums={8, 3, 14, 17, 15,1,12};

    cout<<minSwaps(nums)<<endl;
    //cout<<minJumps(arr,11)<<endl;
    return 0;
}
int minSwaps(vector<int>&nums){
    vector<int> numssorted=nums;
    int minswaps=0;

    sort(numssorted.begin(),numssorted.end());

    for(int i=0;i<nums.size();i++){
        if(nums[i]!=numssorted[i] && (visited[numssorted[i]]==false || visited[nums[i]]==false)){
            minswaps++;
            if(visited[numssorted[i]]==false)
                visited[numssorted[i]]=true;

            if(visited[nums[i]]==false)
                visited[nums[i]]=true;
        }
        else if(nums[i]==numssorted[i] && visited[numssorted[i]]==false){
            visited[numssorted[i]]=true;
        }
    }
    return minswaps;
}
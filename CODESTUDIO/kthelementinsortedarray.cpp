#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k);

int main(){
    vector<int> arr1={2,3,6,7,9},arr2={1,4,8,10};
    cout<<kthElement(arr1,arr2,5,4,4);
    return 0;
}
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    vector<int> merged;
    int i=0,j=0;

    while (i<n && j<m)
    {
        if(arr1[i]<=arr2[j]){
            merged.push_back(arr1[i]);
            i++;
        }
        else{
            merged.push_back(arr2[j]);
            j++;
        }
    }

    if(i<n){
        while (i<n)
        {
            merged.push_back(arr1[i]);
            i++;
        }
    }
    if(j<m){
        while (j<m)
        {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    return merged[k-1];
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> rotateArray(vector<int>& arr, int n);

int main(){
    vector<int> arr={4,0,3,2,5},ans;
    ans=rotateArray(arr,5);
    return 0;
}
vector<int> rotateArray(vector<int>& arr, int n){
    vector<int> leftrotarr(arr.begin(),arr.end());
    int i=0,j=1;

    if(n==1)
        return arr;
    
    while (j<n)
    {
        swap(leftrotarr[i],leftrotarr[j]);
        i=j;
        j++;
    }
    
    // for(auto val:leftrotarr)
    //     cout<<val<<",";
    // cout<<endl;

    return leftrotarr;
}
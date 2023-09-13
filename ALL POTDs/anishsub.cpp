#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int find(int n, vector<int> &arr, int x, int y);

int main(){
    vector<int> arr={1,2,1,3};
    cout<<find(4,arr,2,3);
    return 0;
}
int find(int n, vector<int> &arr, int x, int y){
    int end=0,start=0,ct=0,ans=0;

    for(int end=0;end<n;end++){
        if(arr[end]>=x && arr[end]<=y)
            ct=end-start+1;
        
        if(arr[end]>y){
            ct=0;
            start=end+1;
        }
        ans+=ct;
    }
    return ans;
}

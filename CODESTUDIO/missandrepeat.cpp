#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n);

const int n=1e5+10;
int hsh[n];


int main(){
    pair<int,int> p;
    vector<int> arr={6,4,3,5,5,1};
    p=missingAndRepeating(arr,6);
    return 0;
}
pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    int M,R;
    for(auto val:arr)
        hsh[val]++;
    
    for(int i=1;i<=n;i++){
        if(hsh[i]>=2)
            R=i;
        if(hsh[i]==0)
            M=i;
    }
    //cout<<M<<" "<<R<<endl;
    return {M,R};
}
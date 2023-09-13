#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector < int > productPuzzle(vector < int > & arr, int n);
const int M=1e9+7;

int main(){
    vector <int> arr={2,4,6,3,1,1},res;
    res=productPuzzle(arr,6);
    return 0;
}
vector < int > productPuzzle(vector < int > & arr, int n){
    vector<int> ans(n,0);          //(L,R)
    long long Lprod=1,Rprod=1;

    //left fill
    for(int i=0;i<n;i++){
        if(i==0){
            ans[i]=1;
        }
        else{
            ans[i]=Lprod;
        }
        Lprod=(Lprod*arr[i])%M;
    }

    //right fill
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            ans[i]=(ans[i]*1)%M;
        }
        else{
            ans[i]=(ans[i]*Rprod)%M;
        }
        Rprod=(Rprod*arr[i])%M;
    }

    // for(auto val:ans)
    //     cout<<val<<",";
    // cout<<endl;

    return ans;
}
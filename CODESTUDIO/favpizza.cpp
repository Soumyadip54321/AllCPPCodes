#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int* getProductArrayExceptSelf(int *arr, int n);
const int M=1e9+7;

int main(){
    vector<vector<int>> mat={{0,4,12},{1,4,1},{2,3,4},{0,10,2},{2,5,6}};
    int a[]={5,2,2};
    getProductArrayExceptSelf(a,3);
    return 0;
}
int* getProductArrayExceptSelf(int *arr, int n){
    int* result=new int[n];
    int* leftarr=new int[n];
    long long product=1;

    for(int i=0;i<n;i++){           //computes the left product here
        product=(product*arr[i])%M;
        leftarr[i]=product;
    }

    product=1;          //computes the right product successively
    for(int i=n-1;i>=1;i--){
        result[i]=(leftarr[i-1]*product)%M;
        product=(product*arr[i])%M;
    }
    result[0]=product;
    return result;
}

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> twoelements(int*,int);

int main(){
    int arr[]={35, 27, 37, 54, 92, 34, 38, 27, 45, 19, 35, 27, 37, 54, 92, 34, 38, 2, 45, 19, 4, 80};
    vector<int> res;
    res=twoelements(arr,22);
    return 0;
}
vector<int> twoelements(int* arr,int n){
    int xorres=arr[0],temp;
    vector<int> ans(2,0);

    for(int i=1;i<n;i++){
        xorres=xorres^arr[i];
    }
    temp=xorres;

    for(int i=0;i<n;i++){
        if(xorres==arr[i])
            break;
        xorres=xorres^arr[i];
    }
    ans[0]=xorres;
    ans[1]=temp^xorres;

    cout<<ans[0]<<","<<ans[1]<<endl;

    return ans;
}
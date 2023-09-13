#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
bool IsMean(int n, int k, int x, vector<int> &arr);

int main(){
    vector<int> arr={8};
    cout<<IsMean(1,1,2,arr);
    return 0;
}
bool IsMean(int n, int k, int x, vector<int> &arr){
    int sum=0,i=0,j=n-1,sumofvals;
    for(auto val:arr)
        sum+=val;

    if(n*x-sum<0)
        return false;
    
    if(n*x==sum and k==1)
        return true;
    else if((n*x==sum and k!=1) or ((n*x-sum>0) and k==1))
        return false;

    if(((n*x-sum)%(k-1))!=0)
        return false;

    sort(arr.begin(),arr.end());
    sumofvals=((n*x-sum)/(k-1));
    //we apply 2-sum approach to find 2 numbers s.t their sum equals moreneeded/(k-1);
    while (i<j)
    {
        if(arr[i]+arr[j]==sumofvals)
            return true;
        
        if(arr[i]+arr[j]<sumofvals)
            i++;
        else
            j--;
    }
    return false;
}
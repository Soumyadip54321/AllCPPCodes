#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int firstMissing(int arr[], int n);

int main(){
    int arr[]={3,4,-1,1};
    cout<<firstMissing(arr,4)<<endl;
    return 0;
}
int firstMissing(int arr[], int n){

    if(*max_element(arr,arr+n)<0)
        return 1;
    
    int low=0,high=n-1;
    while (low<high)
    {
        if(arr[low]<0 && arr[high]>=0){
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
        else if(arr[low]<0 && arr[high]<0){
            high--;
        }
        else if(arr[low]>=0 && arr[high]>=0){
            low++;
        }
        else if(arr[low]>=0 && arr[high]<0){
            low++;
            high--;
        }
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<",";
    cout<<endl;

    int highmiss,lowmiss,minpos,maxpos;
    int i=0,posidx;

    while (arr[i]>=0)
    {
        posidx=i;
        i++;
    }
    minpos=*min_element(arr,arr+posidx+1);
    maxpos=*max_element(arr,arr+posidx+1);

    cout<<minpos<<endl;
    if(minpos>1)
        return 1;

    if(minpos+n-1==maxpos){
        highmiss=maxpos-1;
    }
    else
        highmiss=minpos+n-1;
    
    lowmiss=minpos+1;
    cout<<highmiss<<","<<lowmiss<<endl;

    for(int i=0;i<=posidx;i++){
        if(arr[i]==lowmiss)
            lowmiss++;
        else if(arr[i]==highmiss)
            highmiss--;
    }

    if(lowmiss<0 && highmiss>=0)
        return highmiss;
    else if(lowmiss>=0 && highmiss<0)
        return lowmiss;
    return lowmiss;
}
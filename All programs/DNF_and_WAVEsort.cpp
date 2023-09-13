#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

void DNFsort(int*,int);
void WAVEsort(int*,int);
int minimum(int,int,int*);


int main(){
    int arr[]={6,23,45,23,23,6,6,45},arr1[]={1,3,4,7,5,6,2};
    // DNFsort(arr,8);
    WAVEsort(arr1,(sizeof(arr1)/sizeof(int)));

    for(int i=0;i<(sizeof(arr1)/sizeof(int));i++)
        cout<<arr1[i]<<" ";
    cout<<endl;
    return 0;
}
void DNFsort(int* arr,int n){           //sorts array with 3 distinct elements.
    int low=0,mid=0,high=n-1;

    while(mid<=high){
        if(arr[mid]==6){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==45){
            swap(arr[mid],arr[high]);
            high--;
        }
        else if(arr[mid]==23)
            mid++;
    }
}
void WAVEsort(int* arr,int n){
    int start=1;
    
    while(start<n){
        if(not(arr[start]<=arr[minimum(start-1,start+1,arr)])){
            // int temp=arr[start];
            // arr[start]=minimum(arr[start-1],arr[start+1]);
            // minimum(arr[start-1],arr[start+1])=arr[start];
            swap(arr[start],arr[minimum(start-1,start+1,arr)]);
        }
        start+=2;
    }
}
int minimum(int idx1,int idx2,int *arr){
    if(arr[idx1]<arr[idx2])
        return idx1;
    else if(arr[idx1]>arr[idx2])
        return idx2;
    return idx1;
}
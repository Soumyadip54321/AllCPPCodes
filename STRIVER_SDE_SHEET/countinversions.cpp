#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

long long getInversions(long long *arr, int n);
void mergesort(long long*,int,int);
void merge(long long*,int,int,int);
long long ctinv=0;

int main(){
    long long arr[]={2, 5, 1, 3, 4};
    cout<<getInversions(arr,5)<<endl;
    return 0;
}
long long getInversions(long long *arr, int n){
    /*
    idea:
    1. here we implement the merge-sort technique since at every level we deal with 2 arrays that are sorted themselves
    2. and we merge them to form a complete sorted array
    3. everytime during merge if we find any item of left array larger than that of right we increase the inversion count
    by number of elements present in left array from the index till the end
    */
    mergesort(arr,0,n-1);

    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    return ctinv;
}
void mergesort(long long* arr,int low,int high){
    if(high>low){
        int mid=low+(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid+1,high);
    }
}
void merge(long long* arr,int low,int mid,int high){
    int *temp=new int[high-low+1];
    int i=low,j=mid,idx=0;

    while (i<mid && j<=high)
    {
        if(arr[i]>arr[j]){
            ctinv+=(mid-i);
            temp[idx]=arr[j];
            idx++;
            j++;
        }
        else{
            temp[idx]=arr[i];
            i++;
            idx++;
        }
    }

    if(i<mid){
        while (i<mid)
        {
            temp[idx]=arr[i];
            i++;
            idx++;
        }
    }

    if(j<=high){
        while (j<=high)
        {
            temp[idx]=arr[j];
            j++;
            idx++;
        }
    }
    //display temp
    // for(int i=0;i<high-low+1;i++)
    //     cout<<temp[i]<<" ";
    // cout<<endl;

    //we put the sorted elements into original array
    idx=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[idx];
        idx++;
    }
}
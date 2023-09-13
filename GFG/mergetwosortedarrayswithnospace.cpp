#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
void merge(long long arr1[], long long arr2[], int n, int m);
void swapifgreater(long long arr1[], long long arr2[],int,int);

int main(){
    long long arr1[]={1,3,5,7},arr2[]={0,2,6,8,9};
    merge(arr1,arr2,4,5);
    return 0;
}
void merge(long long arr1[], long long arr2[], int n, int m){
    //we use GAP METHOD
    int gap=(n+m)/2+(n+m)%2;
    while (true)
    {   
        int left=0;
        int right=left+gap;

        while(right<n+m){
            //arr1 and arr2
            if(left<n && right>=n){
                if(arr1[left]>arr2[right-n])
                    swapifgreater(arr1,arr2,left,right-n);
            }
            //arr2 and arr2
            else if(left>=n){
                if(arr2[left-n]>arr2[right-n])
                    swapifgreater(arr2,arr2,left-n,right-n);
            }
            //arr1 and arr1
            else{
                if(arr1[left]>arr1[right])
                    swapifgreater(arr1,arr1,left,right);
            }
            left++;
            right++;
        }
        if(gap==1)
            break;
        gap=(gap/2)+(gap%2);
    }
    //display arr1 and arr2
    for(int i=0;i<n;i++)
            cout<<arr1[i]<<",";
        cout<<endl;

    for(int i=0;i<m;i++)
        cout<<arr2[i]<<",";
    cout<<endl;
}
void swapifgreater(long long arr1[], long long arr2[],int idx1,int idx2){
    swap(arr1[idx1],arr2[idx2]);
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
void sort012(int *arr, int n);

int main(){
    int arr[]={2, 1, 2, 0, 1, 0};
    sort012(arr,6);
    return 0;
}
void sort012(int *arr, int n){
    int p1=0,p2=n-1;


    //at first we move all zeros front
    while (p1<p2)
    {
        if(arr[p1]>0 && arr[p2]==0){
            swap(arr[p1],arr[p2]);
            p1++;
            p2--;
        }
        else if(arr[p1]==0 && arr[p2]==0){
            p1++;
        }
        else if(arr[p1]>0 && arr[p2]>0){
            p2--;
        }
        else{
            p1++;
            p2--;
        }
    }
    //now we move the 2s back keeping 1s in the middle
    /*
    at first we find where the first non-zero item from front is placed
    */

   for(p1=0;p1<n;p1++){
        if(arr[p1]!=0)
            break;
   }
    p2=n-1;

    while (p1<p2)
    {
        if(arr[p1]==2 && arr[p2]==1){
            swap(arr[p1],arr[p2]);
            p1++;
            p2--;
        }
        else if(arr[p1]==2 && arr[p2]==2){
            p2--;
        }
        else if(arr[p1]==1 && arr[p2]==1)
            p1++;
        else{
            p1++;
            p2--;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<",";
    // }
    // cout<<endl;
}
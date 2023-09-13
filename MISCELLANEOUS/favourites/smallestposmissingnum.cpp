#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int missingNumber(int arr[], int n);

int main(){
    int arr[]={0};
    cout<<missingNumber(arr,1);
    return 0;
}
int missingNumber(int arr[], int n){
    //first we check if 1 is present
    /*
    1. first we segregate the positive and negatives
    */

   int i=0,j=n-1,nonpossize=-1;

   while (i<j)
   {
        if(arr[i]>0 && arr[j]<=0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        else if(arr[i]<=0 && arr[j]<=0){
            i++;
        }
        else
            j--;
   }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<",";
    cout<<endl;


   //we find the index of first num>=0
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            nonpossize=i;
            break;
        }
    }
    if(nonpossize==-1)
        return 1;
    
    for(int i=nonpossize;i<n;i++){
        int num=abs(arr[i]);
        if(nonpossize+num-1<n && arr[nonpossize+num-1]>0)      //we mark numbers present at index=nonpossize+num-1 '-'ve to indicate that the value is present
            arr[nonpossize+num-1]=-arr[nonpossize+num-1];
    }

    for(int i=nonpossize;i<n;i++){     //we look for the first positive value if any that denotes the smallest positive element missing to be i-nonpossize+1;
        if(arr[i]>0)
            return i-nonpossize+1;
    }
    return n-nonpossize+1;    
}
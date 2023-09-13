#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
void arrange(long long arr[], int n);


int main(){
    long long arr[]={3,2,0,1};
    arrange(arr,4);
    return 0;
}
void arrange(long long arr[], int n){
    //idea:
    /*
    1. we use 2 variables representing 
    2. index & value
    3. This indicates the index at which the value in the original array was present everytime that value is changed
    4. also since a value is used once cause the array has elements from 0-n-1 our index and value will keep on changing
    */

   long long t=-1,index=-1,touched=n,i=0,visited;

   if(index==-1){
        t=arr[0];
        index=0;
        arr[0]=arr[arr[0]];
    }

   while (touched)
   {

   }
   

    for(int i=0;i<n;i++)
        cout<<arr[i]<<",";
    cout<<endl;
}
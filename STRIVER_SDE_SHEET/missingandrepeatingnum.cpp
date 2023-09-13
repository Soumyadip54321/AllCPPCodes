#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n);

int main(){
    vector<int> arr={6,4,3,5,5,1};
    pair<int,int> p;
    p=missingAndRepeating(arr,6);
    return 0;
}
pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    /*
    idea:
    1. for find ing the repeating number we mark all values present at index abs(arr[i])-1 negative
    2. in case of a repeated number we'd try and mark a value negative that's already is
    3. for a missing number there will always exists such a value in array will remains positive i.e. unmarked
    */

   int R,M;

   for(int i=0;i<n;i++){
        if(arr[abs(arr[i])-1]<0){
            R=abs(arr[i]);
        }
        else{
            arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
        }
   }

   //we iterate the array to find the index where the entry is positive still. This index+1 will be our missing number

   for(int i=0;i<n;i++){
        if(arr[i]>0){
            M=i+1;
            break;
        }    
   }
    //cout<<M<<" "<<R<<endl;
   return {M,R};
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int minJumps(int arr[], int n);
void computeminjumpstoend(int arr[],int n,int idx,int numjumps);
int minjumps=INT_MAX;

int main(){
    int arr[]={1, 4, 3, 2, 6, 7};
    cout<<minJumps(arr,6);
    return 0;
}
int minJumps(int arr[], int n){
    //BRUTE FORCE RECURSION APPROACH
    /*
    idea:
    1. from the starting index idx we jump to all possible indexes from [idx+1,idx+arr[idx]] with number of jumps as numjumps+1
        where numjumps is the total jumps we made till that point
    2. base cases:-
        (i) if we reach the end of array i.e. idx>=n-1 we store the minimum between 'numjumps' and our result that holds
            the minimum number of jumps to reach end 'minjumps' in minjumps and return
        (ii) if along the way we come across an idx s.t arr[idx]==0 we cannot move forward and hence return 
    */
    computeminjumpstoend(arr,n,0,0);
        
    if(minjumps==INT_MAX)
        return -1;
    return minjumps;
}

void computeminjumpstoend(int arr[],int n,int idx,int numjumps){
        if(idx>=n-1){
            minjumps=min(minjumps,numjumps);
            return;
        }
        if(arr[idx]==0){
            return;
        }

        for(int jumps=1;jumps<=arr[idx];jumps++){
            computeminjumpstoend(arr,n,idx+jumps,numjumps+1);
        }
        //TC=O(n^n)
}
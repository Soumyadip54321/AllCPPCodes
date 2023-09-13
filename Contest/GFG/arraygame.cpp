#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int minops(int n, vector<int>&arr, vector<int>&brr);
void rotatearray(vector<int>&arr,int n,int rotamt);

int main(){
    vector<int> arr={1,2,3,4,5},brr={4,5,1,3,2};
    cout<<minops(5,arr,brr);
    return 0;
}
int minops(int n, vector<int>&arr, vector<int>&brr){
        int numops=0,brct=0;
	    unordered_map<int,int> mpp,temp;
	    
	    //track position of each element in arr
	    for(int i=0;i<n;i++)
	        mpp[arr[i]]=i;
	    
	    while(n){
	        if(arr[0]==brr[0]){
	            numops++;
	            arr.erase(arr.begin());
	            brr.erase(brr.begin());
                n--;

                //update positions of rem array elements here
                mpp=temp;
                for(int i=0;i<n;i++)
	                mpp[arr[i]]=i;
	        }
	        else{
	            numops+=mpp[brr[0]];
	            rotatearray(arr,n,mpp[brr[0]]);
	        }
	    }
	    return numops;
}

void rotatearray(vector<int>&arr,int n,int rotamt){
        vector<int> newarr=arr;
        
        for(int i=0;i<n;i++){
            if(i-rotamt<0){
                newarr[i-rotamt+n]=arr[i];
            }
            else
                newarr[i-rotamt]=arr[i];
        }
        arr=newarr;
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
void transpose(vector<vector<int> >& matrix, int n);
int minSubarraySum(int arr[], int n, int k) ;
int findSmallestInteger(vector<int> arr);

int main(){
    vector<vector<int> > matrix={{1, 2},
                                 {-9, -2}};
    vector<int> a={1, 1, 1, 1};
    int arr[]={1, 2};
    //transpose(matrix,2);
    //cout<<minSubarraySum(arr,2,3);
    cout<<findSmallestInteger(a);

    return 0;
}
void transpose(vector<vector<int> >& matrix, int n){
    //since matrix is a square one we change all elements eexcept the pivots around which we rotate row->col or col->row

    for(int col=0;col<n;col++){
        for(int row=col;row<n;row++){
            swap(matrix[row][col],matrix[col][row]);
        }
    }
}
int minSubarraySum(int arr[], int n, int k) {
    //2 ptr method
    int s=0,e=-1,result=INT_MAX,sum=0;

    // if(k>n)
    //     return -1;
    
    while (true)
    {
        while (e-s+1<k && e<n)
        {
            e++;
            sum+=arr[e];
        }

        if(e>=n)
            break;

        result=min(result,sum);
        sum-=arr[s];
        s++;
    }
    return result;
}
int findSmallestInteger(vector<int> arr){
    int smallestpos=1,n=arr.size();

    for(int i=0;i<n;i++){
        if(arr[i]>smallestpos)
            return smallestpos;
        else{
            smallestpos+=arr[i];
        }
    }
    return smallestpos;
}
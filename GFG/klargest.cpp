#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> kLargest(int arr[], int n, int k);
const int n=1e5+10;
int a[n];

int main(){
    vector<int> k;
    int arr[]={322, 559, 647, 983, 482, 145, 197, 223, 130, 162, 536, 451, 174, 467};
    k=kLargest(arr,14,9);
    return 0;
}
vector<int> kLargest(int arr[], int n, int k){
    /*
    idea:
    1. here we take a priority queue
    2. insert elements keeping size k
    */
   int total=k;
   priority_queue<int,vector<int>,greater<int>> pq;             /*min heap*/
   pq.push(arr[0]);

   for(int i=1;i<n;i++){
            if(pq.size()==k){
                pq.push(arr[i]);
                pq.pop();
            }
            else
                pq.push(arr[i]);
   }

   while (not(pq.empty()))
   {
        a[k-1]=pq.top();
        //cout<<pq.top()<<",";
        pq.pop();
        k--;
   }
   vector<int> klarge(a,a+total);

    // for(auto val:klarge)
    //     cout<<val<<" ";
   return klarge;
}
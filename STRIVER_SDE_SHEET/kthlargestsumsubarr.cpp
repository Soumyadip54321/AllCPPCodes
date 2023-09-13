#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int getKthLargest(vector<int> &arr, int k);

int main(){
    vector<int> arr={1,2,3};
    cout<<getKthLargest(arr,1);
    return 0;
}
int getKthLargest(vector<int> &arr, int k){
    //NAIVE APPROACH

    /*
    idea:
    1.  we iterate through every possible combination and compute the sum obtained
    2. we insert the sum in priority queue
    3. Find the kth sum from top 
    */

   int s=0,e=0,sum=0,size=arr.size();
   priority_queue<int> pq;
   

   while (true)                         //TC=O(N^2log(N));
   {
        sum+=arr[e];
        pq.push(sum);
        e++;

        while (e<size)
        {
            sum+=arr[e];
            pq.push(sum);           
            e++;
        }
        sum=0;
        s++;
        e=s;

        if(s>=size)
            break; 
   }
    k-=1;
    while (k)               //TC=O(Klog(N))
    {
            pq.pop();
            k--;
    }
   return pq.top();
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long maxDiamonds(int A[], int N, int K);


int main(){
    int A[]={7,1,2};
    cout<<maxDiamonds(A,3,2);
    return 0;
}
long long maxDiamonds(int A[], int N, int K){
    /*
    idea:
    1. we put number of diamonds in a priority queue(max heap)
    2. consider dropping diamonds form up top increasing gain by the number and halving the number before pushing it back
    3. we continue this until K is resched
    */
   priority_queue<int> pq;      /*max heap*/
   long long gain=0;

    for(int i=0;i<N;i++)                //TC=O(NLOG(N));  SC=O(N)
        pq.push(A[i]);
    
    while (K)                   //TC=O(KLOG(N));
    {
        gain+=pq.top();
        int num=pq.top();

        pq.pop();
        pq.push(num/2);
        K--;
    }
    return gain;
}
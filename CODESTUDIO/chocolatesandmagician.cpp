#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int M=1e9+7;
int maximumChocolates(vector<int> &arr, int k);

int main(){
    vector<int> arr={2,10,4,3};
    cout<<maximumChocolates(arr,1);
    return 0;
}
int maximumChocolates(vector<int> &arr, int k){
    long long eaten=0;
    priority_queue<int> pq;
    int takenout;

    for(int i=0;i<arr.size();i++){              //TC=O(NLOG(N));
        pq.push(arr[i]);
    }

    while (k)                           //TC=O(KLOG(N));
    {

        eaten+=pq.top();
        takenout=pq.top();
        pq.pop();                   //TC=O(LOG(N))

        takenout/=2;
        pq.push(takenout);
        k--;
    }
    return eaten%M;
}
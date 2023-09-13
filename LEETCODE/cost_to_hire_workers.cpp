#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long totalCost(vector<int>& costs, int k, int candidates);

int main(){
    vector<int> costs={18,64,12,21,21,78,36,58,88,58,99,26,92,91,53,10,24,25,20,92,73,63,51,65,87,6,17,32,14,42,46,65,43,9,75};
    cout<<totalCost(costs,13,23);
    return 0;
}
long long totalCost(vector<int>& costs, int k, int candidates){
    long long totalcost=0;
    int intakes=candidates;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

    int i=0,j=costs.size()-1;
    //cout<<costs.size()<<endl;

    while (i<j)                                 //TC=O(min(intake,N/2)*LOG(N));
    {
        pq.push({costs[i],i});
        pq.push({costs[j],j});
        intakes--;
        if(intakes==0)
            break;
        i++;
        j--;
    }

    if(i==j)
        pq.push({costs[i],i});

    //cout<<i<<" "<<j<<endl;
    if(i>=j){
        while (k)                   //TC=O(KLOG(N));
        {
            int idx=pq.top().second;
            totalcost+=pq.top().first;
            pq.pop();
            k--;
        }
    }
    else{
        while (k)                           /*TC=O(KLOG(N))*/
        {
            int idx=pq.top().second;
            //cout<<idx<<endl;
            totalcost+=pq.top().first;
            pq.pop();

            if(j-i>1){
                if(idx>=j){
                    pq.push({costs[j-1],j-1});
                    j--;
                }
                else if(idx<=i){
                    pq.push({costs[i+1],i+1});
                    i++;
                }
            }
            k--;
        }
    }
    return totalcost;
}
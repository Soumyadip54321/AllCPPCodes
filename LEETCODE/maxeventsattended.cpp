#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int maxValue(vector<vector<int>>& events, int k);

int main(){
    vector<vector<int>> events={{40,73,65},{57,79,80},{51,57,19},{33,99,77},{47,85,44},{18,56,11},{19,78,87},{23,80,37},{26,48,74},{45,87,80},{10,12,52},{23,83,43},{48,84,42},{23,39,3}};
    cout<<maxValue(events,13);
    return 0;
}
int maxValue(vector<vector<int>>& events, int k){
    /*
    idea:
    1.  we first sort events basis their value from largest to smallest.
    2.  then we pick events from first such that no two events starts or ends at the same time  
    */
    priority_queue<pair<int,pair<int,int>>> pq;      //form: (value,(start,end));
    priority_queue<pair<int,pair<int,int>>> pq2;
    int n=events.size(),maxvalobtained=-1;

    for(int i=0;i<n;i++){                                   //TC=O(Nlog(N))
        pq.push({events[i][2],{events[i][0],events[i][1]}});
    }
    pq2=pq;


        while(not(pq.empty())){
            int minendtime=-1,minsttime=-1,maxendtime,maxsttime,valobtained=0,times=k;
            while (times && not(pq.empty()))                //TC=O(klog(N))
            {
                if(minendtime==-1){
                    valobtained+=pq.top().first;
                    minendtime=pq.top().second.second;
                    minsttime=pq.top().second.first;
                    maxendtime=minendtime;
                    maxsttime=minsttime;

                    times--;
                }
                else if((pq.top().second.first>minendtime && pq.top().second.second<maxsttime) || pq.top().second.second<minsttime || pq.top().second.first>maxendtime){
                    valobtained+=pq.top().first;
                    minendtime=min(minendtime,pq.top().second.second);
                    minsttime=min(minsttime,pq.top().second.first);

                    maxendtime=max(maxendtime,pq.top().second.second);
                    maxsttime=max(maxsttime,pq.top().second.first);

                    times--;
                }
                pq.pop();
            }
            maxvalobtained=max(maxvalobtained,valobtained);
            pq2.pop();       //here we omit the top event since we already considered it;

            pq=pq2;
        }
    return maxvalobtained;
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int maximumProfit(vector<int> &prices, int n, int k);

int main(){
    vector<int> prices={2,5,10,8,12};
    cout<<maximumProfit(prices,5,2);
    return 0;
}
int maximumProfit(vector<int> &prices, int n, int k){
    /*
    idea:
    1. at first we find the optimal (SPs,day sold) against each CP
    2. Next for each transaction we iterate from daysold+1 to set the maxprofit
    3. we find the maximum for K such transactions
    */
    if(k==0)
        return 0;

   priority_queue<pair<int,pair<int,int>>> pq;              //(profit,(broughtday,sold day)) type entries
   vector<int> optimalSPday(n);
    int maxSPidx,day,maxprofitinktrans=-1,trans=k;

    optimalSPday[n-1]=n-1;
    maxSPidx=n-1;

    for(int i=n-2;i>=0;i--){
        if(prices[maxSPidx]>prices[i])
            optimalSPday[i]=maxSPidx;
        else{
            optimalSPday[i]=i;
            maxSPidx=i;
        }
    }

    // for(int i=0;i<n;i++)
    //     cout<<optimalSPday[i]<<",";
    // cout<<endl;

    for(int i=0;i<n;i++){
        int maxprofit=prices[optimalSPday[i]]-prices[i];
        int j=optimalSPday[i]+1;

        //cout<<maxprofit<<endl;
        while (j<n)
        {
            pq.push({prices[optimalSPday[j]]-prices[j],{j,optimalSPday[j]}});
            j=optimalSPday[j]+1;
        }

        //now we compute the max profit by k transactions
        int daysold=optimalSPday[i];

        while(trans && not(pq.empty())){

            if(daysold<pq.top().second.first){
                maxprofit+=pq.top().first;
                daysold=pq.top().second.second;
            }
            pq.pop();
            trans--;
        }
        
        while (not(pq.empty()))
        {
            pq.pop();
        }
        maxprofitinktrans=max(maxprofitinktrans,maxprofit);
        trans=k;
        //cout<<maxprofitinktrans<<endl;
    }
    return maxprofitinktrans;
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int maxProfit(vector<int>& prices);
int findmin(vector<int>,int,int);
int findoptimalprofit(vector<int>,int);

const int N=1e5+10;
int maxsellprices[N];


int main(){
    vector<int> prices={1,5,7,6};
    cout<<maxProfit(prices)<<endl;
    return 0;
}
int maxProfit(vector<int>& prices){
    /*we search for local maxima at each index looking at the future*/
    int maxsp=-1;
    for(int i=prices.size()-1;i>=0;i--){
        if(maxsp<prices[i])
            maxsp=prices[i];
        maxsellprices[i]=maxsp;
    }

    int maxprofit=-1;
    for(int i=0;i<prices.size();i++){
        if(maxprofit<maxsellprices[i]-prices[i])
            maxprofit=maxsellprices[i]-prices[i];
    }
    
    // cout<<maxprofit<<endl;
    return maxprofit;
}

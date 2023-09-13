#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int stockBuyAndSell(int n, vector<int> &prices);

int main(){
    vector<int> prices={3,4,1,5};
    cout<<stockBuyAndSell(4,prices);
    return 0;
}
int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        int db=n-2,ds=n-1;
        int maxprofit=0;
        
        while(db>=0){
            if(prices[db]>=prices[ds]){
                ds=db;
            }
            else{
                maxprofit+=prices[ds]-prices[db];
                ds=db;
            }
            db--;
        }
        return maxprofit;
    }
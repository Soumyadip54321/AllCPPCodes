#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int cutRod(int price[], int n);
void obtainmaximumprices(int*,int,int,int,int);
int maxprice=-1;

int main(){
    int price[]={20};
    cout<<cutRod(price,1);
    return 0;
}
int cutRod(int price[], int n){
    /*
    idea:
    1. try all possible combination that add upto n
    2. find out the price for each of them
    3. store prices in a vector
    */
    obtainmaximumprices(price,n,0,0,0);  
    return maxprice;
}
void obtainmaximumprices(int* prices,int length,int currlen,int cidx,int currprice){
    if(currlen==length){
        // maxprices[cidx]=max(maxprices[cidx],currprice);
        maxprice=max(maxprice,currprice);
        return;
    }
    if(currlen>length)
        return;

    for(int i=0;i<length;i++)
    {
        currlen+=(i+1);
        currprice+=prices[i];
        obtainmaximumprices(prices,length,currlen,i,currprice);
        currlen-=(i+1);                         /*backtrack*/
        currprice-=prices[i];
    }
}
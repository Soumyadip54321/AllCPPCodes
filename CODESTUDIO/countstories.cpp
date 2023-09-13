#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int countStories(int x, int y, int z);

int main(){
    cout<<countStories(4,1,10);
    return 0;
}
int countStories(int x, int y, int z){
    int priceperstory=y,coins=z,storiestolistentogetfreestory=x,storiesct=0;

    if(coins<priceperstory)
        return storiesct;

/*-----------------METHOD-I TC=O(coins)-----------------------------------------------------*/
    while (coins>=priceperstory)                         
    {
        storiesct++;
        coins-=priceperstory;
        storiestolistentogetfreestory--;

        if(storiestolistentogetfreestory==0){
            storiesct++;
            storiestolistentogetfreestory=x-1;
        }
    }

/*----------------METHOD-II TC=O(1)----------------------------------------------------*/
    storiesct+=coins/priceperstory;

    if(storiestolistentogetfreestory>storiesct){
        return storiesct;
    }
    else if(storiestolistentogetfreestory==storiesct)
        return storiesct+1;
    
    int rem=storiesct-storiestolistentogetfreestory;
    storiesct++;
    storiestolistentogetfreestory--;

    storiesct+=rem/storiestolistentogetfreestory;
    return storiesct;
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int totalSteps(int n, int k, vector<int> &flowers);

int main(){
    vector<int> flowers={1,1,1,1,1};
    cout<<totalSteps(5,1,flowers);
    return 0;
}
int totalSteps(int n, int k, vector<int> &flowers){
    int minsteps=0,tankloc=-1;
    int currpos=tankloc,containerqty=k,floweridx=currpos+1,wateredplants=0;

    while(true){
        if(flowers[floweridx]<=containerqty){

            minsteps+=floweridx-currpos;
            currpos=floweridx;
            containerqty-=flowers[currpos];

            flowers[currpos]=0;
            floweridx=currpos+1;
            wateredplants++;

            while(flowers[floweridx]<=containerqty && wateredplants<n){
                minsteps+=floweridx-currpos;
                currpos=floweridx;
                floweridx=currpos+1;
                wateredplants++;

                containerqty-=flowers[currpos];
                flowers[currpos]=0;;
            }

            if(wateredplants==n)
                break;
            //refill container here at tank location
            minsteps+=currpos-tankloc;
            currpos=tankloc;
            containerqty=k;
        }
    }
    return minsteps;

}
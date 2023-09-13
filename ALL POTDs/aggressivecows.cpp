#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int aggressiveCows(vector<int> &stalls, int k);
bool canplacecows(vector<int> &,int,int);

int main(){
    vector<int> stalls={67, 70, 13, 97, 19, 15, 22, 89, 28};
    cout<<aggressiveCows(stalls,7);
    return 0;
}
int aggressiveCows(vector<int> &stalls, int k){
    /*
    idea:
    1. we sort stalls
    2. implement binary search on the possible distances from 1 to max-min
    3. at each min we check if its possible to place the cows
    4. if not we make high=mid-1
    5. else low=mid+1
    */
    int n=stalls.size();
    
    sort(stalls.begin(),stalls.end());
    int mindist=stalls[0],maxdis=stalls[n-1];

    //  for(int i=1;i<=maxdis-mindist;i++){             //TC=O(maxdis-mindis)*O(n)=>O(n^2);
    //      if(not(canplacecows(stalls,k,i)))
    //          return i-1;
    //  }
     /*-----------METHOD-II  TC=O(n*log(n)) BINARY SEARCH---------------*/
     int low=1,high=maxdis;

     while (high>=low)
     {
        int mid=low+(high-low)/2;
        if(canplacecows(stalls,k,mid)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
     }
     return high;
}
/*helper function which indicates if we can place cows at distance distancetoplace*/
bool canplacecows(vector<int> &stalls,int cows,int disttoplace){
    int lastdist=stalls[0];
    int n=stalls.size();
    cows--;

    for(int i=1;i<n;i++){
        if(stalls[i]-lastdist>=disttoplace){
            lastdist=stalls[i];
            cows--;
        }
        if(cows==0)
            return true;
    }
    return false;
}
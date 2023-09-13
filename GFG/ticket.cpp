#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int distributeTicket(int N, int K);


int main(){
    cout<<distributeTicket(1,2)<<endl;
    return 0;
}
int distributeTicket(int N, int K){
    //we use 2 ptr here
    int round=1,lastperson;
    int i=1,j=N;

    if(K>=N)
        return N;

    while (i<j)
    {
        if(round%2!=0){
            i+=K;
            if(i<=j)
                lastperson=i;
        }
        else{
            j-=K;
            if(i<=j)
                lastperson=j;
        }   
        round++;
    }
    return lastperson;
    //TC=O(N)
}
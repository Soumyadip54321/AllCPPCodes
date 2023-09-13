#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int oneIteration(vector<int> A);

int main(){
    vector<int> A={-9,-19,-3,-6};
    cout<<oneIteration(A);
    return 0;
}
int oneIteration(vector<int> A){
    /*
    idea:
    1. we find max and second max entries , add and return in O(n)=tc
    */
    vector<int> dupA=A;
    int maxele=INT_MIN,smaxele=INT_MIN,maxidx;
    for(int i=0;i<dupA.size();i++){
            if(dupA[i]>maxele){
                maxele=dupA[i];
                maxidx=i;
            }
    }
        dupA[maxidx]=INT_MIN;
        
        for(int i=0;i<dupA.size();i++){
            if(dupA[i]>smaxele){
                smaxele=dupA[i];
            }
    }
        return maxele+smaxele;
}
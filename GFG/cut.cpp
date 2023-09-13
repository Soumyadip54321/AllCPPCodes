#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int totalCuts(int N,int K,vector<int> &A);
const int N=1e5+10;
int leftmax[N];


int main(){
    vector<int> v={7,1,3,2,0,6,9,1};
    cout<<totalCuts(8,10,v)<<endl;
    return 0;
}
int totalCuts(int N,int K,vector<int> &A){
    int totalcuts=0,right_small=1e5;
    vector<int> indexestocutat;

    for(int i=0;i<N;i++){
        if(A[i]>leftmax[i])
            leftmax[i+1]=A[i];
        else
            leftmax[i+1]=leftmax[i];
    }

    for(int i=0;i<N;i++)
        cout<<leftmax[i]<<" ";
    cout<<endl;

    for(int i=N-1;i>0;i--){
        if(A[i]<right_small)
            right_small=A[i];
        
        if(right_small+leftmax[i]>=K){
            totalcuts++;
            indexestocutat.push_back(i);
        }
    }
    for(auto item:indexestocutat)
        cout<<item<<" ";
    cout<<endl;
    return totalcuts;
}
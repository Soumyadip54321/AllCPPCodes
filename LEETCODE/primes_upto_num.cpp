#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

void primesuptoN(int);


int main(){
    primesuptoN(100);
    return 0;
}
void primesuptoN(int n){
    int *nosupton = new int [n+1],st=2;

    for(int i=2;i<n+1;i++){
        nosupton[i]=i;
        // st++;
    }
    
    /*now we omit all numbers which is the multiple of num*/
    for(int i=2;i<n+1;i++){
        for(int j=i*i;j<=n;j+=i){
            nosupton[j]=-1;
        }
    }
    /*we display the array here*/
    for(int i=2;i<=n;i++){
        if(nosupton[i]!=-1)
            cout<<nosupton[i]<<" ";
    }
    cout<<endl;
    
}
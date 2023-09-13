#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> leastPrimeFactor(int n);

const int n=1e5+10;
bool numbers[n];


int main(){
    vector<int> pf;
    pf=leastPrimeFactor(12);

    for(auto val:pf)
        cout<<val<<",";
    cout<<endl;
    return 0;
}
vector<int> leastPrimeFactor(int n){
    /*
    idea:
    1. We iterate from from 2 to sqrt(N)
    2. include in the list first number that divides it
    */
    int *pf=new int[n+1];
    if(pf==nullptr)
        exit(-1);
    pf[1]=1;
    /*we use sieve of Eratosthenes to make TC=O(NLOG(LOG(N)))*/

    for(int i=2;i<=n;i++){
        numbers[i]=true;
    }
    for(int i=2;i<=n;i++){
        if(numbers[i]){
            pf[i]=i;

            for(int j=i*i;j<=n;j+=i){
                if(numbers[j]){
                    numbers[j]=false;
                    pf[j]=i;
                }
            }
        }
    }
    vector<int> primefactors(pf+1,pf+n+1);
    return primefactors;
}
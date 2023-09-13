#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

long long power(int N,int R);
long long solve(int,int);
const int M=1e9+7;

int main(){
    cout<<power(12,21);
    return 0;
}
long long power(int N,int R){
    /*
    idea:
    1. pow(x,n)=x^(n/2)*x^(n/2) if n=even
               =x*x^(n/2)*x^(n/2) if n=odd
    */
    return solve(N,R)%M;
}
long long solve(int N,int R){
    if(R==0)
        return 1;
    if(R==1)
        return N;

    long long temp=solve(N,R/2)%M;
    if(R%2==0){
        return (temp*temp)%M;
    }
    else{
        return ((temp*temp)%M*N)%M;
    }
}
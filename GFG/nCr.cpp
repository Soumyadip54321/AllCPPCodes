#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int M=1e9+7;
int nCr(int n, int r);

int main(){
    cout<<nCr(69,43)<<endl;
    return 0;
}
int nCr(int n, int r){                  //nCr=(n*(n-1)*(n-2)*....*(n-r+1)/r!)
    if(r>n)
        return 0;
    
    if(r==n)
        return 1;
    long long product=1,denom_fact=1,denom_fact_2=1;
    int temp=n;

    // if(n-(n-r)>n-r)
    //     r=n-r;
    while (n)
    {
        product=(product*n)%M;
        n--;
    }
    cout<<product<<endl;
    n=temp;

    for(int i=n-r;i>=1;i--)
        denom_fact_2=(denom_fact_2*i)%M;
    
    cout<<denom_fact_2<<endl;

    while (r)
    {
        denom_fact=(long long)(denom_fact*r)%M;
        r--;
    }
    cout<<denom_fact<<endl;

    return (product/((denom_fact*denom_fact_2)%M))%M;
}
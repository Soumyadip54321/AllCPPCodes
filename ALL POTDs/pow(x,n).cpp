#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
double myPow(double x, int n);

int main(){
    cout<<myPow(2,-2);
    return 0;
}
double myPow(double x, int n){
    if(n==0)
        return 1.0;
    if(n==1)
        return x;
    
    double ans;
    if(n>=0)
        ans=myPow(x,n/2);
    else
        ans=myPow(1.0/x,abs(n/2));
    if(n%2==0)
        return ans*ans;
    
    if(n>=0)
        return x*ans*ans;
    return (ans*ans)/x;
}

// TC=O(log(n)),SC=O(log(n))
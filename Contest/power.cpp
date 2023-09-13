#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

double myPow(double x, int n);
double calpow(double,int);
int main(){
    double x=0.00001;
    cout<<myPow(x,2147483647)<<endl;
    return 0;
}
double myPow(double x, int n){
    int countdec=0;
    if(x<1){
        /*here we check for number of decimal places*/
        while (x<1)
        {
            x*=10;
            countdec++;
        }
        if(n>0)
            return calpow(x,n)/calpow(10,n*countdec);
    }
    if(n<0)
        return 1/calpow(x,-1*n);
    return calpow(x,n);
}
double calpow(double x, int n){
    if(n==1)
        return x;
    return x*myPow(x,n-1);
}
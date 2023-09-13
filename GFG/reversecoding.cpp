#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int sumOfNaturals(int n);
const int M=1e9+7;


int main(){
    cout<<sumOfNaturals(63032);
    return 0;
}
int sumOfNaturals(int n){
    long long totalsum=1;

    totalsum=(totalsum*n);
    totalsum=(long long)(totalsum*(n+1))/2;
    return totalsum%M;

    /*
    here since integer range lies between 1e-9 to 1e9 with M=1e9+7 the answer returned lies roughly within integer range
    */
}
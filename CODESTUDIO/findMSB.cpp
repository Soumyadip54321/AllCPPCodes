#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int findMSB(int n);

int main(){
    cout<<findMSB(1);
    return 0;
}
int findMSB(int n){
    int result=0;

    //first we count the set bits
    //if found to be 1 it itself is a power of 2 and we return
    if((n & (n-1))==0)
        return n;
    
    string numstr="";
    while (n)
    {
        numstr+=(n & 1)+'0';
        n=n>>1;
    }
    return (1<<(numstr.length()-1));
}
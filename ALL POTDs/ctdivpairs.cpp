#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int countOfDivisiblePairs(int n, int m);

int main(){
    cout<<countOfDivisiblePairs(55,52);
    return 0;
}
int countOfDivisiblePairs(int n, int m){
    //n ranges from [1,n],m from [1,m]
    int ctpairs=0;

    //largest multiple of 5 that's possible is ((n+m)/5)*5
    m=max(n,m);
    n=min(n,m);
    
    if(n+m<5)
        return ctpairs;
    
    int largest5mult=(n+m)-((n+m)%5);

    for(int i=m;i>=1;i--){
        if(i>=largest5mult-5){
            if(largest5mult-i<=n and largest5mult-i>=1)
                ctpairs++;
        }
        else{
            if(largest5mult-i<=n and largest5mult-i>=1)
                ctpairs++;
            
            largest5mult-=5;

            if(largest5mult-i<=n and largest5mult-i>=1){
                ctpairs++;
            }
        }
    }
    return ctpairs;
}
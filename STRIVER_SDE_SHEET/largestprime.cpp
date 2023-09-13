#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
long long int largestPrimeFactor(int N);

int main(){
    cout<<largestPrimeFactor(41);
    return 0;
}
long long int largestPrimeFactor(int N){
    //LONG VERSION
    long long  maxprimefact=-1;
    // //we first try and divide by 2
    //  while ((N%2)==0)
    //  {
    //      maxprimefact=2;
    //      N/=2;
    //  }
    //  //next we try and divide with 3
    //  while ((N%3)==0)
    //  {
    //      maxprimefact=3;
    //      N/=3;
    //  }
    //  //next we try starting at 5,7,  ,11,13,....
    //  for(int i=5;i<=sqrt(N);i+=6){
    //      while ((N%i)==0)
    //      {
    //          maxprimefact=i;
    //          N/=i;
    //      }
    //      while ((N%(i+2))==0)
    //      {
    //          maxprimefact=i+2;
    //          N/=(i+2);
    //      }
    //  }
    //  //for primes greater than 4
    //  if(N>4)
    //      maxprimefact=N;
    //  return maxprimefact;
    //TC=O(sqrt(n));


    //SMALL VERSION
    int i=2;
    int numfactors=sqrt(N);
    while (i<=numfactors)
    {
        while ((N%i)==0)
        {
            maxprimefact=i;
            N/=i;
        }
        i++;
    }
    if(N>1)
        maxprimefact=N;
    return maxprimefact;
}   
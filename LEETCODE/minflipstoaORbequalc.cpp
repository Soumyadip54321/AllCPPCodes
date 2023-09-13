#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int minFlips(int a, int b, int c);
const int n=1e5+10;

int bh1[n],bh2[n];


int main(){
    cout<<minFlips(8,3,5)<<endl;
    return 0;
}
int minFlips(int a, int b, int c){
    /*NAIVE APPROACH:
    1. We find the binary equivalent of a,b,and c
    2. Iterate through the digits of a and b to check see if there exists atleast one 1 for 1 in c
    3. or all 0s for 0 in c
    */
   int minflips=0;
   for(int i=31;i>=0;i--){
        if((a & (1<<i))!=0){
            bh1[i]=1;
        }
        if((b & (1<<i))!=0)
            bh2[i]=1;
   }

//    for(int i=31;i>=0;i--)
//       cout<<bh1[i]<<" ";
//     cout<<endl;

    for(int i=31;i>=0;i--){
        if((c & (1<<i))!=0){
            if(bh1[i]==0 && bh2[i]==0)
                minflips+=1;            /*one unset bit set to make 1*/
        }
        else{
            if(bh1[i]==1 && bh2[i]==1)
                minflips+=2;            /*both set bits unset to make 0*/
            else if(bh1[i]==1 || bh2[i]==1)
                minflips++;
        }
    }
   return minflips;

   /*TC=O(n)
   where n=> largest number of bits present*/
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
using namespace std;

int countFractions(int n, int numerator[], int denominator[]);
int gcd(int,int);

int main(){
    int numerator[]={2,2,1,2,2,3,3,2,1},denominator[]={3,2,3,3,5,4,3,2,4};
    cout<<countFractions(9,numerator,denominator);
    return 0;
}
int countFractions(int n, int numerator[], int denominator[]){
    //BETTER APPROACH
    /*
    idea:
    1.  create a map of pairs<int,int> s.t each represents a fraction (p/q) and get their corresponsing counts
    2.  ensure you divide both numerator and denomination by gcd(numerator,denominator) to reduce each to its smallest fraction
    3.  loop through the array to find out if there exists fraction ((q-p)/q) for each in the map and put the corresponsind count in ans
    4.  put the fraction (q-p)/q in map and increase its count
    */

    map<pair<int,int>,int> mpp;         //map considered due to high change of collision with fractional parts;
    int ct=0;

    for(int i=0;i<n;i++){
        int gcd_num_deno=gcd(max(numerator[i],denominator[i]),min(numerator[i],denominator[i]));        //TC=O(lg(min(n1,n2)));
        int red_num=numerator[i]/gcd_num_deno;
        int red_deno=denominator[i]/gcd_num_deno;

        ct+=mpp[{red_deno-red_num,red_deno}];       //TC=O(lg(n));

        mpp[{red_num,red_deno}]++;
    }
    return ct;
    //TC=O(nlg(n)),SC=O(n);
}
int gcd(int num1,int num2){

    if(num1%num2==0)
        return num2;
    
    return gcd(num2,num1%num2);
}
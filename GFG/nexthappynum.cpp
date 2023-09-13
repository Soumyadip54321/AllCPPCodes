#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int nextHappy(int N);
int squareandsumdigits(int);


int main(){
    cout<<nextHappy(45);
    return 0;
}
int nextHappy(int N){
    /*
    idea:
    1. we sum squares of digits and insert into a set
    2. if at any stage we obtain 1 we return the number squaring which we obtained 1
    3. else there will be a time when a number already in the set is visited in which case we move onto the next higher number
    emptying the set out
    */
   set<int> s;
   int nextnum=N+1,prev=nextnum;

   while (squareandsumdigits(nextnum)!=1)
   {
        if(s.find(squareandsumdigits(nextnum))!=s.end()){
            s.clear();
            nextnum=prev+1;
            prev=nextnum;
        }
        else{
            s.insert(squareandsumdigits(nextnum));
            nextnum=squareandsumdigits(nextnum);
        }
   }
   return prev;

   //TC=O(NLOG10(N)), Auxilliary Space =O(n);
}
int squareandsumdigits(int num){
    string numstr=to_string(num);
    int sumofdigitsquare=0;

    for(int i=0;i<numstr.length();i++)
        sumofdigitsquare+=(numstr[i]-'0')*(numstr[i]-'0');
    return sumofdigitsquare;
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int minNumToWin(int n, int mishaNums);

int main(){
    cout<<minNumToWin(7,4);
    return 0;
}
int minNumToWin(int n, int mishaNums){
    /*
    idea:
    1. whatever misha chooses all num<= misha num if it falls will result in MIsha win
    2. what we chose out of remaining must be such that the prob>=prob(misha win) i.e. we must not leave any number starting from
    idx+1 where idx=> number chosen by misha
    */

   //figure out nos to left and right of Misha
    int mid=(1+n)/2;
        if(mishaNums==mid){
            if(mishaNums-1>=1 && n%2!=0)
            	return mishaNums-1;
			return mishaNums+1;
        }
        else{
            if(mishaNums<mid){
                return mishaNums+1;
            }
            else
                return mishaNums-1;
        }
}
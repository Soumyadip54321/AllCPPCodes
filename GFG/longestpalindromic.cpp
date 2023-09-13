#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
string longestPalin (string S);
bool ispalindromic(string,int,int);


int main(){
    string str="vnrtysfrzrmzlygfv";
    cout<<longestPalin(str)<<endl;
    //cout<<ispalindromic(str,0,4)<<endl;
    return 0;
}
string longestPalin (string S){
    /*
    idea:
    1. employ 2 ptr method to search for substrings longest to shortest
    2. first time we find a palindromic substric we return
    */
   int maxlenpalin=-1;
   string palindstr;

   for(int i=0;i<S.length();i++){
        for(int j=S.length()-1;j>=i;j--){
            string s=S.substr(i,j-i+1);
            //cout<<s<<endl;

            if(ispalindromic(s,0,j-i+1) && maxlenpalin<(j-i+1)){
                palindstr=s;
                maxlenpalin=j-i+1;
                //cout<<palindstr<<endl;
            }        
        }
   }
   return palindstr;
}
bool ispalindromic(string str,int idx,int n){
    // if(idx>=n/2)
    //     return true;
        
    // if(str[idx]!=str[n-idx-1])
    //     return false;
    
    // return ispalindromic(str,idx+1,n);
    int mid=n/2;
    if(n%2==0)
        mid-=1;


    for(int i=idx;i<=mid;i++){
        if(str[i]!=str[n-i-1])
            return false;
    }
    return true;
}
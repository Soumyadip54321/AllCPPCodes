#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int setSetBit(int x, int y, int l, int r);

int main(){
    cout<<setSetBit(43,18469,11,27)<<endl;
    return 0;
}
int setSetBit(int x, int y, int l, int r){
    string s1="",s2="";

    while (x)           //TC=O(LOG(X))
    {
        s1+=(x & 1)+'0';
        x=x>>1;
    }

    while (y)           //TC=O(LOG(Y))
    {
        s2+=(y & 1)+'0';
        y=y>>1;
    }

    //now we find indexes between l and r where set bits exists

    //we check if x < y in which case we make length same
    if(s1.length()<s2.length()){    
        for(int i=s1.length();i<s2.length();i++)
            s1+='0';
    }

    int st=l-1,end=r;
    if(r>s2.length())
        end=s2.length();

    while (st<end)          //TC=O(R-L)
    {
        if(s2[st]=='1'){
            s1=s1.substr(0,st)+s2[st]+s1.substr(st+1);
        }
        st++;
    }
    reverse(s1.begin(),s1.end());           /*we reverse number to set it right as the number in actual looks like*/
    //cout<<s1<<endl;

    int num=0;

    for(int i=0;i<s1.length();i++){
        num+=(s1[s1.length()-i-1]-'0')*(1<<i);
    }
    return num;
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
typedef long long LL;
using namespace std;

long long minnumber(long long);

int main(){
    LL num;
    cin>>num;
    cout<<minnumber(num);
    return 0;
}
long long minnumber(long long num){
    string numstr=to_string(num),res;
    LL len=numstr.length();
    LL ans; 
    /*
    idea:
    1. digits >=5 when inverted gives digits from [0,....,4]
    */
   //here we look for digits >=5 and invert them
    for(LL i=0;i<len;i++){

        if(numstr[i]-'0'>=5){
            if(numstr[i]-'0'==9 and i==0)
                res+=numstr[i];
            else
                res+=(9-(numstr[i]-'0'))+'0';
        }
        else
            res+=numstr[i];
    }
    //cout<<res<<endl;
    ans=stoll(res);
    return ans;
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
bool isGoodNumber(int n);

int main(){
    cout<<isGoodNumber(1045);
    return 0;
}
bool isGoodNumber(int n){
    int res=0,num=n;
    unordered_map<int,int> m;

    m[n]++;

    while (true)
    {
        string numstr=to_string(num);
        for(int i=0;i<numstr.length();i++)
            res+=(numstr[i]-'0')*(numstr[i]-'0');
        
        if(res==1)
            return true;
        else if(m[res])
            break;

        m[res]++;
        num=res;
        res=0;
    }
    return false;
}
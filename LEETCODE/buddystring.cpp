#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
bool buddyStrings(string s, string goal);

int main(){
    string s="abcd",s1="badc";
    cout<<buddyStrings(s,s1);
    return 0;
}
bool buddyStrings(string s, string goal){
    if(s.length()!=goal.length())
        return false;

    bool allsame=true,respsame=true;

    for(int i=0;i<s.length();i++){
        if(s[i]!=goal[0]){
            allsame=false;
            break;
        }
    }

    if(allsame)
        return true;
    

    for(int i=0;i<s.length();i++){
        if(s[i]!=goal[i]){
            respsame=false;
            break;
        }
    }
    if(respsame)
        return false;
    
    int first=0,mismatch=0,nummismatch=0;
    char mismatchs,mismatchg;

    for(int i=0;i<s.length();i++){
        if(s[i]!=goal[i])
            nummismatch++;
    }

    if(nummismatch!=2)
        return false;

    while (first<s.length())
    {
        if(s[first]!=goal[first]){
            mismatch++;
            if(mismatch==nummismatch){
                if(mismatchs==goal[first] && mismatchg==s[first])
                    return true;
                else
                    break;
            }
            mismatchs=s[first];
            mismatchg=goal[first];
        }
        first++;
    }
    
    return false;
}
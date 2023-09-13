#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int isValid(string s);

int main(){
    string s="a.1.245.29";
    cout<<isValid(s);
    return 0;
}
int isValid(string s){
    /*
    idea:
    1. first we count number of parts present, if not 4 we return false
    2. then inside a loop evrytime we come across the '.' we count number of digits
        (i) if count of digits does not belong to [1,3] we return false
        (ii) also we check if any number with 2 or more digits have leading zeros, in which case we return false
        (iii) next we check number obtained if its not b/w [0,255] we return false
    3.  we also check if it is a number we check everytime we encounter a '.' i.e. if at any instant we find we have anything but a digit
        we return false;
    */
    int n=s.length(),ctdots=0;
    string parts;

    //check for 4 parts
    for(int i=0;i<n;i++){
        if(s[i]=='.')
            ctdots++;
    }
    if(not(ctdots==3))
        return 0;

    for(int i=0;i<=n;i++){
        if(s[i]=='.' or i==n){
            if(not(parts.length()>0 and parts.length()<4))
                return 0;
            
            if(parts.length()>1 and parts[0]-'0'==0)
                return 0;
            int num=stoi(parts);

            if(not(num>=0 and num<=255))
                return 0;
            parts="";
        }
        else{
            if(isdigit(s[i]))
                parts+=s[i];
            else
                return 0;
        }
    }
    return 1;
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
bool isValidIPv4(string ipAddress);

int main(){
    string ipAddress="n.8.f0.";
    cout<<isValidIPv4(ipAddress);
    return 0;
}
bool isValidIPv4(string ipAddress){
    //check for presence of 4 parts i.e. 3 '.'
    int ctparts=0,n=ipAddress.length(),j=0;
    string parts="";

    for(int i=0;i<n;i++){
        if(ipAddress[i]=='.')
            ctparts++;
    }
    if(ctparts!=3)
        return false;
    //check if address starts with '.' in which case its invalid
    if(ipAddress[0]=='.')
        return false;
    
    //we check whether each part is a number
    for(int i=0;i<=n;i++){
        if(ipAddress[i]=='.' || i==n){
            int num=stoi(parts);

            if(not(num>=0 && num<=255))
                return false;
            parts="";
        }
        else{
            if(isdigit(ipAddress[i]))
                parts+=ipAddress[i];
            else
                return false;
        }
    }
    return true;
}
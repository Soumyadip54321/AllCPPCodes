#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
string nextSmallerPalindrome(string &s);

int main(){
    string s="101";
    cout<<nextSmallerPalindrome(s);
    return 0;
}
string nextSmallerPalindrome(string &s){
    if(s=="1")
        return "0";

    string nextpalin=s;
    int mid=s.length()/2;

    for(int i=mid;i<nextpalin.length();i++){
        if(nextpalin[i]-'0'!=0){
            nextpalin[i]=nextpalin[nextpalin.length()-1-i]=((nextpalin[i]-'0')-1)+'0';
            break;
        }
        else{
            nextpalin[i]=nextpalin[nextpalin.length()-1-i]='9';
        }
    }

    //now for cases such as s=10001/11 it gets changed to 09990/00 we need to change to 9999/9 resp
    if(nextpalin[0]=='0'){
        nextpalin='9'+nextpalin.substr(1,nextpalin.length()-2);
    }
    return nextpalin;
}
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

string removeDigit(string number, char digit);
string maxnumber(string,char,int);


int main(){
    string number="5514337899214532337655419099456774235166905543222105534768892";
    cout<<removeDigit(number,'5');
    return 0;
}
string removeDigit(string number, char digit){
    string maxnum="";
    for(int i=0;i<number.length();i++){
        string s=maxnumber(number,digit,i);

        if(s!="")
            maxnum=max(maxnum,s);
    }
    return maxnum;
}
string maxnumber(string number,char digit,int idx){
    if(idx==number.length())
        return "";
    if(number[idx]==digit)
        return number.substr(0,idx)+number.substr(idx+1);
    
    return maxnumber(number,digit,idx+1);
}
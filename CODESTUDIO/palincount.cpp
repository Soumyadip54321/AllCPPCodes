#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int palinCount(string str);
void formsubstrings(string,string);
bool checkpalin(string,int);

vector<string> substrings;


int main(){
    string str="aab";
    cout<<palinCount(str)<<endl;
    return 0;
}
int palinCount(string str){
    /*1. first we form the substrings
      2. next we loop through substrings to find palindromes
    */
   int numofpalindromes=0;
   formsubstrings(str,"");

    for(auto substr:substrings)
        cout<<substr<<",";
    cout<<endl;

    for(auto substr:substrings){
        if(checkpalin(substr,0) && substr!="")
            numofpalindromes++;
    }
    //cout<<numofpalindromes<<endl;
    return numofpalindromes;

}
void formsubstrings(string str,string s){
    if(str.length()==0){
        substrings.push_back(s);
        return;
    }
    char ch=str[0];
    string ros=str.substr(1);

    formsubstrings(ros,s+ch);
    formsubstrings(ros,s);
}
bool checkpalin(string str,int idx){
    if(idx>=str.length()/2)
        return true;

    if(str[idx]!=str[str.length()-idx-1])
        return false;
    
    return checkpalin(str,idx+1);
}
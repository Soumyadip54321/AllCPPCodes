#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
bool checkMeta(string &str1, string &str2);

int main(){
    string str1="Seek",str2="Seke";
    cout<<checkMeta(str1,str2);
    return 0;
}
bool checkMeta(string &str1, string &str2){
    if(str1==str2 || str1.length()!=str2.length())
        return false;
    
    //if there exists only one out of position then its a meta string for swapping 
    //such letters gives you the original string back
    int n=str1.length(),idx1,idx2;
    

    for(int i=0;i<n;i++){
        if(str1[i]!=str2[i]){
            idx1=i;
            break;
        }
    }
    for(int i=n-1;i>=idx1;i--){
        if(str1[i]!=str2[i]){
            idx2=i;
            break;
        }
    }
    string modstr2="";
    for(int i=0;i<idx1;i++){
        modstr2+=str2[i];
    }
    modstr2+=str2[idx2];

    for(int i=idx1+1;i<n;i++){
        if(str1[i]==str2[idx1])
            modstr2+=str2[idx1];
        else
            modstr2+=str2[i];
    }
    //cout<<modstr2<<endl;
    if(modstr2==str1)
        return true;
    return false;
}
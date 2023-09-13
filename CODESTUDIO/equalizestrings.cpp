#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
string equaliseTwoStrings(int n, string &p, string &q);

const int n=1e5+10;
bool letterequal[n];


int main(){
    string str="zzhzsd",str1="axdcwd";
    cout<<equaliseTwoStrings(6,str,str1)<<endl;
    return 0;
}
string equaliseTwoStrings(int n, string &p, string &q){
    if(p.length()!=q.length())
        return "No";
    
    for(int i=0;i<p.length();i++){
        if(p[i]==q[i])
            letterequal[i]=true;
    }

    for(int i=0;i<p.length();i++){
        if(letterequal[i]==false){
            if(letterequal[i-1] || letterequal[i+1]){
                p[i]=q[i];
                letterequal[i]=true;
            }
        }
    }

    if(p==q)
        return "Yes";
    return "No";
}
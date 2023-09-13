#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
char nonrepeatingCharacter(string S);

int main(){
    string str="yy";
    cout<<nonrepeatingCharacter(str);
    return 0;
}
char nonrepeatingCharacter(string S){
    unordered_map<char,int> chfreq;
    int n=S.length(),repidx=-1;

    for(int i=0;i<n;i++){
        chfreq[S[i]]++;
    }

    for(int i=0;i<n;i++){
        if(chfreq[S[i]]==1){
            repidx=i;
            break;
        }
    }
    if(repidx==-1)
        return '$';
    return S[repidx];
}



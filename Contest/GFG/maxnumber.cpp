#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int maximumNumber(int N);

int main(){
    cout<<maximumNumber(9999);
    return 0;
}
int maximumNumber(int N){
    /*
    idea:
    1. we start at MSB then move to end
    2. the first time we encounter a '7' we change it to '9' and return
    */
   string numstr=to_string(N),numans;
   int idx=-1;

   for(int i=0;i<numstr.length();i++){
        if(numstr[i]-'0'==7){
            idx=i;
            break;
        }
        else
            numans+=numstr[i];
   }

    if(idx!=-1){
        numans+='9';
        for(int i=idx+1;i<numstr.length();i++)
            numans+=numstr[i];
    }
   //cout<<numans<<endl;
   return stoi(numans);
}
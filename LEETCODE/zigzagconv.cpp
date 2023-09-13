#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

string convert(string s, int numRows);
void updatemtx(string,int,int,int);

const int n=1010;
char strmtx[n][n];


int main(){
    string str="A";
    cout<<convert(str,1);
    return 0;
}
string convert(string s,int numRows){
    int ci=0,rh=0,rl=numRows-1;
    string ans;
    while (true)
    {
        // cout<<endl;
        while(rh<=rl && s.length()){
            strmtx[rh][ci]=s[0];
            //cout<<strmtx[rh][ci]<<endl;
            s.erase(s.begin()+0);
            rh++;
        }
        if(not(s.length()))
            break;

        rh=0;
        rl--;
        ci++;

        // cout<<endl;
        while (rl>rh && s.length())
        {
            char ch=s[0];
            strmtx[rl][ci]=ch;
            //cout<<strmtx[rl][ci];
            s.erase(s.begin()+0);
            ci++;
            rl--;
        }
        if(not(s.length()))
            break;

        rl=numRows-1;
    }

    for(int i=0;i<numRows;i++){
        for(int j=0;j<n;j++){
            if(strmtx[i][j]>0)
                ans+=strmtx[i][j];
        }
    }
    //cout<<ans<<endl;
    return ans;
}

